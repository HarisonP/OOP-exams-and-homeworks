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
	Добавяне на лидер

		Лидера тук може да бъде от всякакъв тип

		Взимане на оценка на армията

Оценката се смята като(Лоялноста на лидера * сума от лоялноста на всеки войник) + сума от силата на всеки войник

		(лидера е войник!)

		Оператор >

		Сравнява 2 армии според оценката им(може да сравнява различен тип армии)

		Да се реализира голяма четворка и други необходими за следващите задачи методи.*/



	~Conscript_army();
private:
	Human sold[100];
	int countSold;
	double salary, armyGrade, budge, leaderSalary, grade, armyPower;
	Human Leader;
};

