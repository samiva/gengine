#include "pch.h"
#include "LoggerAPI.h"
#include <iostream>

LoggerAPI::~LoggerAPI()
{
	m_ofs.close();
}

LoggerAPI::LoggerAPI(std::string logFileName)
{
	open(logFileName);
}
void LoggerAPI::open(std::string logFilename)
{
	m_ofs.open(logFilename,std::ios_base::trunc);
}

void LoggerAPI::writeDebugString(std::string str)
{
}

void LoggerAPI::writeErrorString(std::string str)
{
	m_ofs << "[ERROR] " << str << std::endl;
}

void LoggerAPI::writeInfoString(std::string str)
{
	m_ofs << "[INFO] " << str << std::endl;
}
