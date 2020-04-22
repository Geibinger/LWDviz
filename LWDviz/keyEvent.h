#pragma once

#include "event.h"

#include <sstream>

namespace lv {

	class LWDVIZ_API KeyEvent : public Event{
	public:
		inline int getKeyCode() const { return m_keyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode) {}

		int m_keyCode;
	};

	class LWDVIZ_API KeyPressedEvent : public KeyEvent {

	};
}