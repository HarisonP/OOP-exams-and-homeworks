#ifndef NOMRALHUMAN_H
#define NORMALHUMAN_H
#include <iostream>
#include "Human.h"

class NormalHuman :	public Human{
public:
	NormalHuman(const char* name = "", int loyalty = 0, int strenght = 0) :Human(name, loyalty, strenght){}
	NormalHuman(const NormalHuman& other) :Human(other){}
	NormalHuman& operator=(const NormalHuman& other){
		if (this != &other){
			Human::operator=(other);
		}
		return *this;
	}

	virtual char* getSpecialSkill() const{
		return "None";
	}
	virtual int getRevenge(){
		int result = 0;
		for (int i = 0; i < size; i++){
			result += friends[i]->getStrenght();
		}
		return result;
	}
	virtual void addFriends(const Human& newFriend){
		if (!strcmp(newFriend.getSpecialSkill(), "None")){
			Human::addFriends(newFriend);
		}
	}
	virtual Human* clone() const{
		return new NormalHuman(*this);
	}

	virtual void setName(const char* name){
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	virtual void setLoyalty(int loyalty){
		this->loyalty = loyalty;
	}

};
#endif
