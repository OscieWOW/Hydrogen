#pragma once

#include "Event.h"

namespace Hydrogen {
	class  KeyPressed:public Event {
		public:

		public:
			KeyPressed(int keycode, bool repeat = true):Event(EventType::KeyPressed),keycode(keycode),repeat(repeat) {}

			std::string traceEvent() override { return "Key:"+std::to_string(keycode)+" pressed, repeat:"+std::to_string(repeat); }
			static EventType staticGetType() { return EventType::KeyPressed; }
				
			int getKeycode() { return keycode; }
			bool getRepeat() { return repeat; }

		private:
			bool repeat;
			int keycode;
	};

	class  KeyReleased:public Event {
		public:

		public:
			KeyReleased(int keycode):Event(EventType::KeyReleased),keycode(keycode) {}
		
			std::string traceEvent() override { return "Key:"+std::to_string(keycode)+" released"; }
			static EventType staticGetType() { return EventType::KeyReleased; }
		
			int getKeycode() { return keycode; }

		private:
			int keycode;
	};

	class  KeyTyped:public Event {
		public:

		public:
			KeyTyped(int keycode):Event(EventType::KeyTyped), keycode(keycode) {}

			std::string traceEvent() override { return "Key:"+std::to_string(keycode)+" typed"; }
			static EventType staticGetType() { return EventType::KeyTyped; }
		
			int getKeycode() { return keycode; }

		private:
			int keycode;
	};

	class  MouseButtonPressed:public Event {
		public:

		public:
			MouseButtonPressed(int keycode):Event(EventType::MouseButtonPressed), keycode(keycode) {}

			std::string traceEvent() override { return "Mouse button:"+std::to_string(keycode)+" pressed"; }
			static EventType staticGetType() { return EventType::MouseButtonPressed; }
	
			int getButton() { return keycode; }

		private:
			int keycode;
	};

	class  MouseButtonReleased:public Event {
		public:

		public:
			MouseButtonReleased(int keycode):Event(EventType::MouseButtonReleased), keycode(keycode) {}

			std::string traceEvent() override { return "Mouse button:"+std::to_string(keycode)+" released"; }
			static EventType staticGetType() { return EventType::MouseButtonReleased; }

			int getButton() { return keycode; }

		private:
			int keycode;
	};

	class  MouseMoved:public Event {
		public:

		public:
			MouseMoved(int x, int y):Event(EventType::MouseMoved),x(x),y(y) {}

			std::string traceEvent() override { return "MouseX:"+std::to_string(x)+" MouseY:"+std::to_string(y); }
			static EventType staticGetType() { return EventType::MouseMoved; }

		private:
			int x, y;
	};
	class  MouseScrolled:public Event {
		public:

		public:
			MouseScrolled(int scroll):Event(EventType::MouseScrolled), scroll(scroll) {}

			std::string traceEvent() override { return "Mouse scrolled:"+std::to_string(scroll)+" px"; }
			static EventType staticGetType() { return EventType::MouseScrolled; }

		private:
			int scroll;
	};
}