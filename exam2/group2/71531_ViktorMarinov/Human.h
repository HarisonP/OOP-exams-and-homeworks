#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>

class Human{
protected:
	char* name;
	int loyalty,
		strenght;
	Human** friends;
	int size, capacity;
public:
	Human(const char* name = "", int loyalty = 0, int strenght = 0):name(NULL){
		setName(name);
		setLoyalty(loyalty);
		setStr(strenght);
		this->friends = new Human*[loyalty];
		this->capacity = loyalty;
	}
	virtual ~Human() = 0{
		delete[] this->name;
		for (int i = 0; i < size; i++){
			delete friends[i];
		}
		//delete[] this->friends;
	}
	Human(const Human& other):name(NULL){
		setName(other.name);
		setLoyalty(other.loyalty);
		setStr(other.strenght);
		this->capacity = other.loyalty;
		this->friends = other.friends;
	}
	Human& operator=(const Human& other){
		if (this != &other){
			setName(other.name);
			setLoyalty(other.loyalty);
			setStr(other.strenght);
			this->capacity = other.loyalty;
			this->friends = other.friends;
		}
		return *this;
	}

	virtual void setName(const char* name){
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	virtual void setLoyalty(int loyalty){
		this->loyalty = loyalty;
	}
	void setStr(int str){
		strenght = str;
	}

	virtual int getLoyalty() const{
		return loyalty;
	}
	int getStrenght() const{
		return strenght;
	}
	char* getName() const{
		return this->name;
	}

	void StrenghtDown(int n){
		if (strenght - n >= 0)
			this->strenght -= n;
		else
			strenght = 0;
	}

	virtual void addFriends(const Human& newFriend){
		if (size == capacity){
			return;
		}
		friends[size++] = newFriend.clone();
	}
	virtual Human* clone() const = 0;
	virtual char* getSpecialSkill() const = 0;
	virtual int getRevenge() = 0;
};

#endif