#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
struct Brick {
	sf::RectangleShape shape;
	sf::Color color;
	sf::Vector2f position;
};
void brickInit(Brick& brick, sf::Vector2f position) {
	brick.position = position;
	brick.shape.setSize(BRICK_SIZE);
	brick.shape.setFillColor(sf::Color::Black);
	brick.shape.setPosition(brick.position);
	brick.shape.setOutlineThickness(1.f);
	brick.shape.setOutlineColor(sf::Color::White);
}
void brickUpdate(Brick& brick) {

}
void brickDraw(sf::RenderWindow& window, const Brick& brick) {
	window.draw(brick.shape);
}

struct Bricks {
	int size;
	Brick brickArr[5];
};

void bricksInit(Bricks& bricks, int size, sf::Vector2f rowStartPos,
	float offsetY){
	bricks.size = size;
	for (int i = 0; i < bricks.size; i++) {
		sf::Color::Black;
		sf::Vector2f position{ rowStartPos.x, rowStartPos.y + offsetY * i };
		brickInit(bricks.brickArr[i], position);

	}
}
void bricksUpdate(Bricks& bricks) {
	for (int i = 0; i < bricks.size; i++) {
		brickUpdate(bricks.brickArr[i]);
	}
}
void bricksDraw(sf::RenderWindow& window, const Bricks& bricks) {
	for (int i = 0; i < bricks.size; i++) {
		brickDraw(window, bricks.brickArr[i]);
	}
}