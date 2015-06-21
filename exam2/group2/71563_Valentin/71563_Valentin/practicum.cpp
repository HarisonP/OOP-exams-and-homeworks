//1 Наследяване
//2 Абстракция
//3 Енкапсулация
//4 Полиморфизъм

#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class Human{
protected:
	char* name;
	int power;
	int loyalty;
	Human** friends;
	int friendsCount;
	void cpy(char* name, int power, int loyalty, int friendsCount = 0, Human* const* friends = NULL){
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		assert(this->name != NULL);
		strcpy_s(this->name, length, name);
		this->power = power;
		this->loyalty = loyalty;
		for (int i = 0; i < loyalty; i++)
		{
			this->friends[i] = friends[i];
		}
		this->friendsCount = friendsCount;
	}
public:	
	char* getName(){
		return this->name;
	}
	int getPower(){
		return this->power;
	}
	int getLoyalty(){
		return this->loyalty;
	}
	void setName(char* name){
		delete[] this->name;
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		assert(this->name != NULL);
		strcpy_s(this->name, length, name);
	}
	void setPower(int power){
		this->power = power;
	}
	void setLoyalty(int loyalty){
		this->loyalty = loyalty;
	}
	int powerDecreasing(int n){
		this->power -= n;
		if (this->power < 1){
			return 1;
		}
		return this->power;
	}
	virtual char* getSkill() = 0;
	virtual int getGrade() = 0;
	bool addFriend(Human& other){
		if (loyalty > friendsCount){
			this->friends[friendsCount++] = &other;
			return true;
		}
		return false;
	}
	bool removeFriend(char* name){
		int index = -1;
		bool del = false;
		for (int i = 0; i < loyalty; i++){
			if (strcmp(name, friends[i]->getName()) == 0){
				index = i;
				del = true;
				break;
			}
		}
		if (del){
			Human **temp = new Human*[loyalty - 1];
			for (int i = 0; i < index; i++){
				temp[i] = friends[i];
			}
			for (int i = index; i < loyalty- 1; i++){
				temp[i] = friends[i + 1];
			}
			for (int i = 0; i < loyalty - 1; i++){
				friends[i] = temp[i];
			}
			delete[] temp;
			loyalty--;

		}
		return del;
	}
	
	Human(char* name = "", int power = 0, int loyalty = 0){
		cpy(name, power, loyalty);
	}
	Human(const Human& other){
		cpy(other.name, other.power, other.loyalty, other.friendsCount, other.friends);
	}
	Human& operator=(Human& other){
		if (this != &other){
			delete[] this->name;
			cpy(other.name, other.power, other.loyalty, other.friendsCount, other.friends);
		}
		return *this;
	}
	virtual ~Human(){
		delete[] this->name;
	}
};
class NormalHuman :public Human{
public:
	virtual char* getSkill(){
		return "none";
	}
	virtual int getGrade(){
		int sum = 0;
		for (int i = 0; i < loyalty; i++){
			sum += friends[i].getPower();
		}
		return sum;
	}
	NormalHuman(char* name = "", int power = 0, int loyalty = 0) : Human(name, power, loyalty){}
	NormalHuman(const NormalHuman& other) : Human(other){}
	NormalHuman& operator=(const NormalHuman& other){
		if (this != &other){
			Human::operator=(other);
		}
		return *this;
	}
};
class Army{
private:
	Human* soldiers[100];
	int countSoldiers;
	Human* lider;
	void cpy(int countSoldiers, Human* const* soldiers = NULL, Human* lider = NULL){
		this->countSoldiers = countSoldiers;
		for (int i = 0; i < countSoldiers; i++){
			this->soldiers[i] = soldiers[i];
		}
		this->lider = lider;
	}
public:
	Army(int countSoldiers = 0){
		cpy(countSoldiers);
	}
	Army(const Army& other){
		cpy(other.countSoldiers, other.soldiers, other.lider);
	}
	Army& operator=(const Army& other){
		if (this != other){
			cpy(other.countSoldiers, other.soldiers, other.lider);
		}
		return *this;
	}
	virtual ~Army(){
		delete[] soldiers;
		delete[] lider;
	}

	bool addSoldier(Human& other){
		if (countSoldiers < 100){
			this->soldiers[countSoldiers++] = &other;
			return true;
		}
		return false;
	}
	bool removeSoldier(char* name){
		int index = -1;
		bool del = false;
		for (int i = 0; i < loyalty; i++){
			if (strcmp(name, soldiers[i]->getName()) == 0){
				index = i;
				del = true;
				break;
			}
		}
		if (del){
			Human **temp = new Human*[countSoldiers - 1];
			for (int i = 0; i < index; i++){
				temp[i] = soldiers[i];
			}
			for (int i = index; i < countSoldiers - 1; i++){
				temp[i] = soldiers[i + 1];
			}
			for (int i = 0; i < countSoldiers - 1; i++){
				soldiers[i] = temp[i];
			}
			delete[] temp;
			countSoldiers--;

		}
		return del;
	}
	virtual int getGradeOfArmy() = 0;
	virtual char* getType() = 0;

};
class PaidArmy : public Army{
private:
	int budget;
	int liderSalary;
	void cpy(int budget, int liderSalary){
		this->budget = budget;
		this->liderSalary = liderSalary;
	}
public:
	
	PaidArmy(int countSoldiers = 0, int budget = 0, int liderSalary = 0) : Army(countSoldiers){
		cpy(budget, liderSalary);
	}
	~PaidArmy(){}
	PaidArmy(const PaidArmy& other) : Army(other) {
		cpy(other.budget, other.liderSalary)
	}
	PaidArmy& operator=(const PaidArmy& other){
		if (this != &other){
			Army::operator=(other);
			cpy(other.budget, other.liderSalary);
		}
		return *this;
	}
	double salary(){
		return (20 / 100) * liderSalary;
	}
	virtual int getGradeOfArmy(){
		return budget + liderSalary;
	}
	virtual char* getType(){
		return "PaidArmy";
	}
};
class ConscriptArmy : public Army{
private:
	int budget;
	int liderSalary;				
	void cpy(int budget, int liderSalary){
		this->budget = budget;
		this->liderSalary = liderSalary;
	}
public:
	virtual int getGradeOfArmy(){
		return budget + liderSalary;
	}
	virtual char* getType(){
		return "ConscriptArmy";
	}
	ConscriptArmy(int countSoldiers = 0, int budget = 0, int liderSalary = 0) : Army(countSoldiers){
		cpy(budget, liderSalary);
	}
	~ConscriptArmy(){}
	ConscriptArmy(const ConscriptArmy& other) : Army(other) {
		cpy(other.budget, other.liderSalary)
	}
	ConscriptArmy& operator=(const ConscriptArmy& other){
		if (this != &other){
			Army::operator=(other);
			cpy(other.budget, other.liderSalary);
		}
		return *this;
	}
	double salary(){
		return (20 / 100) * liderSalary;
	}
};
class Targaryen : virtual public Human{
private:
	int years;
	char* name;
public:
	virtual char* getSkill(){
		return "fire";
	}
	Targaryen(int years = 0, char* name = "", int power = 0, int loyalty = 0) : Human(name, power, loyalty){
		this->years = years;
	}
	Targaryen& operator=(const Targaryen& other){
		if (this != &other){
			Human::operator=(other);
			years = other.years;
		}
		return *this;
	}
	Targaryen(const Targaryen& other) : Human(other){
		years = other.years;
	}
	~Targaryen(){}
	int gradeForRevenge(){
		int sum = 0;
		for (int i = 0; i < loyalty; i++)
		{
			sum += friends[i].getPower();
		}
		return 2 * sum;
	}
}; 
class Stark: virtual public Human{
private:
	int years;
public:
	virtual char* getSkill(){
		return "ice";
	}
	int gradeForRevenge(){
		int sum = 0;
		for (int i = 0; i < loyalty; i++)
		{
			sum += friends[i].getPower();
		}
		return 2 * sum;
	}
	Stark(int years = 0, char* name = "", int power = 0, int loyalty = 0) : Human(name, power, loyalty){
		this->years = years;
	}
	Stark& operator=(const Stark& other){
		if (this != &other){
			Human::operator=(other);
			years = other.years;
		}
		return *this;
	}
	Stark(const Stark& other) : Human(other){
		years = other.years;
	}
	~Stark(){}

};
class Targeryen_Stark : public Targaryen, public Stark{
private:
	char* name;
	int power;
	int loyalty;
	void cpy(char* name, int power, int loyalty){
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		assert(this->name != NULL);
		strcpy_s(this->name, length, name);
		this->power = power;
		this->loyalty = loyalty;
	}
public:
	char* setName(char* name){
		delete[] this->name;
		size_t length = strlen(name) + 1;
		this->name = new char[length];
		assert(this->name != NULL);
		strcpy_s(this->name, length, name);
		return this->name + " Snow";
	}
	char* getName(){
		return this->name;
	}
	int getPower(){
		return this->power;
	}
	int getLoyalty(){
		return this->loyalty;
	}
	void setPower(int power){
		this->power = power
	}
	void setLoyalty(int loyalty){
		this->loyalty = loyalty;
	}
	virtual char* getSkill(){
		return "I am the son of " + Targaryen::getSkill() + " and " + Stark::getSkill() + "!";
	}
	Targeryen_Stark(char* name = "", int power = 0, int loyalty = 0, int years = 0, int _years = 0, char* _name = "", int _power = 0, int _loyalty = 0) : Human(name, power, loyalty),
		Targaryen(years), Stark(_years){
		cpy(_name, _power, _loyalty);
	}
	~Targeryen_Stark(){
		delete[] this->name;
	}
	Targeryen_Stark(const Targeryen_Stark& other) : Human(other), Targaryen(other), Stark(other){
		cpy(other.name, other.power, other.loyalty);
	}
	Targeryen_Stark& operator= (const Targeryen_Stark& other){
		if (this != &other){
			Human::operator=(other);
			Targaryen::operator=(other);
			Stark::operator=(other);
			delete[]this->name;
			cpy(other.name, other.power, other.loyalty);
		}
		return *this;
	}
};