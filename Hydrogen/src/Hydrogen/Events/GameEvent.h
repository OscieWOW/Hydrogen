#pragma once

#include "Event.h"

namespace Hydrogen {
	class H_API GameUpdate:public Event {
		public:
			std::chrono::nanoseconds deltaTime;

		public:
			GameUpdate(std::chrono::nanoseconds deltaTime):Event(EventType::GameUpdate),deltaTime(deltaTime) {			}

			std::string traceEvent() override {return "GameUpdate dt:"+std::to_string(deltaTime.count());}
			static EventType staticGetType() {return EventType::GameUpdate;}
	};

	class H_API GameEvent:public Event {
		public:
			std::function<void()> func;

		public:
			GameEvent(std::function<void()> eventFunc):Event(EventType::GameEvent),func(eventFunc) {}

			std::string traceEvent() override {return "GameEvents does not have a string returnable argument";}
			static EventType staticGetType() {return EventType::GameEvent;}

	};
}