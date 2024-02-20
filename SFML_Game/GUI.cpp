#include "GUI.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
void GUI::init_window()
{
	this->vidMode.height = 720;
	this->vidMode.width = 1280;
	this->window = new sf::RenderWindow(this->vidMode, "GUI", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}


void GUI::init_gui()
{
    this->font.loadFromFile("Font/zh-cn.ttf");
    this->gui_texture.loadFromFile("Texture/night_bg.png");

    menu_design(&this->main_menu[0], "START", 870, 200);
    menu_design(&this->main_menu[1], "CHARACTER", 870, 300);
    menu_design(&this->main_menu[2], "GACHA", 870, 400);
    menu_design(&this->main_menu[3], "EXIT", 870, 500);

    float scale_x;
    float scale_y;
    scale_x = static_cast<float>(1280) / this->gui_texture.getSize().x;
    scale_y = static_cast<float>(720) / this->gui_texture.getSize().y;
    this->gui_background.setScale(scale_x, scale_y);
    this->gui_background.setTexture(this->gui_texture);

}


sf::Text GUI::menu_design(sf::Text* menu, std::string text, int pos_x, int pos_y)
{
    menu->setFont(this->font);
    menu->setFillColor(sf::Color::White);
    menu->setString(text);
    menu->setCharacterSize(40);
    menu->setPosition(pos_x, pos_y);

    return *menu;
}

GUI::GUI()
{
    
}

GUI::~GUI() {
    delete this->window;
}

const bool GUI::is_running() const
{
    return this->window->isOpen();
}


//void GUI::pollEvents(sf::RenderWindow* windows)
//{
//    while (windows->pollEvent(this->evnt)) {
//        switch (this->evnt.type) {
//        case::sf::Event::MouseButtonPressed:
//            if (evnt.mouseButton.button == sf::Mouse::Left)
//            {
//                sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->window);
//                for (int i = 0; i < max_main_menu; i++) {
//                    if (this->main_menu[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
//                        switch (i) {
//                        case 0: 
//                            this->select = "play";
//                            this->main_menu[i].setFillColor(sf::Color::Color(128,128,128));
//                            break;
//                        case 1:
//                            this->select = "character";
//                            this->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
//                            break;
//                        case 2:
//                            this->select = "gacha";
//                            this->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
//                            break;
//                        case 3:
//                            this->select = "exit";
//                            this->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
//                            windows->close();
//                            break;
//                        default:
//                            this->main_menu[i].setFillColor(sf::Color::White);
//                            break;
//                        }
//                    }
//                }
//            }
//        default:
//            sf::Vector2i mousePosition = sf::Mouse::getPosition(*windows);
//            for (int i = 0; i < max_main_menu; i++) {
//                if (this->main_menu[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
//                    switch (i) {
//                    case 0:
//                        this->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
//                        break;
//                    case 1:
//                        this->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
//                        break;
//                    case 2:
//                        this->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
//                        break;
//                    case 3:
//                        this->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
//                        break;                    }
//                }
//                else {
//                    main_menu[i].setFillColor(sf::Color::White);
//                }
//            }
//        }
//    }
//}

void GUI::update()
{
    
}

void GUI::render()
{
    this->window->clear();
    this->window->draw(gui_background);
    for (int i = 0; i < max_main_menu; i++) {
        this->window->draw(this->main_menu[i]);
    }

    this->window->display();
}

void GUI::close_window()
{
    this->window->close();
}

