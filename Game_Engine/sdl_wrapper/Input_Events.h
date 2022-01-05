#ifndef INPUT_EVENTS_H
#define INPUT_EVENTS_H

#include "../utils/drawing/Point.h"
#include "../utils/EventDefines.h"

//Forword Declarations
union SDL_Event;

class InputEvent
{
public:
	bool pollEvent() const;

	Point mousePos = Point::UNKNOWN;
	int32_t key = Keyboard::Key::KEY_UNKNOWN;
	uint8_t mouseButton = Mouse::MouseKey::UNKNOWN;
	TouchEvent touchEvent = TouchEvent::UNKNOWN;

private:
	/** Holds the OS communication event system */
	SDL_Event* _sdlEvent = nullptr;
};

#endif // INPUT_EVENTS_H

