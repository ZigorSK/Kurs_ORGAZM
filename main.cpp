/*
������ �������� ������� ���������� �������. �������� ���������� �������� � ����
��������� �������: ������ � ���������� ���� ��������, ������� ������� ��������, �������
������� ��������, ���������� ����������, ������ ������ (�� ������ ������� ��������). ����������
���� �������� ����������� �� 1 ����. ������ ������� ������ ��������� � ��������. �������
��������� ������� �������� ����������� � ���������. ����������� ����, ��� ��� ������� ��������
������������ ����������� ��������� P1 (0.9; 0.8; 0.6). ����� ��������� � �������� 1 ����. �����
��������� � ������ N ������ (2, 5, 10). � ��� �������� � ������� �������� ���� ����� ������.
�������������� ��� ���� ������. ���������� ���������� ��� ������ ������� ���� ����������� ��
1 ����, ���������� ���������� ��� ������ ������� ���� ����������� �� M ������ (4, 8, 16). �����������
����, ��� ������� ������� �������� �������� ������� ���� P2 (0.9; 0.7; 0.5). � ���� ������ �������
����� ����������� ������ �� ������ ���� �������� � ��������� � ������ ��� ������ ��� ������ �
������ ������
*/
#include<iostream>
#include"View.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	Vie obg;

	system("cls");
	obg.find_middle_time_pipeline();

	system("pause");
	return 0;
}
