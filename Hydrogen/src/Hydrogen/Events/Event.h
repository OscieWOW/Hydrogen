#pragma once

#include "../Core/Core.h"
#include "../Core/Log.h"

namespace Hydrogen {
	enum class  EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled,
		GameUpdate, GameEvent
	};

	class  Event {
		public:
			bool handeled = false;
			EventType eventType;

		public:
			Event(EventType type):eventType(type) {};

			virtual std::string traceEvent() = 0;
			static EventType staticGetType() {return EventType::None;}
	};

	class  EventDispatcher {
		template<typename t> using EventFn = std::function<bool(t&)>;

		private:
			Event& m_event;

		public:
			EventDispatcher(Event& e):m_event(e) {}

			template<typename t> void dispatch(EventFn<t> fn) {
				if(t::staticGetType() == m_event.eventType) {
					m_event.handeled = fn(*(t*)&m_event);
				}
			}
	};
}
