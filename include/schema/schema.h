#ifndef SCHEMAS_H
#define SCHEMAS_H


#include <functional>
#include "../data-access.h"
#include "include/repository.h"

#define NO_ID -1

#define ADD "add"
#define REMOVE "rm"
#define UPDATE "update"
#define SELECT "select"

typedef struct{
    std::string stmt;
    sqlite3_callback callback;
    void* data;
}stmtData_t;

typedef std::function<stmtData_t(void)> schemaStmt;

class Schema{
private:
    void buildStmtTable();

    virtual stmtData_t addStmt() = 0;

    virtual stmtData_t selectStmt() = 0;
    virtual stmtData_t updateStmt() = 0;
    virtual	stmtData_t deleteStmt() = 0;
protected:
    std::unordered_map<std::string, schemaStmt> stmtTable;

    static stmtData_t buildStmtData(std::string stmt, sqlite3_callback callback, void* data);
public:
    explicit Schema(){
        this->buildStmtTable();
    }

    virtual ~Schema()= default;

    virtual stmtData_t getStmt(const std::string& cmd){
        if(stmtTable.find(cmd) != stmtTable.end()){
            return stmtTable[cmd]();
        }
        return buildStmtData("", nullptr, nullptr);
    };

    virtual int getId() const = 0;
    virtual std::string getTable() const = 0;
};

std::string getParamValue(std::string param);

#endif //SCHEMAS_H
