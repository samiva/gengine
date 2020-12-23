#ifndef __LOGGER_h__
#define __LOGGER_h__
#include "LoggerAPI.h"
#include <string>

class Logger {
public:
	static void Init(std::string logFile) {
		s_api = new LoggerAPI(logFile);
	}

	static void WriteDebugString(std::string str) {
		s_api->writeDebugString(str);
	}

	static void WriteErrorString(std::string str) {
		s_api->writeErrorString(str);
	}

	static void WriteInfoString(std::string str) {
		s_api->writeInfoString(str);
	}

	static void Shutdown() {
		delete s_api;
	}
private:
	static LoggerAPI* s_api;
};
#endif // __LOGGER_h__
