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
	//������� ������, ��������� � ���� ��������, ������������� ���������
	Sprite mySprite;
	mySprite.setTexture(myTexture);
	mySprite.setPosition(0, 0);

	ofstream file_ptr_outPut("Result.txt", ios::out);

	int val = 0;
	file_ptr_outPut << N << " ������ ������� ��������" << endl << endl;

	int count = 0;
	//���������� �������� ����-�� ������ ��� i-�� ������� ���������
	for (int i = 0; i < N; i++)
	{
		val = obg.find_pipeline_comand_time(i) - 2;
		array_of_val[i] = val;
		count += val;
		//cout << setw(3) << val << " ������ ��� " << i + 1 << "-�� ������� ��������. " << endl;
		file_ptr_outPut << setw(3) << val << " ������ ��� " << i + 1 << "-�� ������� ��������. " << endl;//����������������� ���� Result.txt
		cout<< setw(3) << val << " ������ ��� " << i + 1 << "-�� ������� ��������. " << endl;
	}
	//������� ������ �����, �� ������� ����� ���������� �����:
	sf::VertexArray lines(sf::Lines, 2 /*���������� �����*/);
	//����� ��� ������ ����� ��������� ����:
	lines[0].color = sf::Color::Blue;
	lines[1].color = sf::Color::Red;

	int width = (int)(1170 - 62) / N;//������ �-� 2 ��������� �� ��� �
	int height = (int)(535 - 250) / 20;
	//�. ������ ������� - (62,535)
	//����� ��� � (1170, 535)
	//�. ��-� 20 -����-�� ������ (62, 250) 10 =(62, 393) 30 (62, 107)
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
		//������ �� ���
		for (int i = 0; i < N; i++)
		{
			//������ �������������(������� ���������)
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

	file_ptr_outPut << endl << "������� ����� ���������� ������� ��������: " << round(count / N + 0.5);

	file_ptr_outPut.close();
	
	return round(count / N + 0.5);

	
}