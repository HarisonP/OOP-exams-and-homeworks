//enkapsulaciq, polimorfizum, nasledqvane, abstrakciq

#include<iostream>
#include<math.h>
using namespace std;

class Human{
protected:
	char* name;
	int power;
	int loyalty;
	Human* Friends= new Human[loyalty];
public:

    void Human::setName(char* _name){
		this->name = _name;
	}
	void Human::setPower(int _power){
		this->power = _power;
	}
	void Human::setLoyalty(int _loyalty){
		this->loyalty = _loyalty;
	}

	char* Human::getName() const{
		return this->name;
	}

	int Human::getPower() const{
		return this->power;
	}

	int Human::getLoyalty() const {
		return this->loyalty;
	}

	Human::Human(){

	}
	Human::Human(const Human &other){
		name = other.name;
		power = other.power;
		loyalty = other.loyalty;
	}

	Human::Human& operator=(Human const& other){
		this->name = other.name;
		this->power = other.power;
		this->loyalty = other.loyalty;
	}


	Human::~Human(){
		delete name;
		delete[] Friends;
	}


	bool Human::Low(){
		int n;
		this->power -= n;
		if (power < 0) return false;

	}

	void Human::addFriend(Human& chovek)
	{
		Human* Mates=new Human[loyalty + 1];
		for (int i = 0; i < loyalty+1; ++i){
			Mates[i] = Friends[i];
			Friends[loyalty + 1] = chovek;
		}

	}

	void Human::removeFriend(){
	
	}


	virtual char* Human::specialSkill();
			
};

class Normal_human:public Human{
protected:
	char* type;
public:
	Normal_human::Normal_human();

	void getSpecialskill(){

	}


	virtual void Normal_human::getRevange(){
		Human* sum = 0;
		for (int i = 0; i < loyalty; ++i){
			sum += Friends[i];
		}
	}

};

class Army{
protected:
	Human* Soldiers = new Human[100];
	int countSoldiers;
	Human* leader;

public:

	virtual void addSoldiers(Human* soldier);
	virtual void removeSoldiers(Human* soldier);
	virtual void addLeader(Human* one);
	virtual void Sum(Human* grade);

};


class Paid_army :public Army{
protected:
	int budjet;
	double salary;
public:
	Paid_army::Paid_army(){
	
	}
	Paid_army::Paid_army(const Paid_army &other){
		budjet = other.budjet;
		salary = other.salary;
	}

	Paid_army::Paid_army& operator=(Paid_army const& other){
		
		this->budjet = other.budjet;
		this->salary = other.salary;
	}


	Paid_army::~Paid_army(){
};

class Conscript_army :public Army{
protected:
	double salary;
public:
	Conscript_army::Conscript_army(){

	}
	Conscript_army::Conscript_army(const Conscript_army &other){
		salary = other.salary;
	}

	Conscript_army::Conscript_army& operator=(Conscript_army const& other){

		this->salary = other.salary;
	}

	Conscript_army::~Conscript_army(){
	};
};


class Targaryen :public Human{
protected:
	int years;
public:
	virtual void setName(char* _name);
	char* getName();
	void setPower(int _power);
	int getPoewr();
	void setLoyalty(int _loyalty);
	int getLoyalty(){
		return loyalty + years;
	}

};

class Stark :public Human{
protected:
	int years;
public:

	int setLoyalty(){
		return loyalty + years;
	}
};