#include "Character.h"
#include "Animation.h"
#include "Boss.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>

Character::Character()
{

}

Character::Character(string character_name, int heal_percent, int damage_per_hit, int mana_percent, string appearance_data, int character_id) {
	this->character_name = character_name;
	this->heal_percent = heal_percent;
	this->damage_per_hit = damage_per_hit;
	this->mana_percent = mana_percent;
	this->appearance_data = appearance_data;
	this->character_id = character_id;
}

void Character::set_character_pos(int x, int y, int x_element, int y_element) {
	this->character_pos_x[x_element] = x;
	this->character_pos_y[y_element] = y;
}

void Character::init_character_pos(sf::RectangleShape* character_shape, int num)
{
	int pos_x = 0;
	int pos_y = 0;
	bool done_pos = false;
	switch (num) {
	case 1: 
		pos_x = 0, pos_y = 0;
		break;
	case 2:
		pos_x = 0, pos_y = 1;
		break;
	case 3:
		pos_x = 1, pos_y = 0;
		break;
	case 4:
		pos_x = 1, pos_y = 1;
		break;
	}
	character_shape->setPosition(this->character_pos_x[pos_x], this->character_pos_y[pos_y]);
	character_shape->setSize(sf::Vector2f(100.f, 100.f));
	character_shape->setFillColor(sf::Color::Cyan);
}

sf::Sprite Character::init_appearance(string* character_data, int num)
{
	int pos_x = 0;
	int pos_y = 0;
	bool done_pos = false;
	switch (num) {
	case 1:
		pos_x = 0, pos_y = 0;
		break;
	case 2:
		pos_x = 0, pos_y = 1;
		break;
	case 3:
		pos_x = 1, pos_y = 0;
		break;
	case 4:
		pos_x = 1, pos_y = 1;
		break;
	}
	this->character_texture.loadFromFile(*character_data);
	float scale_x;
	float scale_y;
	Animation animation;
	/*scale_x = static_cast<float>(170) / this->character_texture.getSize().x;
	scale_y = static_cast<float>(190) / this->character_texture.getSize().y;
	this->character_appearance.setScale(scale_x, scale_y);*/
	this->character_appearance = animation.idle_animation(&this->character_texture, &this->character_appearance);
	this->character_appearance.setPosition(this->character_pos_x[pos_x], this->character_pos_y[pos_y]);

	return this->character_appearance;
}

bool once = false;
int init_pos;

void Character::normal_attack()
{
	Boss boss;
	sf::Vector2f current_pos = this->character_appearance.getPosition();
	std::cout << "Current: " << current_pos.x << endl;
	if (once = false) {
		init_pos = current_pos.x;
		once = true;
	}

	int boss_pos_x = boss.get_boss_pos_x();
	if (current_pos.x != boss_pos_x) {
		current_pos.x++;
		std::cout << current_pos.x << endl;
		this->set_character_pos(current_pos.x, current_pos.y, 0, 1);
	}
	else {
		this->set_character_pos(init_pos, current_pos.y, 0, 1);
	}
	
}




