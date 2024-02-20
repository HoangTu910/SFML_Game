#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include "Character.h"
class Animation
{
private:
	sf::Clock clock;
public:
	sf::Sprite floating_animation(sf::Sprite* item, int amplitude);
	sf::Sprite idle_animation(sf::Texture* character_texture, sf::Sprite* character_idle);

};

