#pragma once
#include<iostream>
#include<cassert>
class Human
{
public:
	Human(char * =" ",int =3,int=3,int=3);
	Human(const Human&);
	Human& operator = (const Human&);
	virtual void setPower(int);
	virtual int getPower()const;
	virtual void reducePower(int);
	virtual void setLoyalty(int);
	virtual int getLoyalty()const;
	virtual void setName(char *);
	virtual char* getName()const;
	virtual void addFriend(Human);
	virtual void removeFriend(char *);
	virtual int gradeRevenge();
	virtual ~Human();

private:
	char *name;
	int power,sizeOfFriends, loyalty;
	Human *friends;

};

