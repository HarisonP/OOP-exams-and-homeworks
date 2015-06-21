#pragma once
#include "Human.h"
class NormalHuman :
	public Human
{
public:
	NormalHuman(char * = " ", int = 3, int = 3, int = 3);
	NormalHuman(const NormalHuman&);
	NormalHuman& operator = (const NormalHuman&);
	void setPower(int);
	int getPower()const;
	void reducePower(int);
	void setLoyalty(int);
	int getLoyalty()const;
	void setName(char *);
	char* getName()const;
	void addFriend(NormalHuman);
	void removeFriend(char *);
	char* getSpecialAbility();
	int gradeRevenge();
	~NormalHuman();
private:
	char *name;
	int power, sizeOfFriends, loyalty;
	Human *friends;

};

