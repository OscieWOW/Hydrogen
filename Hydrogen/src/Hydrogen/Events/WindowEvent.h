#pragma once

#include "Event.h"

namespace Hydrogen {
	class H_API WindowClose:public Event {
		public:

		public:
			WindowClose():Event(EventType::WindowClose) {}

			std::string traceEvent() override { return "Closing window"; }
			static EventType staticGetType() { return EventType::WindowClose; }
	};
	class H_API WindowResize:public Event {
		public:


		public:
			WindowResize(int width, int height):Event(EventType::WindowResize), m_width(width), m_height(height) {}

			int getWidth() { return m_width; }
			int getHeight() { return m_height; }

			std::string traceEvent() override { return "Window Resize: "+std::to_string(m_width)+" "+std::to_string(m_height); }
			static EventType staticGetType() { return EventType::WindowResize; }

		private:
			unsigned int m_width, m_height;
	};
	class H_API WindowFocus:public Event {
		public:

		public:
			WindowFocus():Event(EventType::WindowFocus) {}

			std::string traceEvent() override { return "Window focus"; }
			static EventType staticGetType() { return EventType::WindowFocus; }
	};
	class H_API WindowLostFocus:public Event {
		public:

		public:
			WindowLostFocus():Event(EventType::WindowLostFocus) {}

			std::string traceEvent() override { return "Window lost focus"; }
			static EventType staticGetType() { return EventType::WindowLostFocus; }
	};
	class H_API WindowMoved:public Event {
		public:

		public:
			WindowMoved(int deltaX, int deltaY):Event(EventType::WindowMoved), m_deltaX(deltaX), m_deltaY(deltaY) {}

			int getDeltaX() { return m_deltaX; }
			int getDeltaY() { return m_deltaY; }
			
			std::string traceEvent() override { return "Window moved:"+std::to_string(m_deltaX)+" "+std::to_string(m_deltaY); }
			static EventType staticGetType() { return EventType::WindowMoved; }

		private:
			int m_deltaX, m_deltaY;
	};
}
