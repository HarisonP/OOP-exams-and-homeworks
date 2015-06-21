#include "Human.h"
#ifndef Normal_human_h
#define Normal_human_h
class Normal : public Human

{

public:

	virtual char* special() const{
		return "none";
	}
	virtual int revenge()
	{
		int sum = 0; 
		for (int i = 0; i < friendnum; i++)
		{
			sum += friends[i]->getPower();
		}
		return sum; 
	}
	virtual void addFriend(Normal&);
	Normal(const char* name = " ", int power = 0, int loql = 0) :Human(name, power, loql){};

};
#endif Normal_human_h