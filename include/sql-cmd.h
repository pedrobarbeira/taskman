#ifndef _SQL_CMD_H
#define _SQL_CMD_H

#include <vector>
#include "data-access.h"
#include "schema-builder.h"

void addCmd(std::unique_ptr<TableSchema> schema);

void viewCmd(std::unique_ptr<TableSchema> schema);

void updateCmd(std::unique_ptr<TableSchema> schema);

void removeCmd(std::unique_ptr<TableSchema> schema);

void checkCmd(std::unique_ptr<TableSchema> schema);

void uncheckCmd(std::unique_ptr<TableSchema> schema);

void installCmd();

#endif //_SQL_CMD_H_
