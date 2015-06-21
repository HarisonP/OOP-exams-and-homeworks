/*Encapsulation
  Abstraction
  Polymorphism
  Inheritance */

#include "Human.h"
#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;

void Human::setName(char* name)
{
	delete[] this->name;
	assert(this->name != NULL);
	strcpy(this->name, name);
	this->name = name;
}

void Human::setPower(int power)
{
	this->power = power;
}

void Human::setLoyalty(int loyalty)
{
	this->loyalty = loyalty;
}

char* Human::getName() const
{
	return this->name;
}

int Human::getPower() const
{
	return this->power;
}

int Human::getLoyalty() const
{
	return this->loyalty;
}

Human::Human(Human& other)
{
	this->name = other.name;
	this->power = other.power;
	this->friends = other.friends;
	this->loyalty = other.loyalty;
}

void Human::lowerPower(int p)
{
	if (this-power - p >= 0)
		this->power -= p;
}

Human::Human() :name(NULL), power(0), loyalty(0), friends(nullptr){}

Human::Human(char* name, int power, int loyalty) : name(name), power(power), loyalty(loyalty), friends(nullptr) {}


//could've done it in python.. 