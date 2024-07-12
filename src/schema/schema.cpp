#include <utility>

#include "include/schema/schema.h"

void Schema::buildStmtTable() {
    stmtTable[ADD] = [this] { return addStmt(); };
    stmtTable[SELECT] = [this] { return selectStmt(); };
    stmtTable[UPDATE] = [this] { return updateStmt(); };
    stmtTable[REMOVE] = [this] { return deleteStmt(); };
}

std::string getParamValue(std::string param){
    for(unsigned long i = 0 ; i < param.size(); i++){
        if(param[i] == ':'){
            return param.substr(i+1);
        }
    }
    return "";
}

stmtData_t Schema::buildStmtData(std::string stmt, sqlite3_callback callback, void* data){
    return stmtData_t{ std::move(stmt), callback, data};
}
