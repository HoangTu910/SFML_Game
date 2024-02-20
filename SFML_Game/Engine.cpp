
#include "Engine.h"
#include "Boss.h"
#include "GUI.h"

#include <iostream>


//Global Variables
string char_1 = "Character/zhongli.png";
string char_2 = "Character/xiao_idle.png";
string char_3 = "Character/lumine.png";
string char_4 = "Character/nahida.png";
string boss_data = "Character/andius_boss_rm.png";
//Private Functions
void Engine::initialize_variables() {
	this->window = nullptr;
}

void Engine::init_window() {
	this->vidMode.height = 720;
	this->vidMode.width = 1280;
	this->window = new sf::RenderWindow(this->vidMode, "GAME", sf::Style::Titlebar |sf::Style::Close);
    this->window->setFramerateLimit(60);
    this->return_button = gui->menu_design(&this->return_button, "Return", 2, 2);
    this->test_button = gui->menu_design(&this->test_button, "Attack", 200, 2);
}




//Constructors / Destructors
Engine::Engine() {
    gui = new GUI();
    boss = new Boss();
	this->initialize_variables();
	this->init_window();
    gui->init_gui();
    
    
    master_character = new Character();
    character_1 = new Character("Xiao", 5000, 200, 100, "Character/xiao_idle.png", 1);
    character_2 = new Character();
    character_3 = new Character();
    character_4 = new Character();

    

    boss->init_boss(&boss_data);
    master_character->init_appearance(&character_1->appearance_data, 2);
   /* master_character->init_appearance(&char_1, 1);
    master_character->init_appearance(&character_1->ap, 2);
    master_character->init_appearance(&char_3, 3);
    master_character->init_appearance(&char_4, 4);*/

    /*character_1->init_character_pos(&character_1->character_pos_1, 1);
    character_2->init_character_pos(&character_2->character_pos_2, 2);
    character_3->init_character_pos(&character_3->character_pos_3, 3);
    character_4->init_character_pos(&character_4->character_pos_4, 4);*/
}

void Engine::init_world()
{
    this->worldBackGroundTex.loadFromFile("Texture/arena_1.png");
    float scale_x;
    float scale_y;
    scale_x = static_cast<float>(1280) / this->worldBackGroundTex.getSize().x;
    scale_y = static_cast<float>(720) / this->worldBackGroundTex.getSize().y;
    this->worldBackGround.setScale(scale_x, scale_y);
    this->worldBackGround.setTexture(this->worldBackGroundTex);
}

Engine::~Engine() {
	delete this->window;
    delete boss;
    delete gui;
    delete master_character;
    delete character_1;
    delete character_2;
    delete character_3;
    delete character_4;
}

//Accessors
const bool Engine::is_running() const
{
	return this->window->isOpen();
}

//Public Functions
void Engine::pollEvents()
{
    sf::Cursor pointer_cursor;
    /*if (pointer_cursor.loadFromSystem(sf::Cursor::Hand))
    {
        this->window->setMouseCursor(pointer_cursor);
    }*/
    while (this->window->pollEvent(this->evnt)) {
        switch (this->evnt.type) {
        case::sf::Event::Closed:
            this->window->close();
            break;
        case::sf::Event::KeyPressed:
            if (this->evnt.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
        case::sf::Event::MouseButtonPressed:
            if (evnt.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->window);
                for (int i = 0; i < max_main_menu; i++) {
                    if (gui->main_menu[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        switch (i) {
                        case 0:
                            gui->select = "play";
                            gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                            break;
                        case 1:
                            gui->select = "character";
                            gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                            break;
                        case 2:
                            gui->select = "gacha";
                            gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                            break;
                        case 3:
                            gui->select = "exit";
                            gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                            this->window->close();
                            break;
                        default:
                            gui->main_menu[i].setFillColor(sf::Color::White);
                            break;
                        }
                    }
                }
                if (this->return_button.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    gui->select = "none";
                }
                if (this->test_button.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    master_character->normal_attack();
                }
            }
            
        default:
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->window);
            for (int i = 0; i < max_main_menu; i++) {
                if (gui->main_menu[i].getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    /*switch (i) {
                    case 0:
                        gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                        pointer_cursor.loadFromSystem(sf::Cursor::Hand);
                        this->window->setMouseCursor(pointer_cursor);
                        break;
                    case 1:
                        gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                        pointer_cursor.loadFromSystem(sf::Cursor::Hand);
                        this->window->setMouseCursor(pointer_cursor);
                        break;
                    case 2:
                        gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                        pointer_cursor.loadFromSystem(sf::Cursor::Hand);
                        this->window->setMouseCursor(pointer_cursor);
                        break;
                    case 3:
                        gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                        pointer_cursor.loadFromSystem(sf::Cursor::Hand);
                        this->window->setMouseCursor(pointer_cursor);
                        break;
                    }*/
                    gui->main_menu[i].setFillColor(sf::Color::Color(128, 128, 128));
                    pointer_cursor.loadFromSystem(sf::Cursor::Hand);
                    this->window->setMouseCursor(pointer_cursor);
                    break;
                }
                else if (this->return_button.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    this->return_button.setFillColor(sf::Color::Color(128, 128, 128));
                    pointer_cursor.loadFromSystem(sf::Cursor::Hand);
                    this->window->setMouseCursor(pointer_cursor);
                }
                else {
                    pointer_cursor.loadFromSystem(sf::Cursor::Arrow);
                    gui->main_menu[i].setFillColor(sf::Color::White);
                    this->return_button.setFillColor(sf::Color::White);
                    this->window->setMouseCursor(pointer_cursor);
                }
            }
        }
    }
}



void Engine::update() {
    this->pollEvents();


    /*std::cout << "Pos: " << sf::Mouse::getPosition(*this->window).x << " " << 
                            sf::Mouse::getPosition(*this->window).y << endl;*/
    boss->update_animation();
}

void Engine::render_world()
{
    this->window->draw(this->worldBackGround);

    //this->window->draw(master_character->init_appearance(&char_1, 4));
    this->window->draw(master_character->init_appearance(&character_1->appearance_data, 2));
    //this->window->draw(master_character->init_appearance(&char_3, 3));
    //this->window->draw(master_character->init_appearance(&char_4, 1));

}

void Engine::render_menu()
{
    this->window->draw(gui->gui_background);
    for (int i = 0; i < max_main_menu; i++) {
        this->window->draw(gui->main_menu[i]);
    }
}

void Engine::render() {
    this->window->clear();
    if (gui->select != "play") {
        this->render_menu();
    }
    //Draw game
    if (gui->select == "play") {
        this->init_world();
        this->render_world();
        this->window->draw(this->return_button);
        this->window->draw(this->test_button);

        this->window->draw(boss->boss_appearance);

        this->window->draw(character_1->character_pos_1);
        this->window->draw(character_2->character_pos_2);
        this->window->draw(character_3->character_pos_3);
        this->window->draw(character_4->character_pos_4);
    }
    

    this->window->display();
}