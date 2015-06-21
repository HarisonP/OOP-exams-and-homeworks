#include "Army.h"
#ifndef Conscript_army_h
#define Conscript_army_h
class Conscript_army :public Army
{
public:
	virtual void addLider(Human&  other)
	{
		Army::addLider(other);
	}
	virtual  int getGrade();
	Conscript_army() :Army(){};
};
#endif Conscript_army_h