#pragma once
#include "Human.h"
class Army :
	public Human
{

public:
	Army();
	Army(const Army &);
	Army& operator = (const Army&);
	virtual void addSoldier(Human);
	virtual void removeSoldier(char *);
	virtual void addLeader(Human &);
	virtual double getArmyGrade();
	virtual ~Army();

private:
	Human sold[100];
	int countSold;
	double grade;
	Human Leader;
};

