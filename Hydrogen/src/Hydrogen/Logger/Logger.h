#pragma once

#include "LoggerEnums.h"
#include "Sink.h"
#include "ConsoleSink.h"
#include  "FileSink.h"
#include <format>

namespace Logger {
	class  OutputStream {
		public:
			OutputStream(std::string name,Hydrogen::Ref<OutputSink> outputSink);
			~OutputStream();

			void setLogFormat(std::string format);
			std::string formatMessage(std::string message);

			template<typename... Args>
			void logTrace(const std::string& message, Args&&... args) {
				auto formatted = std::vformat(
					std::string_view(message),
					std::make_format_args(args...)
				);

				outputSink->output(formatMessage(formatted), Logger::Severity::TRACE);
			}
			void logTrace(const std::string& message) {
				outputSink->output(formatMessage(message),Logger::Severity::TRACE);
			}

			template<typename... Args>
			void logMessage(const std::string& message, Args&&... args) {
				auto formatted = std::vformat(
					std::string_view(message),
					std::make_format_args(args...)
				);

				outputSink->output(formatMessage(formatted), Logger::Severity::MESSAGE);
			}
			void logMessage(const std::string& message) {
				outputSink->output(formatMessage(message), Logger::Severity::MESSAGE);
			}

			template<typename... Args>
			void logWarning(const std::string& message, Args&&... args) {
				auto formatted = std::vformat(
					std::string_view(message),
					std::make_format_args(args...)
				);

				outputSink->output(formatMessage(formatted), Logger::Severity::WARNING);
			}
			void logWarning(const std::string& message) {
				outputSink->output(formatMessage(message), Logger::Severity::WARNING);
			}

			template<typename... Args>
			void logFatal(const std::string& message, Args&&... args) {
				auto formatted = std::vformat(
					std::string_view(message),
					std::make_format_args(args...)
				);

				outputSink->output(formatMessage(formatted), Logger::Severity::FATAL);
			}
			void logFatal(const std::string& message) {
				outputSink->output(formatMessage(message), Logger::Severity::FATAL);
			}

		private:
			std::vector<Logger::formatToken> formatTokens;
			std::string outputName;
			Hydrogen::Ref<Logger::OutputSink> outputSink;

	};
}
