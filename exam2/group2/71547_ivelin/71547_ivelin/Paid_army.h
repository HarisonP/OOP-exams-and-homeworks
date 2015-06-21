#ifndef Paid_army_h
#define Paid_army_h
#include "Army.h"
#include "Normal_human.h"

class Paid_army : virtual public Army
{
private:
	int budget;
	double soldierSalary;
	int Paid_ArmyValue;
	


public:
	void addLeader(Normal_human&);
	void ArmyValue();
	void addSoldier();
};

		


#endif