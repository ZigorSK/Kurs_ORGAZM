#include "View.h"

int Vie::find_middle_time_pipeline()
{
	int N = obg.get_num();

	int *array_of_val = nullptr;
	array_of_val = new int[N];

	RenderWindow window(VideoMode(1366, 768), "Diagram of cycles of the pipeline");
	Image myBackground;
	myBackground.loadFromFile("pic.png");

	Texture myTexture;
	myTexture.loadFromImage(myBackground);
	//system("pause");
	//Создаем спрайт, загружаем в него текстуру, устанавливаем положение
	Sprite mySprite;
	mySprite.setTexture(myTexture);
	mySprite.setPosition(0, 0);

	ofstream file_ptr_outPut("Result.txt", ios::out);

	int val = 0;
	file_ptr_outPut << N << " циклов прогона конвеера" << endl << endl;

	int count = 0;
	//Вычисление значений колл-ва тактов для i-го прогона конвейера
	for (int i = 0; i < N; i++)
	{
		val = obg.find_pipeline_comand_time(i) - 2;
		array_of_val[i] = val;
		count += val;
		//cout << setw(3) << val << " тактов для " << i + 1 << "-го прогона конвеера. " << endl;
		file_ptr_outPut << setw(3) << val << " тактов для " << i + 1 << "-го прогона конвеера. " << endl;//Документированиев файл Result.txt
		cout<< setw(3) << val << " тактов для " << i + 1 << "-го прогона конвеера. " << endl;
	}
	//создаем массив точек, по которым будут рисоваться линии:
	sf::VertexArray lines(sf::Lines, 2 /*количество точек*/);
	//далее для каждой точки указываем цвет:
	lines[0].color = sf::Color::Blue;
	lines[1].color = sf::Color::Red;

	int width = (int)(1170 - 62) / N;//Ширина м-у 2 прогонами по оси х
	int height = (int)(535 - 250) / 20;
	//т. начала графика - (62,535)
	//конец оси х (1170, 535)
	//т. зн-я 20 -колл-во тактов (62, 250) 10 =(62, 393) 30 (62, 107)
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
	
		window.clear();
		window.draw(mySprite);
		//Рисуем всё тут
		for (int i = 0; i < N; i++)
		{
			//Рисуем прямоугольник(Столбец диаграммы)
			//left
			lines[0].position = sf::Vector2f(62 + (i * width), 535);
			lines[1].position = sf::Vector2f(62 + (i * width),535 -  height * array_of_val[i]);
			window.draw(lines);
			//top
			lines[0].position = sf::Vector2f(62 + (i * width), 535 - height * array_of_val[i]);//
			lines[1].position = sf::Vector2f(62 + ((i + 1) * width), 535 - height * array_of_val[i]);
			window.draw(lines);
			//right
			lines[0].position = sf::Vector2f(62 + ((i + 1) * width), 535);//
			lines[1].position = sf::Vector2f(62 + ((i + 1) * width), 535 - height * array_of_val[i]);
			window.draw(lines);
			//bot
			lines[0].position = sf::Vector2f(62 + (i * width), 535);//
			lines[1].position = sf::Vector2f(62 + ((i + 1) * width), 535);
			window.draw(lines);
		}

		window.display();
	}

	file_ptr_outPut << endl << "Среднее время выполнения команды конвеера: " << round(count / N + 0.5);

	file_ptr_outPut.close();
	
	return round(count / N + 0.5);

	
}