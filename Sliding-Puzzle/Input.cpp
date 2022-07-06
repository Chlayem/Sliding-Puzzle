#include "Input.h"

Input::Input()
{
	button.left = button.right = button.up = button.down = button.attack = button.escape = false;
}

void Input::InputHandler(Event evt, RenderWindow& window)
{
	if (evt.type == Event::Closed)
		window.close();
	if (evt.type == Event::KeyPressed)
		switch (evt.key.code)
		{
		case Keyboard::Escape:
			button.escape = true;
			break;
		case Keyboard::Left:
			button.left = true;
			break;
		case Keyboard::Right:
			button.right = true;
			break;
		case Keyboard::Down:
			button.down = true;
			break;
		case Keyboard::Up:
			button.up = true;
			break;
		default:
			break;
		}
	if (evt.type == Event::KeyReleased)
		switch (evt.key.code)
		{
		case Keyboard::Escape:
			button.escape = false;
			break;
		case Keyboard::Left:
			button.left = false;
			break;
		case Keyboard::Right:
			button.right = false;
			break;
		case Keyboard::Down:
			button.down = false;
			break;
		case Keyboard::Up:
			button.up = false;
			break;
		default:
			break;
		}
	if (evt.type == Event::MouseButtonPressed)
	{
		if (evt.mouseButton.button == Mouse::Left)
			button.attack = true;
		if (evt.mouseButton.button == Mouse::Right)
			button.attack = false;
	}
	if (evt.type == Event::TextEntered)
	{
		if (evt.text.unicode < 128)
			std::cout << static_cast<char>(evt.text.unicode) ;
	}
}

Input::Button Input::getButton() const
{
	return button;
}