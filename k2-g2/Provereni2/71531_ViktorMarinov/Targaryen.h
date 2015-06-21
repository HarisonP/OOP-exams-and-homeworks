#ifndef Targaryen_H
#define Targaryen_H
#include "Human.h"
class Targaryen :virtual public Human{
protected:
	int age;
public:
	Targaryen(const char* name = "", int loyalty = 0, int strenght = 0, int age = 0)
		: Human(name, loyalty, strenght){
		this->age = age;
	}
	Targaryen(const Targaryen& other) :Human(other){}
	Targaryen& operator=(const Targaryen& other){
		if (this != &other){
			Human::operator=(other);
		}
		return *this;
	}

	virtual int getLoyalty() const{
		return loyalty + age;
	}
	virtual char* getSpecialSkill() const{
		return "Fire";
	}
	virtual void addFriends(const Human& newFriend){
		if (!strcmp(newFriend.getSpecialSkill(), "Fire")){
			Human::addFriends(newFriend);
		}
	}
	virtual int getRevenge(){
		int result = 0;
		for (int i = 0; i < size; i++){
			result += friends[i]->getStrenght();
		}
		return 2*result;
	}

	virtual void setName(const char* name){
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	virtual void setLoyalty(int loyalty){}

};

#endif