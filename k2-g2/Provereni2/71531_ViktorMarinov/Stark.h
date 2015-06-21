#ifndef STARK_H
#define STARK_H
#include "Human.h"
class Stark : virtual public Human{

	int numberOfTargFriends;
public:
	Stark(const char* name = "", int loyalty = 0, int strenght = 0)
		: Human(name, loyalty, strenght){
		this->age = age;
		numberOfTargFriends = 0;
	}
	Stark(const Stark& other) :Human(other){}
	Stark& operator=(const Stark& other){
		if (this != &other){
			Human::operator=(other);
		}
		return *this;
	}

	virtual int getLoyalty() const{
		return loyalty + size;
	}
	virtual void setLoyalty(int loyalty){
		this->loyalty = loyalty - size;
	}
	virtual char* getSpecialSkill() const{
		return "Ice";
	}
	void addFriends(const Human& newFriend){
		if (if (!strcmp(newLeader.getSpecialSkill, "Ice") || !strcmp(newLeader.getSpecialSkill, "None"))){
			Human::addFriends(newFriend);
		}
		else if (numberOfTargFriends == 0){
			Human::addFriends(newFriend);
			numberOfTargFriends = 1;
		}


};
	virtual int getRevenge(){
		int result = 0;
		for (int i = 0; i < size; i++){
			if (!strcmp(friends[i]->getSpecialSkill, "Ice"))
				result += 3 * friends[i]->getStrenght();
			if (!strcmp(friends[i]->getSpecialSkill, "Fire"))
				result += 2 * friends[i]->getStrenght();
			else
				result += friends[i]->getStrenght();
		}
		return result;
	}
	virtual void setName(const char* name){
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}


#endif