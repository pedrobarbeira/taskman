#include "schemas.h"

std::string TaskSchema::addStmt(){
	return "someting";
}

std::string ProjectSchema::addStmt(){
	std::stringstream ss;	
	ss << "insert into projects(name, course) values('"
		<< this->name << "', '" << this->course
		<< "');";
	return ss.str();
}
