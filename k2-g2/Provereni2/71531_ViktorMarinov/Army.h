#ifndef ARMY_H
#define ARMY_H
#include "Human.h"
#include <iostream>

class Army{
protected:
	Human* arr[100];
	int size;
	Human* leader;
public:
	Army(){
		for (size_t i = 0; i < 100; i++){
			arr[i] = NULL;
		}
		size = 0;
		leader = NULL;
	}
	virtual ~Army(){
		for (size_t i = 0; i < 100; i++){
			delete arr[i];
		}
		delete arr; //?? ? ?????????
		delete leader;
	}

	void add(const Human& newHuman){
		if (size == 100)
			return;
		arr[size++] = newHuman.clone();

	}
	void remove(char* name){
		for (size_t i = 0; i < size; i++){
			if (!strcmp(arr[i]->getName, name)){
				delete arr[i];
				for (size_t i = 0; i < size - 1; i++){
					arr[i] = arr[i + 1];
				}
				size--;
				arr[size] = NULL;
			}
		}
	}
	virtual void makeLeader(const Human& newLeader);
	virtual int getGrade();


	bool operator>(const Army& other){
		return this->getGrade > other.getGrade;
	}
};

#endif