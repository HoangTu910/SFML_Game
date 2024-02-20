#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <string>

const int max_main_menu = 4;
class GUI
{
private:
	int menu_selected;

	sf::RenderWindow* window; //dynamically
	sf::VideoMode vidMode;
	sf::Event evnt;
	sf::Font font;
	

	void init_window();
	void update_gui();
	

public:
	GUI();
	~GUI();
	sf::Sprite gui_background;
	sf::Texture gui_texture;
	sf::Text main_menu[max_main_menu];
	const bool is_running() const;
	std::string select;
	//void pollEvents(sf::RenderWindow* window);
	void update();
	void render();
	void init_gui();
	void close_window();
	sf::Text menu_design(sf::Text* menu, std::string text, int pos_x, int pos_y);
};

