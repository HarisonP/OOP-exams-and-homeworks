#pragma once
#include "Army.h"
class Conscript_army :
	virtual public Army
{
public:
	Conscript_army();
	void addLeader(Human &);
	double getArmyGrade();
	bool operator >(const Army&);

	/*
	�������� �� �����

		������ ��� ���� �� ���� �� �������� ���

		������� �� ������ �� �������

�������� �� ����� ����(��������� �� ������ * ���� �� ��������� �� ����� ������) + ���� �� ������ �� ����� ������

		(������ � ������!)

		�������� >

		�������� 2 ����� ������ �������� ��(���� �� �������� �������� ��� �����)

		�� �� ��������� ������ �������� � ����� ���������� �� ���������� ������ ������.*/



	~Conscript_army();
private:
	Human sold[100];
	int countSold;
	double salary, armyGrade, budge, leaderSalary, grade, armyPower;
	Human Leader;
};

