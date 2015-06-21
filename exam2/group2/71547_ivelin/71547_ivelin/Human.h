#ifndef Human_h
#define Human_h

class Human
{
public:
	Human();
	Human(char*, int, int);
	Human(Human&);
	void setName(char*);
	void setPower(int);
	void setLoyalty(int);
	char getName() const;
	int getPower() const;
	int getLoyalty() const;
	void lowerPower(int n);
	virtual void getRevenge() = 0;
	void addFriend(Human&);
	virtual char* specialAbility() = 0;
	void removeFriend(char*);
	Human& operator=(const Human&);



private:
	char* name;
	int power;
	int loyalty;
	Human* friends;
	
};

#endif