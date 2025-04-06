#pragma once

#include "Event.h"

namespace Hydrogen {
	class H_API AppUpdate:public Event {
		public:

		public:
			AppUpdate(std::chrono::nanoseconds deltaTime):Event(EventType::AppUpdate),deltaTime(deltaTime) {}

			std::string traceEvent() override { return "App update deltaTime:"+std::to_string(deltaTime.count()); }
			static EventType staticGetType() { return EventType::AppUpdate; }

		private:
			std::chrono::nanoseconds deltaTime;
	};
	class H_API AppRender:public Event {
		public:

		public:
		AppRender():Event(EventType::AppRender) {}

		std::string traceEvent() override { return "App rendering"; }
		static EventType staticGetType() { return EventType::AppRender; }
	};
}
