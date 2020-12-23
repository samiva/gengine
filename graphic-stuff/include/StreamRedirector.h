#ifndef __STREAMREDIRECTOR_H__
#define __STREAMREDIRECTOR_H__
#include "pch.h"

class StreamRedirector {
public:
	StreamRedirector(const std::string& sout = "stdout.txt", const std::string& eout="stderr.txt")
	: m_sout(sout.c_str(), std::ios_base::trunc), m_eout(eout.c_str(), std::ios_base::trunc), m_sbuff(nullptr),m_ebuff(nullptr)
	{
		// Redirect stdout
		if (m_sout.is_open()) {
			m_sbuff = std::cout.rdbuf();
			std::cout.rdbuf(m_sout.rdbuf());
		}

		// Redirect stderr
		if (m_eout.is_open()) {
			m_ebuff = std::cerr.rdbuf();
			std::cerr.rdbuf(m_eout.rdbuf());
		}

	}

	~StreamRedirector() {
		if (m_sbuff != nullptr) {
			std::cout.rdbuf(m_sbuff);
		}
		if (m_ebuff != nullptr) {
			std::cerr.rdbuf(m_ebuff);
		}
		if (m_sout.is_open()) {
			m_sout.close();
		}
		if (m_eout.is_open()) {
			m_eout.close();
		}
	}
private:
	std::ofstream m_sout;
	std::ofstream m_eout;
	std::streambuf* m_sbuff;
	std::streambuf* m_ebuff;
};
#endif //!__STREAMREDIRECTOR_H__
