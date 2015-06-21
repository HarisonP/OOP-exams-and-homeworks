#include "Targaryen.h"


int Targaryen::getLoql() const
{
	return Human::getLoql() + getAge();
}
int Targaryen::getAge() const
{
	return this->age;
}
void Targaryen::setAge(int)
{
	this->age = age; 
}
void Targaryen::addFriend(Targaryen& other)
{
	friends[friendnum] = new Targaryen; 
	friends[friendnum] = &other;
	friendnum++;
}


int Targaryen::revenge()
{
	int sum = 0;
	for (int i = 0; i < friendnum; i++)
	{
		sum += friends[i]->getPower();
	}
	return 2 * sum ;
}
 char*   Targaryen ::special()const

{
	return "fire";
}