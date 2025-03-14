#pragma once

#include "../Core/Core.h"

namespace Logger {
	enum class Severity {
		FATAL,
		WARNING,
		MESSAGE,
		TRACE
	};

	enum class formatTokenType {
		TEXT,
		NAME,
		TIME,
		DATE,
		MESSAGE
	};
	struct formatToken {
		formatTokenType formatType;
		std::string text;
		formatToken(formatTokenType type):formatType(type) {}
	};
}
