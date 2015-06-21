#include "Human.h"
#ifndef Targaryen_h
#define Targaryen_h
class Targaryen : public Human
{
private:
	int age;
public:

	virtual int getLoql() const;
	int getAge() const;
	void setAge(int);
	virtual void addFriend(Targaryen&);
	virtual int revenge();
	virtual char* special() const ;
	Targaryen(const char* name = " ", int power = 0, int loql = 0, int age = 0) :Human(name, power, loql){ setAge(age); };
};

#endif Targaryen_h