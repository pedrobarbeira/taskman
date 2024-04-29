#include "data-access.h"

namespace fs = std::filesystem;

fs::path get_db_path(){
	return std::filesystem::path(std::filesystem::current_path()) / DB_NAME;
}

sqlite3* open_connection(){
	sqlite3* db;
	fs::path dbPath = get_db_path();
	sqlite3_open(dbPath.string().c_str(), &db);
	return db;
}

void execute(std::string stmt, sqlite3_callback callback, void* data){
	sqlite3* db = open_connection();
	char* errMsg;
	int rc = sqlite3_exec(db, stmt.c_str(), callback, data, &errMsg);	
	if(rc != SQLITE_OK){
		std::cout << "Error executing query - code " << rc << "\n\t" << stmt << '\n' 
						<< errMsg << std::endl;
	}else{
		std::cout << "Success with code " << rc << std::endl;
	}
	sqlite3_close(db);	
}

void create_db(fs::path dbPath){
	std::ofstream dbFile(dbPath);
	if(dbFile.is_open()){
		std::cout << "Db file successfully created\n";
	}
	else{
		std::cout << "Error creating db file\n";
	}
}

bool table_exists(sqlite3* db, std::string tableName){
	sqlite3_stmt* stmt;
	
	std::stringstream ss;

	ss << "SELECT name FROM sqlite_master WHERE type='table' AND name='"
		<< tableName << "';";

	int rc = sqlite3_prepare_v2(db,ss.str().c_str(), -1 , &stmt, nullptr);
	if(rc != SQLITE_OK){
		std::cerr << "Failed to prepare statement: "
						<< sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
		return false;
	}

	rc = sqlite3_step(stmt);
	sqlite3_finalize(stmt);	

	return rc == SQLITE_ROW;
}

void create_db_table(sqlite3* db, std::string tableName, std::string createStmt){
	if(!table_exists(db, tableName)){
		char* errorMsg;
		int rc = sqlite3_exec(db, createStmt.c_str(), NULL, 0, &errorMsg);

		if(rc != SQLITE_OK){
			std::cout << "Error creating table [" << tableName << "]\n" 
				<< errorMsg << std::endl;
			sqlite3_free(errorMsg);
		}else{
			std::cout << "Table [" << tableName << "] successfuly created!\n";
		}
	}
}


void create_db_tables(fs::path dbPath){
	sqlite3* db;

	int rc = sqlite3_open(dbPath.string().c_str(), &db);
	if(rc){
		std::cerr << "Can't open database: "
						<< sqlite3_errmsg(db) << std::endl;
	}

	create_db_table(db, "projects", sql_create::projects);	
	create_db_table(db, "tasks", sql_create::tasks);

	sqlite3_close(db);
}

