#pragma once
#include "Boss.h"
#include "Character.h"
#include "GUI.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>


class Engine
{
private:
	sf::RenderWindow* window; //dynamically
	sf::VideoMode vidMode;
	sf::Event evnt;
	sf::Sprite worldBackGround;
	sf::Texture worldBackGroundTex;
	sf::Text return_button;
	sf::Text test_button;
	//Function
	void initialize_variables();
	void init_window();
	void init_world();

public:
	//Constructors
	Engine();
	virtual ~Engine();
	Boss* boss;
	GUI* gui;
	Character* character_1;
	Character* character_2;
	Character* character_3;
	Character* character_4;
	Character* master_character;


	//Accessors
	const bool is_running() const;

	//Functions
	void pollEvents();
	void event_menu();
	void update();
	void render_world();
	void render_menu();
	void render();
};

