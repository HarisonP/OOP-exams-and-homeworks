//Четирите принципа са: енкапсулация,наследяване,абстракция,полиморфизъм

#include<iostream>
using namespace std;
class Human
{
protected:
	char* name;
	int power;
	int loyalty;
	Human* friends;
public:
	
	 Human::Human()
	{
		Human* friends = new Human[loyalty];
	}
     Human::Human(Human const &other)
	{
		name = other.name;
		power = other.power;
		loyalty = other.loyalty;
	}
	 Human::Human &operator=(Human const &other)
	 {
		 this->name = other.name;
		 this->power = other.power;
		 this->loyalty = other.loyalty;
	 }
	 Human::Human()
	 {
		 delete[] name;
	 }
	 void Human::setName(char* name1)
	 {
		 name = name1;
	 }
	 void Human::setPower(int power1)
	 {
         power = power1;
	 }
	 void Human::setLoyalty(int loyalty1)
	 {
		 loyalty = loyalty1;
	 }
	 char* Human::getName()const
	 {
		 return this->name;
	 }
	 int Human::getPower()const
	 {
		 return this->power;
	 }
	 int Human::getLoyalty()const
	 {
		 return this->loyalty;
	 }
	 int Human::getPowerLow()
	 {
		 int N;
		 if (power >= N)  power -= N;
		 return power;
	 }
	 virtual char* getSpecialUm();
 	 virtual void Human::addFriends(Human* p)
	 {
		 Human* friends1=new Human[loyalty + 1];
		 for (int i = 0; i < loyalty + 1; i++)
			 p = &friends1[loyalty + 1];
      }
	virtual void removeFriends(Human* p)
	 {
		delete[] p;
	 }
	virtual void getPoint();
};

class Normal_human :public Human
{
protected:
	Normal_human* friends;
public:
	Normal_human::Normal_human()
	{
		Normal_human* friends = new Normal_human[loyalty];
	}
	Normal_human::Normal_human();

	char* getSpeacialUm()
	{
		return "NONE";
	}
	void addFriends(Normal_human* fr)
	{
		Normal_human* friends2= new Normal_human[loyalty + 1];
		for (int i = 0; i < loyalty + 1; i++)
			fr = &friends2[loyalty + 1];
      }
	void getPoint();
};

class Army :public Human
{
protected:
	Human* soldiers = new Human[100];
	int br_soldiers;
	Human* lider;
public:
	Army::Army();
	Army::Army(Army const&other);
	Army::Army &operator=(Army const &other);
	Army::Army();
	virtual void addSoldier(Human* soldier);
	virtual void removeSoldier(Human* soldier);
	virtual void addLider(Human* lider);
	virtual int getArmyPoints(Human* grade);

};

class Paid_army :public Army
{
private:
	int budjet;
	double zaplata;
public:
	Paid_army::Paid_army(int budjet1, double zaplata1)
	{
		this->budjet = budjet1;
		
	
	}
	Paid_army::~Paid_army();
	void addLider(Normal_human* lider)
	{

	}
	int getArmyPoints()
	{
		
	}
	Paid_army::Paid_army &operator>(Army* const &other )
	{

	}

};

class Conscript_army :public Army
{
public:
	Conscript_army::~Conscript_army();
	Conscript_army::Conscript_army &operator>(Conscript_army const &other)
	{

	}
	Conscript_army::~Conscript_army();
	void addLider();
	int getArmyPoints();

};

class Targaryen :public Human
{
private:
	int age;
public:
	Targaryen::Targaryen();
	Targaryen::Targaryen(Targaryen const &other);
	Targaryen::Targaryen &operator=(Targaryen &other);
	Targaryen::~Targaryen();
	void Targaryen::setName(char*);
	void Targaryen::setPower(int);
	void Targaryen::setLoyalty(int);
	char* Targaryen::getName()const;
	int Targaryen::getPower()const;
	int Targaryen::getLoyalty()const
	{
		return this->loyalty + age;
	}

	char* Targaryen::getSpecialUm()
	{
		return "fire";
	}
	void Targaryen::addFriends(Targaryen* friends);
	void Targaryen::getPoint();

};

class Stark :public Human
{
private:
	int age;
public:
	Stark::Stark();
	Stark::Stark(Stark const &other);
	Stark::Stark &operator=(Stark const &other);
	Stark::~Stark();
	void Stark::setName(char*);
	void Stark::setPower(int);
	void Stark::setLoyalty(int);
	char* Stark::getName()const;
	int Stark::getPower()const;
	int Stark::getLoyalty()const;
	char* Stark::getSpecialUm()
	{
		return "ice";
	}



};