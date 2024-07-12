#ifndef btest_h
#define btest_h

#include <vector>
#include <iostream>
#include <sstream>

namespace btest {

    enum LogLevel {
        SETUP, TEST, METHOD, CONSTRUCTOR
    };

    class Logger {
    public:
        virtual void log(const std::string &log, LogLevel level) const = 0;
    };

    class TestLogger : public Logger {
    private:
        std::ostream &out;

        void logSetup(const std::string &log) const {
            this->out << "SETUP      ::" << log << '\n';
        }

        void logTest(const std::string &log) const {
            this->out << "--TEST     ::" << log << '\n';
        }

        void logMethod(const std::string &log) const {
            this->out << "----METHOD ::" << log << '\n';
        }

        void logConstructor(const std::string &log) const {
            this->out << "------CSTR ::" << log << '\n';
        }

    public:
        explicit TestLogger(std::ostream &out) :
                out(out) {};

        void log(const std::string &log, LogLevel level) const override {
            this->log(log, " ", level);
        }

        void log(const std::string &log, const std::string &prefix, LogLevel level) const {
            std::string outStr = prefix + log;
            switch (level) {
                case SETUP :
                    return logSetup(outStr);
                case TEST :
                    return logTest(outStr);
                case METHOD :
                    return logMethod(outStr);
                case CONSTRUCTOR:
                    return logConstructor(outStr);
                default:
                    return;
            }
        }
    };


    class mock {
    };

    typedef bool (*mock_func)(TestLogger *logger);

    class bockTest {
    private:
        TestLogger logger;
        std::vector<mock_func> tests;
    public:
        bockTest(std::vector<mock_func> tests, TestLogger logger) :
                logger(std::move(logger)), tests(std::move(tests)) {};

        void runBockTests() {
            logger.log("::::STARTING TESTS::::::::", "::", SETUP);
            if (tests.empty()) {
                std::cout << "No tests no run\n";
                return;
            }
            for (unsigned long i = 0; i < tests.size(); i++) {
                bool result = tests[i](&logger);
                std::stringstream ss;
                ss << "[" << (result ? "X" : " ") << "] Test " << i << "-" << (result ? "Passed" : "Failed");
                logger.log(ss.str(), SETUP);
            }
        }

        [[nodiscard]] const TestLogger& getLogger() const{
            return this->logger;
        }
    };

    void runTests(std::vector<mock_func> tests) {
        auto logger = TestLogger(std::cout);

        bockTest Bock = bockTest(std::move(tests), logger);

        Bock.runBockTests();
    }
}


#endif //btest_h
