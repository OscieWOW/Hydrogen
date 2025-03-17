#pragma once

#include "Event.h"

namespace Hydrogen {
	class H_API GameEvent:public Event {
		public:
			float deltaTime;

		public:
			GameEvent(EventType type, float deltaTime):Event(type),deltaTime(deltaTime) {}

			std::string traceEvent() override {
				return std::to_string(deltaTime);
			}
			static EventType staticGetType() {return EventType::GameEvent;}
	};
}