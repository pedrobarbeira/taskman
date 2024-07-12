#ifndef DATA_ACCESS_H
#define DATA_ACCESS_H

#include <filesystem>
#include <sqlite3.h>
#include <iostream>
#include <fstream>

#define DB_NAME "db.sql"

namespace fs = std::filesystem;
namespace sql_create{
	const std::string tasks = "CREATE TABLE TASKS("
													"ID INTEGER PRIMARY KEY AUTOINCREMENT,"	
													"PROJECT INTEGER NOT NULL,"
													"NAME VARCHAR(50) NOT NULL,"
													"DESCRIPTION VARCHAR(512),"
													"DUE_BY INTEGER,"
													"CONSTRAINT FK_PROJECTS FOREIGN KEY (PROJECT) REFERENCES PROJECTS(ID));";

	const std::string projects = "CREATE TABLE PROJECTS("
															"ID INTEGER PRIMARY KEY AUTOINCREMENT,"
															"NAME VARCHAR(50),"
															"COURSE CHAR(4));";
}

void db_install();

fs::path get_db_path();

sqlite3* open_connection();

void execute(const std::string& stmt, sqlite3_callback callback, void* data);

void create_db(const fs::path& dbPath);

bool table_exists(sqlite3* db, const std::string& tableName);

void create_db_table(sqlite3* db, const std::string& tableName, const std::string& createStmt);

void create_db_tables(const fs::path&  dbPath);

#endif //DATA_ACCESS_H
