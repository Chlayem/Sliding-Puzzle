#include "main.h"

void LoadFont();

int main()
{
    window.create(sf::VideoMode(800, 600), "SFML works!");
    window.setVerticalSyncEnabled(true);
    LoadFont();
    RectangleShape back(Vector2f(800.f, 600.f));
    Texture ground;
    ground.loadFromFile("res/background.png");
    back.setTexture(&ground);
	Texture one;
    n = 16;
    T = RandomTab(n);
    VerifT = construireVerifT(n, T);
    Tab = new Tableau[n - 1];
    Construire(n,Tab);

    
	sprintf_s(ch, "%d", 1);
	setText(txt, ch);
    while (window.isOpen())
    {
        Event evnt;
        while (window.pollEvent(evnt))
        {
            input.InputHandler(evnt, window);
            CheckBtn();
        }
        
        window.clear();
        window.draw(back);
        window.draw(txt);
        for (int i = 0; i < n-1; i++)
        {
            window.draw(Tab[i].RecTab);
            window.draw(Tab[i].chiffre);
        }
        Mov(n);
        Verif(n, VerifT,T);
        window.display();
    }

    return 0;
}

void setText(Text& txt, String str)
{
    txt.setFont(font);
    txt.setCharacterSize(40);
    txt.setString(str);
    txt.setFillColor(Color::Black);
    txt.setStyle(Text::Bold );
}
void LoadFont()
{
	if (!(font.loadFromFile("res/Poppins-Regular.ttf")))
		cout << "Erreur de chargement de font" << endl;
}

void CheckBtn()
{
	if (input.getButton().left)
	{
		posX--;
		if (posX < 0)
			posX = 0;
		sprintf_s(ch, "%d", posX);
		setText(txt, ch);
	}
	if (input.getButton().right)
	{
		posX++;
		if (posX > 100)
			posX = 100;
		sprintf_s(ch, "%d", posX);
		setText(txt, ch);
	}
	if (input.getButton().down)
		posX = 0;
	sprintf_s(ch, "%d", posX);
	setText(txt, ch);
	if (input.getButton().up)
		posX = 100;
	sprintf_s(ch, "%d", posX);
	setText(txt, ch);
	if (input.getButton().escape)
		window.close();
	//if (input.getButton().attack)
	//	;
}

Tup* RandomTab(int n)
{
    srand(time(NULL));
    Tup* T;
    T = new Tup[n];
    int j = 0; int k;
    int a = (rand() % (int)sqrt(n) + 2) * 100;
    int b = (rand() % (int)sqrt(n) + 1) * 100;
    cout << a << "\t" << b << endl;
    T[j].a = a;
    T[j++].b = b;
    do
    {
        a = (rand() % (int)sqrt(n) + 2) * 100;
        b = (rand() % (int)sqrt(n) + 1) * 100;
        bool test = true;
        for (k = 0; k < j; k++)
        {
            if (b == T[k].b && a == T[k].a)
                test = false;
        }
        if (test)
        {
            T[j].a = a;
            T[j++].b = b;
            cout << T[j-1].a << "\t" << T[j-1].b << endl;
        }
    } while (j < n);
    // cout << k <<endl ;
    // cout << j <<endl ;
    cout << "\n" << endl;
    return T;
}


void Mov(int n) 
{
    if (Mouse::isButtonPressed(Mouse::Left))
    {
        Vector2i mousPos = Mouse::getPosition(window);
        if ((mousPos.x > T[n-1].a) && (mousPos.x < T[n-1].a + 100))
        {
            if ((mousPos.y < T[n-1].b) && (mousPos.y > T[n-1].b - 100))
            {
                for (int i = 0; i < n-1; i++)
                {
                    if (T[i].a == T[n-1].a)
                    {
                        if (T[i].b == T[n-1].b - 100)
                        {
                            T[i].b += 100;
                            T[n-1].b -= 100;
                            Tab[i].RecTab.move(0.f, 100.f);
                            Tab[i].chiffre.move(0.f, 100.f);
                            break;
                        }
                    }
                }
            }
            if ((mousPos.y > T[n-1].b + 100) && (mousPos.y < T[n-1].b + 200))
            {
                for (int i = 0; i < n-1; i++)
                {
                    if (T[i].a == T[n-1].a)
                    {
                        if (T[i].b == T[n-1].b + 100)
                        {
                            T[i].b -= 100;
                            T[n-1].b += 100;
                            Tab[i].RecTab.move(0.f,-100.f);
                            Tab[i].chiffre.move(0.f, -100.f);
                            break;
                        }
                    }
                }
            }
        }
        if ((mousPos.y > T[n-1].b) && (mousPos.y < T[n-1].b + 100))
        {
            if ((mousPos.x < T[n-1].a) && (mousPos.x > T[n-1].a - 100))
            {
                for (int i = 0; i < n-1; i++)
                {
                    if (T[i].b == T[n-1].b)
                    {
                        if (T[i].a == T[n-1].a - 100)
                        {
                            T[i].a += 100;
                            T[n-1].a -= 100;
                            Tab[i].RecTab.move(100.f,0.f);
                            Tab[i].chiffre.move(100.f, 0.f);
                            break;
                        }
                    }
                }
            }
            if ((mousPos.x > T[n-1].a + 100) && (mousPos.x < T[n-1].a + 200))
            {
                for (int i = 0; i < n-1; i++)
                {
                    if (T[i].b == T[n-1].b)
                    {
                        if (T[i].a == T[n-1].a + 100)
                        {
                            T[i].a -= 100;
                            T[n-1].a += 100;
                            Tab[i].RecTab.move(-100.f,0.f);
                            Tab[i].chiffre.move(-100.f, 0.f);
                            break;
                        }
                    }
                }
            }
        }   
    }

}

void Construire(int n,Tableau* Tab)

{
   /* Texture* F;
    F = new Texture[n-1];
    string che = "";*/
    Text num;
    for (int i = 0; i < n-1; i++)
    {
        Tab[i].RecTab.setSize(Vector2f(95.f, 95.f));
        string s = to_string(i + 1);
       /* che = "res/" + s + ".png";
        F[i].loadFromFile(che);*/
        Tab[i].RecTab.setFillColor(Color(222, 184, 135));
        Tab[i].RecTab.setOutlineThickness(5);
        Tab[i].RecTab.setOutlineColor(Color(43, 166, 166));
        //RecTab[i].setTexture(F + i);
        //cout << T[i].a << "\t" << T[i].b << endl;
        setText(num, s);
        Tab[i].RecTab.setPosition((float)T[i].a, (float)T[i].b);
        FloatRect numRect = num.getLocalBounds();
        num.setOrigin(numRect.width / 2, numRect.height / 2);
        num.setPosition((float)T[i].a + 45.f, (float)T[i].b + 38.f);
        
        /*if (i < 9)
        {
           
        }
        else
        {
            num.setPosition((float)T[i].a + 26.f, (float)T[i].b + 25.f);
        }
        */
        Tab[i].chiffre = num;
    }
}

Tup* construireVerifT(int n,Tup* T)
{
    Tup* VerifT;
    VerifT = new Tup[n];
    VerifT[0].a = T[0].a;
    VerifT[0].b = T[0].b;
    for (int j, i = 1; i < n; i++)
    {
        VerifT[i] = T[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (T[i].b < VerifT[j].b)
            {
                VerifT[j + 1] = VerifT[j];
                VerifT[j] = T[i];
            }
            else if(T[i].b == VerifT[j].b)
            {
                if (T[i].a < VerifT[j].a)
                {
                    VerifT[j + 1] = VerifT[j];
                    VerifT[j] = T[i];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << VerifT[i].a << "\t" << VerifT[i].b << endl;
    }
    return VerifT;
}

void Verif(int n, Tup* VerifT,Tup* T)
{
    for (int i = 0; i < n-1;i++)
    {
        if (VerifT[i].a == T[i].a && VerifT[i].b == T[i].b)
        {
            Tab[i].RecTab.setOutlineColor(Color(80, 246, 41));
        }
        else
        {
            Tab[i].RecTab.setOutlineColor(Color(43, 166, 166));
        }

    }
}