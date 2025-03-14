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
					std::tm localTime;
					localtime_s(&localTime, &nowC);

					outputText << std::put_time(&localTime, "%H:%M:%S");
					break;
				}
				case Logger::formatTokenType::DATE:
				{
					auto now = std::chrono::system_clock::now();
					std::time_t nowC = std::chrono::system_clock::to_time_t(now);
					std::tm localTime;
					localtime_s(&localTime, &nowC);

					outputText << std::put_time(&localTime, "%d-%m-%Y");
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

	void OutputStream::logTrace(std::string message) {
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

	}
}