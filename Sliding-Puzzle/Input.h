#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

class Input
{
	struct Button { bool left, right, up, down, attack, escape; };

public:
	Input();
	void InputHandler(Event evt, RenderWindow& window);
	Button getButton() const;

private:
	Button button;
};

