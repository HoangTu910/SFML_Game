#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

#include "Engine.h"
#include "GUI.h"
using namespace std;

int main()
{
    //Start Engine
    bool game_on = false;

    /*GUI gui;
    while (gui.is_running()) {
        gui.update();
        gui.render();
        if (gui.select == "play") {
            game_on = true;
            gui.close_window();
        }
    }*/
    

    //Game loop
    if (game_on == false) {
        Engine engine;
        while (engine.is_running()) {
            //Update
            engine.update();


            //Render
            engine.render();

        }
    }
    
}