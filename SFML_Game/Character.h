/*
	Create character attribute
*/
#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
using namespace std;

class Character
{
private:
	int heal_percent;
	int damage_per_hit;
	int mana_percent;
	int character_pos_x[2] = { 100, 300 };
	int character_pos_y[2] = { 330, 350 };
	string character_name;
	int character_id;
	

public:
	Character();
	Character(string character_name, int heal_percent, int damage_per_hit, int mana_percent, string appearance_data, int character_id);

	string appearance_data;

	sf::RectangleShape character_pos_1;
	sf::RectangleShape character_pos_2;
	sf::RectangleShape character_pos_3;
	sf::RectangleShape character_pos_4;

	sf::Sprite character_appearance;
	sf::Texture character_texture;

	void set_character_pos(int x, int y, int x_element, int y_element);
		
	
	void init_character_pos(sf::RectangleShape* character_shape, int num);
	sf::Sprite init_appearance(string* character_data, int num);
	void normal_attack();
	void ultimate_attack();
};

