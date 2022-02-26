#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    float timer=0, delay=1;
    int second=0,minute=0,hour=0;
    int posx=0, posy=0, spdx=1,spdy=1;
    String Time;
    Color color=Color::White;

    Clock clock;

    RenderWindow window(VideoMode(480, 340), "Clock");
    window.setFramerateLimit(60);

    //Text Font
    sf::Font font;
    font.loadFromFile("Shizuru-Regular.ttf");

    while (window.isOpen()){

        //get the elapse time
        float elapseTime = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=elapseTime;

        Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                window.close();
            }

        if(second == 60){minute++; second=0;}
        if(minute == 60){hour++; minute=0;}

        //converting int to string
        String s = to_string(second);
        String m = to_string(minute);
        String h = to_string(hour);
        Time = h + " : " + m + " : " + s;

        //Text to draw
        Text text(Time,font);
        text.setCharacterSize(30);
        text.setStyle(Text::Bold);
        text.setFillColor(color);

        text.setPosition(posx,posy);
        posx+=spdx;
        posy+=spdy;
        if(posx >= 265) {spdx=-spdx; color=Color::White;}
        if(posx <= 0)   {spdx*=-1;   color=Color::Red;  }
        if(posy >= 300) {spdy=-spdy; color=Color::Blue; }
        if(posy <= 0)   {spdy*=-1;   color=Color::Green;}
        
        

        //delay
        if(timer>delay){
            second++;
            timer = 0;
        }

        window.clear(Color::Black);
        window.draw(text);
        window.display();
    }

    return 0;
}