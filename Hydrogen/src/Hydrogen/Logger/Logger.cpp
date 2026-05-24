#include "Logger.h"

namespace Logger {
	Logger::OutputStream::OutputStream(std::string name, Hydrogen::Ref<OutputSink> outputSink):outputSink(outputSink),outputName(name) {

	}
	Logger::OutputStream::~OutputStream() {

	}

	void OutputStream::setLogFormat(std::string format) {
		std::stringstream text;
		for(int i = 0; i<format.length(); i++) {
			if(format[i] == '%') {
				std::unique_ptr<Logger::formatToken> token = std::make_unique<Logger::formatToken>(Logger::formatTokenType::TEXT);
				token->text = text.str();
				formatTokens.push_back(std::move(*token));
				text.str(std::string());

				i++;
				switch(format[i]) {
					//Name
					case 'N': {
						formatTokens.push_back(Logger::formatToken(Logger::formatTokenType::NAME));
						break;
					}
					//Time
					case 'T':
					{
						formatTokens.push_back(Logger::formatToken(Logger::formatTokenType::TIME));
						break;
					}
					//Date
					case 'D':
					{
						formatTokens.push_back(Logger::formatToken(Logger::formatTokenType::DATE));
						break;
					}
					//Message
					case 'M':
					{
						formatTokens.push_back(Logger::formatToken(Logger::formatTokenType::MESSAGE));
						break;
					}
				}
			}else {
				text << format[i];
			}
		}
	}

	std::string OutputStream::formatMessage(std::string message) {
		std::stringstream outputText;
		for(auto token:formatTokens) {
			switch(token.formatType) {
				case Logger::formatTokenType::TEXT:
				{
					outputText << token.text;
					break;
				}
				case Logger::formatTokenType::NAME:
				{
					outputText << outputName;
					break;
				}
				case Logger::formatTokenType::TIME:
				{
					auto now = std::chrono::system_clock::now();
					std::time_t nowC = std::chrono::system_clock::to_time_t(now);
					struct tm buf;
					localtime_r(&nowC, &buf);

					outputText << buf.tm_hour << ":" << buf.tm_min << ":" << buf.tm_sec;
					break;
				}
				case Logger::formatTokenType::DATE:
				{
					auto now = std::chrono::system_clock::now();
					std::time_t nowC = std::chrono::system_clock::to_time_t(now);
					struct tm buf;
					localtime_r(&nowC, &buf);
					
					outputText << buf.tm_mday << "-" << (buf.tm_mon + 1) << "-" << (buf.tm_year+1900);
					break;
				}
				case Logger::formatTokenType::MESSAGE:
				{
					outputText << message;
					break;
				}
			}
		}
		return outputText.str();
	}

	/*void OutputStream::logTrace(std::string message) {
		outputSink->output(formatMessage(message),Logger::Severity::TRACE);
	}
	void OutputStream::logMessage(std::string message) {
		outputSink->output(formatMessage(message), Logger::Severity::MESSAGE);

	}
	void OutputStream::logWarning(std::string message) {
		outputSink->output(formatMessage(message),Logger::Severity::WARNING);

	}
	void OutputStream::logFatal(std::string message) {
		outputSink->output(formatMessage(message), Logger::Severity::FATAL);

	}*/
}
