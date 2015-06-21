#include "Army.h"
#ifndef Paid_army_h
#define Paid_army_h

class Paid_army : public Army
{
private:
	int sum;
	int salary; 
public:
	Paid_army(int sum = 0) :Army(){ 
		this->salary = 0; 
		this->sum = sum; 
	};
	virtual void addLider(Human&  other)
	{
		Army::addLider(other);
	}
	virtual  int getGrade();
	int getSalary();
	


};
#endif Paid_army_h