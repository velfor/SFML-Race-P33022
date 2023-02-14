#pragma once
#include "settings.h"

struct Obstacle {
	sf::Texture texture;
	sf::Sprite sprite;
};

void obstacleInit(Obstacle& obs, std::string fileName) {
	obs.texture.loadFromFile(fileName);
	obs.sprite.setTexture(obs.texture);
	int x, y;
	int s = rand() % 4;
	if (s == 0) x = 100;
	else if (s == 1) x = 200;
	else if (s == 2) x = 300;
	else if (s == 3) x = 400;
	y = rand() % 951 - 800;
	obs.sprite.setPosition(x, y);
}