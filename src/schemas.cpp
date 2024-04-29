#include "schemas.h"
#include <iostream>

std::string TableSchema::deleteStmt(){
	std::stringstream ss;
	ss << "delete from " << tableName <<
		" where id = " << instanceId << ";";
	return ss.str();
}

std::string TaskSchema::addStmt(){
	return "someting";
}

std::string TaskSchema::selectStmt() {
	return "something";
}

std::string TaskSchema::updateStmt() {
	return "something";
}

std::string ProjectSchema::addStmt(){
	std::stringstream ss;	
	ss << "insert into projects(name, course) values('"
		<< this->name << "', '" << this->course
		<< "');";
	return ss.str();
}

std::string ProjectSchema::selectStmt() {
	return "something";
}

std::string ProjectSchema::updateStmt() {
	return "something";
}


