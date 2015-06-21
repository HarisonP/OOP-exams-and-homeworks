#include "Human.h"
#ifndef Army_h
#define Army_h

class Army
{
public:
	virtual void addSoldier(Human&);
	virtual void addLeader(Human&);
	void removeSoldier(char*);
	int getArmyGrade();


private:
	int numSoldiers;
	Human* soldiers[100];
	Human* leader;


};

#endif 