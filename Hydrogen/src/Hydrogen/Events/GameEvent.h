#pragma once

#include "Event.h"

namespace Hydrogen {
	class H_API GameUpdate:public Event {
		public:
			float deltaTime;

		public:
			GameUpdate(EventType type, float deltaTime):Event(type),deltaTime(deltaTime) {
				H_CORE_TRACE("New game event");
			}

			std::string traceEvent() override {return std::to_string(deltaTime);}
			static EventType staticGetType() {return EventType::GameUpdate;}
	};

	class H_API GameEvent:public Event {
		public:
			std::function<void()> func;

		public:
			GameEvent(EventType type,std::function<void()> eventFunc):Event(type),func(eventFunc) {}

			std::string traceEvent() override {return "GameEvents does not have a string returnable argument";}
			static EventType staticGetType() {return EventType::GameEvent;}

	};
}