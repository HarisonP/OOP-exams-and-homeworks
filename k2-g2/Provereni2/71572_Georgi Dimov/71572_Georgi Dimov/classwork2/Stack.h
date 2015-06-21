#include "Human.h"
#ifndef Stack_h
#define Stack_h
class Stack :virtual public Human
{
private:
	int age; 
public:
	virtual int getLoql() const;
	int getAge() const;
	void setAge(int);
	virtual void addFriend(Stack&);
	virtual int revenge();
	virtual char* special() const;
	Stack(const char* name = " ", int power = 0, int loql = 0, int age = 0) :Human(name, power, loql){ setAge(age); };
};
#endif Stack_h