/*
	Create boss attribute
*/

#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

using namespace std;

class Boss
{
private:
	//Boss Attribution
	int heal_percent;
	int damage_per_hit; 
	int mana_percent;
	string boss_name;
	int boss_pos_x = 775;
	int boss_pos_y = 255;
public:
	sf::Sprite boss_appearance;
	sf::Texture boss_texture;

	void init_boss(string* boss_data);
	void update_animation();
	int get_boss_pos_x();
	int get_boss_pos_y();
};

