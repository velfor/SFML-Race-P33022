#include "settings.h"
#include "road.h"
#include "player.h"
#include "obstacle.h"

using namespace sf;

int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setPosition(Vector2i{ (1920 - (int)WINDOW_WIDTH) / 2, 0 });
	window.setFramerateLimit(FPS);

	RoadLayer grass1, grass2, road1, road2;
	roadLayerInit(grass1, Vector2f{ 0.f,0.f }, "grass.jpg", 0.f);
	roadLayerInit(grass2, Vector2f{ 0.f,-WINDOW_HEIGHT }, "grass.jpg", 0.f);
	roadLayerInit(road1, Vector2f{ 100.f,0.f }, "road.jpg", 100.f);
	roadLayerInit(road2, Vector2f{ 100.f,-WINDOW_HEIGHT }, "road.jpg", 100.f);
	Player player;
	playerInit(player);
	Obstacle obs1;
	obstacleInit(obs1, "car.png");

	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		//Update
		roadLayerUpdate(grass1);
		roadLayerUpdate(grass2);
		roadLayerUpdate(road1);
		roadLayerUpdate(road2);
		playerUpdate(player);
		obstacleUpdate(obs1);
		// Проверка столкновений игрока и препятствий
		FloatRect playerHitBox = player.sprite.getGlobalBounds();
		FloatRect obs1HitBox = obs1.sprite.getGlobalBounds();
		if (playerHitBox.intersects(obs1HitBox)) {
			//действия при столкновении
		}
		// Отрисовка окна
		window.clear();
		roadLayeDraw(window, grass1);
		roadLayeDraw(window, grass2);
		roadLayeDraw(window, road1);
		roadLayeDraw(window, road2);
		playerDraw(window, player);
		//obstacleDraw(window, obs1);
		window.display();
	}

	return 0;
}