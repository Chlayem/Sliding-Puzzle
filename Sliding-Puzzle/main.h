#include "Input.h"
#include "time.h"
#include <math.h>
RenderWindow window;
Font font;
Text txt;
int n ;
Input input;
int posX = 1;
char ch[256];
char ch1[256];
struct Tup
{
    int a;
    int b;
};
Tup* T;
Tup* VerifT;
struct Tableau
{
    RectangleShape RecTab;
    Text chiffre;
};
Tableau* Tab;
void setText(Text& txt, String str);
void LoadFont();
void CheckBtn();
void Construire(int n, Tableau* Tab);
Tup* RandomTab(int n);
Tup* construireVerifT(int n, Tup* T);
void Mov(int n);
void  Verif(int n, Tup* VerifT,Tup* T);
//void InputHandler(Event evt, RenderWindow& window)
//{
//	if (evt.type == Event::Closed)
//		window.close();
//
//	/*if (evt.type == Event::KeyPressed)
//		if (evt.key.code = Keyboard::Escape)
//			window.close();*/
//	if (evt.type == Event::MouseButtonPressed)
//	{
//		if (evt.mouseButton.button == Mouse::Left)
//			setText(txt, "Click gauche");
//		if (evt.mouseButton.button == Mouse::Right)
//			setText(txt, "Click droit");
//	}
//	if (Keyboard::isKeyPressed(Keyboard::Left))
//		setText(txt, "Fleche gauche");
//	if (Keyboard::isKeyPressed(Keyboard::Right))
//		setText(txt, "Fleche droit");
//	if (Mouse::isButtonPressed(Mouse::Left))
//		setText(txt, "Click gauche");
//	/*switch (evt.type)
//	{
//		case 
//	default:
//		break;
//	}*/
//	
//}