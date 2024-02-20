#include "Animation.h"
#include "Boss.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

//Global
int floating = 0;
bool lreverse = false;

//Function
sf::Sprite Animation::floating_animation(sf::Sprite* item, int amplitude)
{
	sf::Vector2f position = item->getPosition();
	int current_x = position.x;
	int current_y = position.y - floating;
	if (lreverse == false) {
		floating++;
		if (floating >= amplitude) {
			lreverse = true;
		}
	}
	else {
		floating--;
		if (floating == 0) {
			lreverse = false;
		}
	}
	item->setPosition(current_x, current_y + floating);
	return *item;
}

int frameCount = 2;
int currentFrame = 0;
float total_time = 0.0f; 
float delta_time;
int nextFrameX = 0;
int x_cor = 0;
int y_cor = 0;

sf::Sprite Animation::idle_animation(sf::Texture* character_texture, sf::Sprite* character_idle)
{
	character_idle->setTexture(*character_texture);
	int frameWidth = character_texture->getSize().x/4;
	int frameHeight = character_texture->getSize().y;
	sf::IntRect frame(x_cor, y_cor, frameWidth, frameHeight);
	character_idle->setTextureRect(frame);
	float frame_duration = (0.2/10000);
	total_time += clock.restart().asSeconds();
	if (total_time >= frame_duration) {
		total_time -= frame_duration;
		if (currentFrame <= frameCount) {
			// Calculate the next frame's x position
			character_idle->setTextureRect(frame);
			nextFrameX = frame.left + frameWidth;
			frame.left = nextFrameX;
			currentFrame++;
			x_cor = nextFrameX;
		}
		else {
			currentFrame = 0;
			nextFrameX = 0;
			x_cor = 0;
		}
	}
	
	return *character_idle;
}


