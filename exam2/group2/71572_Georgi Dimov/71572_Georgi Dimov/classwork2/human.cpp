#include "Human.h"
#include <iostream>
#include <cassert>
using namespace std;

void Human::setName(const char* name)
{
	int length = strlen(name) + 1; 
	this->name = new char[length];
	strcpy_s(this->name, length, name);
}
char* Human::getName() const
{
	return name; 
}
void  Human::lowPower(int x)
{
	this->power -= x;
	assert(power >= 0);
}
void  Human::addFriend(Human& other)
{
	friends[friendnum] = &other;
	friendnum++; 
}
void Human::delFriend(const char* name)
{
	for (int i = 0; i < friendnum; i++)
	{
		if (strcmp(friends[i]->name , name)==0)
		{
			delete friends[i];
		}
	}
}

Human::Human(const char* name, int power, int loql)
{
	setName(name);
	this->power = power;
	this->loql = loql;
	friendnum = 0; 
	friends = new Human*[loql];
	for (int i = 0; i < loql; i++)
	{
		friends[i] = NULL;
	}
}
Human :: ~Human()
{
	for (int i = 0; i < friendnum; i++)
	{
		delete friends[i];
	}
	delete[] friends;
}


int Human :: getPower() const
{
	return this->power;
}

int Human::getLoql() const
{
	return this->loql;

}
