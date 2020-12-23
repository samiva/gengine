#ifndef __LOGGERAPI_h__
#define __LOGGERAPI_h__
#include <fstream>
#include <string>

class LoggerAPI {
public:
	LoggerAPI() = default;
	LoggerAPI(std::string logFileName);
	~LoggerAPI();
	LoggerAPI(const LoggerAPI&) = delete;
	LoggerAPI(LoggerAPI&&) = default;

	LoggerAPI& operator=(const LoggerAPI&) = default;
	LoggerAPI&	operator=(LoggerAPI&&) = default;

	void open(std::string logFilename = "log.txt");
	void writeDebugString(std::string str);
	void writeErrorString(std::string str);
	void writeInfoString(std::string str);
private:
	std::ofstream m_ofs;
};
#endif // __LOGGERAPI_h__
