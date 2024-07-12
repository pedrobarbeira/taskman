#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class ParseException : public std::exception{
	private:
		std::string errMsg;
	public:
		explicit ParseException(std::string  errMsg):
			errMsg(std::move(errMsg)){};

		[[nodiscard]] const char* what() const noexcept override{
			return errMsg.c_str();
		}
};

#endif //EXCEPTION_H
