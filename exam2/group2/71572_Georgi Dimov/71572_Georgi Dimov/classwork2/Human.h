#ifndef Human_h
#define Human_h
class Human
{

private:
	char* name;
	int power;
	int loql;
	char* skill;
protected:
	Human** friends;
	int friendnum;
public:
	
	void setName(const char*);
	char* getName() const;
	void lowPower(int);
	int getPower() const;
	virtual int getLoql() const; 
	virtual void addFriend(Human&) ;
	virtual void delFriend(const char*);
	virtual char* special() const = 0; 
	virtual int revenge() = 0 ;
	Human(const char* = " ", int = 0, int = 0);
	virtual ~Human();

};
#endif Human_h