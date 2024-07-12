//
// Created by pbarbeira on 27-06-2024.
//

#ifndef TASKMAN_TEST_H
#define TASKMAN_TEST_H

#include "../btest.h"
#include "../schema-builder.h"

bool test_schema_builder(btest::TestLogger* logger){
    std::string id = "id:01";
    std::string name = "name:John";
    std::string course = "course:Doe";

    std::unique_ptr<Schema> resultSchema = SchemaBuilder::build({id, name, course});
    std::cout << resultSchema->getId() << std::endl;
    return true;
}

int run_tests(){
    std::vector<btest::mock_func> tests = {
            test_schema_builder
    };
    btest::runTests(tests);

    return 0;
}

#endif //TASKMAN_TEST_H
