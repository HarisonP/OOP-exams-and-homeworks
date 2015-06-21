#ifndef	TARGARYEN_H
#define TARGARYEN_H
#include "Targaryen.h"
#include "Stark.h"
class TargaryenStark : public Targaryen, public Stark{
public:
	TargaryenStark(const char* name = "", int loyalty = 0, int strenght = 0, int age = 0)
		: Human(name, loyalty, strenght), Stark(name, loyalty, strenght),
		Targaryen(name, loyalty, strenght, age){}
	TargaryenStark(const TargaryenStark& other) :Human(other), Stark(other), Targaryen(other){}
	TargaryenStark& operator=(const TargaryenStark& other){
		if (this != &other){
			Stark::operator=(other);
			Targaryen::operator=(other);
		}
		return *this;
	}

	virtual int getLoyalty() const{
		return loyalty + size + age;
	}
	virtual void setLoyalty(int loyalty){
		this->loyalty = loyalty - size - age;
	}
	virtual void setName(const char* name){
		delete[] this->name;
		char* newName = "Snow";
		strcat(newName, name);
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
	virtual char* getSpecialSkill() const{
		char* res = "I am the son of ";
		strcat(res, Stark::getSpecialSkill());
		strcat(res, " and ");
		strcat(res, Targaryen::getSpecialSkill());
		strcat(res, "!");
		return res;
		
	}
	virtual void addFriends(const Human& newFriend){
		if (size == capacity){
			return;
		}
		friends[size++] = newFriend.clone();
	}
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
};

#endif