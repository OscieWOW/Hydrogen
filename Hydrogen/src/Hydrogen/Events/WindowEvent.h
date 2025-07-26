#pragma once

#include "Event.h"

namespace Hydrogen {
	class  WindowClose:public Event {
		public:

		public:
			WindowClose():Event(EventType::WindowClose) {}

			std::string traceEvent() override { return "Closing window"; }
			static EventType staticGetType() { return EventType::WindowClose; }
	};
	class  WindowResize:public Event {
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
	class  WindowFocus:public Event {
		public:

		public:
			WindowFocus():Event(EventType::WindowFocus) {}

			std::string traceEvent() override { return "Window focus"; }
			static EventType staticGetType() { return EventType::WindowFocus; }
	};
	class  WindowLostFocus:public Event {
		public:

		public:
			WindowLostFocus():Event(EventType::WindowLostFocus) {}

			std::string traceEvent() override { return "Window lost focus"; }
			static EventType staticGetType() { return EventType::WindowLostFocus; }
	};
	class  WindowMoved:public Event {
		public:

		public:
			WindowMoved(int X, int Y):Event(EventType::WindowMoved), m_X(X), m_Y(Y) {}

			int getX() { return m_X; }
			int getY() { return m_Y; }
			
			std::string traceEvent() override { return "Window moved:"+std::to_string(m_X)+" "+std::to_string(m_Y); }
			static EventType staticGetType() { return EventType::WindowMoved; }

		private:
			int m_X, m_Y;
	};
}
