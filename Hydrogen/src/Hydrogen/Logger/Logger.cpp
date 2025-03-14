#include "Logger.h"

namespace Logger {
	Logger::OutputStream::OutputStream(std::string name,OutputSink* outputSink):outputSink(outputSink),outputName(name) {

	}
	Logger::OutputStream::~OutputStream() {

	}

	void OutputStream::setLogFormat(std::string format) {
		std::stringstream text;
		for(int i = 0; i<format.length(); i++) {
			if(format[i] == '%') {
				std::unique_ptr<Logger::formatToken> token = std::make_unique<Logger::formatToken>(Logger::formatTokenType::TEXT);
				token->text = text.str();
				std::cout << "adding " << text.str() << " token" << std::endl;
				formatTokens.push_back(std::move(*token));
				text.str(std::string());

				i++;
				switch(format[i]) {
					//Name
					case 'N': {
						formatTokens.push_back(Logger::formatToken(Logger::formatTokenType::NAME));
						std::cout << "adding a name token" << std::endl;
						break;
					}
					//Time
					case 'T':
					{
						formatTokens.push_back(Logger::formatToken(Logger::formatTokenType::TIME));
						std::cout << "adding a time token" << std::endl;
						break;
					}
					//Date
					case 'D':
					{
						formatTokens.push_back(Logger::formatToken(Logger::formatTokenType::DATE));
						std::cout << "adding a date token" << std::endl;
						break;
					}
					//Message
					case 'M':
					{
						formatTokens.push_back(Logger::formatToken(Logger::formatTokenType::MESSAGE));
						std::cout << "adding a message token" << std::endl;
						break;
					}
				}
			}else {
				text << format[i];
			}
		}
	}

	void OutputStream::logTrace(std::string message) {
		//std::cout << message << std::endl;
		std::stringstream output;

		auto now = std::chrono::system_clock::now();
		std::time_t nowC = std::chrono::system_clock::to_time_t(now);
		std::tm localTime = *std::localtime(&nowC);

		output << "[" << outputName << " " << std::put_time(&localTime,"%H:%M:%S") << "] " << message;
		outputSink->output(output.str(), Logger::Severity::TRACE);
	}
	void OutputStream::logMessage(std::string message) {

	}
	void OutputStream::logWarning(std::string message) {

	}
	void OutputStream::logFatal(std::string message) {

	}
}