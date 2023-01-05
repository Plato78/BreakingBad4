#pragma once
#include "SFML/Graphics.hpp"
#include "BAT.h"
#include "BALL.h"
//¡»“¿
void batInit(Bat& bat) {
	bat.shape.setSize(sf::Vector2f(bat_width, bat_height));
	bat.shape.setFillColor(Bat_Color);
	bat.shape.setPosition(bat_start_pos);
	bat.speedx = 0.f;
}
void batControl(Bat& bat) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))bat.speedx = -bat_speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))bat.speedx = bat_speed;
	bat.shape.move(bat.speedx, 0.f);
	bat.speedx = 0.f;
}
void batReboundEdges(Bat& bat) {
	float batx = bat.shape.getPosition().x;
	float baty = bat.shape.getPosition().y;
	if (batx <= 0) bat.shape.setPosition(0.f, baty);
	if (batx >= width - bat_width)
		bat.shape.setPosition(width - bat_width, baty);

}
//ÿ¿–
void ballInit(Ball& ball) {
	ball.shape.setRadius(ballradius);
	ball.shape.setFillColor(ballColor);
	ball.shape.setPosition(const int (bat_start_pos));//ball_start_pos
	ball.ball_speed = 0.f;
}
void drawGame(sf::RenderWindow& window, Ball ball) {
	window.clear();
	window.draw(ball.shape);
	window.display();
}

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
void updateGame(Bat& bat) {
	batControl(bat);
	batReboundEdges(bat);

}

void checkCollision() {}

void drawGame(sf::RenderWindow& window, Bat bat, Ball ball) {
	window.clear();
	window.draw(bat.shape);
	window.display();

}
