#include "sql-cmd.h"

void addCmd(std::unique_ptr<TableSchema> schema){
	std::string stmt = schema->addStmt();
	execute(stmt.c_str(), NULL, 0);
}

void viewCmd(std::unique_ptr<TableSchema> schema){
	std::cout << "view cmd\n";
}

void updateCmd(std::unique_ptr<TableSchema> schema){
	std::cout << "update cmd\n";
}

void removeCmd(std::unique_ptr<TableSchema> schema){
	std::cout << "remove cmd\n";
}

void checkCmd(std::unique_ptr<TableSchema> schema){
	std::cout << "check cmd\n";
}

void uncheckCmd(std::unique_ptr<TableSchema> schema){
	std::cout << "uncheck cmd\n";
}

void installCmd(){
	fs::path dbPath = get_db_path();
	if(!fs::exists(dbPath)){
		create_db(dbPath);		
	}
	create_db_tables(dbPath);	
}

