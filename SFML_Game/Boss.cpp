#include "Boss.h"
#include "Animation.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
void Boss::init_boss(string* boss_data)
{
	
	this->boss_texture.loadFromFile(*boss_data);

	float scale_x;
	float scale_y;
	

	scale_x = static_cast<float>(550) / this->boss_texture.getSize().x;
	scale_y = static_cast<float>(400) / this->boss_texture.getSize().y;

	

	this->boss_appearance.setPosition(775, 255);
	this->boss_appearance.setScale(scale_x, scale_y);
	this->boss_appearance.setTexture(this->boss_texture);
}
float offset = 0;

void Boss::update_animation() {
	Animation animation;
	int amplitude = 15;
	animation.floating_animation(&this->boss_appearance, amplitude);
}

int Boss::get_boss_pos_x()
{
	return this->boss_pos_x;
}

int Boss::get_boss_pos_y()
{
	return this->boss_pos_y;
}

