#include <string>
#include "Character.h"
#include "Boss.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#pragma once
using namespace std;
/*
	Update or create character in this class
*/
class Admin
{
private:

public:
	vector<Character> character_database;
	vector<Boss> boss_database;
};

