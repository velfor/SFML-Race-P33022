#include "settings.h"
#include "road.h"

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

	RoadLayer grass1, grass2;
	roadLayerInit(grass1, Vector2f{ 0.f,0.f }, "grass.jpg", 0.f);
	roadLayerInit(grass2, Vector2f{ 0.f,-WINDOW_HEIGHT }, "grass.jpg", 0.f);


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
		// Отрисовка окна
		window.clear();
		roadLayeDraw(window, grass1);
		roadLayeDraw(window, grass2);
		window.display();
	}

	return 0;
}