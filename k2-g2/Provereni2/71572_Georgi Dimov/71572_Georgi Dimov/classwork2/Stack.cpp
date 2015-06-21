#include "Stack.h"
int Stack::getLoql() const
{
	return Human::getLoql() + friendnum;
}
int Stack::getAge() const
{
	return this->age;
}
void Stack::setAge(int)
{
	this->age = age;
}
void Stack::addFriend(Stack& other)
{
	friends[friendnum] = new Stack;
	friends[friendnum] = &other;
	friendnum++;
}


int Stack::revenge()
{
	int sum = 0;
	for (int i = 0; i < friendnum; i++)
	{
		sum += friends[i]->getPower();
	}
	return 2 * sum;
}
char*   Stack::special()const

{
	return "ice";
}




