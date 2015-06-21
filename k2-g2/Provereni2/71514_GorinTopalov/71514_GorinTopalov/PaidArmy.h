#pragma once
#include "Army.h"
class PaidArmy :
	virtual public Army
{
public:
	PaidArmy();
	bool operator >(const PaidArmy&);
	PaidArmy(const PaidArmy&);
	void addSoldier(Human);
	void removeSoldier(char *);
	void addLeader(Human &);
	double getArmyGrade();
	double getSalary();
	double getLeaderSalary();
	void addLeader(Human);
	void setAll(const PaidArmy&);
	double getArmyPower();
	~PaidArmy();
private:
	Human sold[100];
	int countSold;
	double salary,armyGrade, budge, leaderSalary,grade,armyPower;
	Human Leader;
};

