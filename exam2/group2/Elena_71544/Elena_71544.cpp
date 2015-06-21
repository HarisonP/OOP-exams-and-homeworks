//Abstraction,Encapsulation,Polymophism,Inheritance
#include <iostream>
#include <string>
#include<assert.h>
using namespace std;
class Human{
protected:
	char* name;
	int power;
	int loyal;
	int friendCount;
	int maxSize;
	Human** friends;
	void cpy(char* name = "", int power = 0, int loyal = 0, int friendCount = 0, Human** friends = NULL){
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
		this->power = power;
		this->loyal = loyal;
		this->maxSize = loyal;
		this->friendCount = friendCount;
		for (int i = 0; i < friendCount; i++){
			this->friends[i] = friends[i];
		}

	}
public:
	char* getName()const {
		return name;
	}
	virtual int getSalary() = 0;
	void setName(char* name){
		delete[]this->name;
		this->name = new char[strlen(name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	int getPower(){
		return power;
	}
	int getLoyal(){
		return loyal;
	}
	void changePower(int n){
		if (power - n >= 0){
			power -= n;
		}
	}
	virtual char* getSkill() = 0;
	virtual bool addFriend(Human& newOne){
		if (friendCount + 1 <= maxSize){
			friends[friendCount++] = &newOne;
			return true;
		}
		return false;
	}
	virtual bool removeFriend(char* name)
	{
		int index = -1;
		bool isFound = false;
		for (int i = 0; i < friendCount; i++){
			if (strcmp(friends[i]->getName(), name) == 0){
				index = i;
				isFound = true;
				break;
			}
			if (isFound){
				for (int i = index; i < friendCount - 1; i++){
					friends[i] = friends[i + 1];
				}
				friendCount--;
			}
			return isFound;
		}
	}
	Human(char* name, int power, int loyal, int friendCount, Human** friends){
		cpy(name, power, loyal, friendCount, friends);
	}
	virtual void setLoyal(int loyal){
		this->loyal = loyal;
	}
	Human(const Human& other){
		cpy(other.name, other.power, other.loyal, other.friendCount, other.friends);
	}
	virtual ~Human(){
		delete[]name;
		if (friendCount > 0){
			delete[]friends;
		}
	}
	virtual int markPower() = 0;
};
class NormalHuman :public Human{
	virtual char* getSkill(){
		return "none";
	}
	virtual bool addFriend(Human& newOne){
		if (strcmp(newOne.getSkill(), "none") == 0){
			return Human::addFriend(newOne);
		}
		return false;
	}
	virtual bool removeFriend(Human& human){
		if (strcmp(human.getSkill(), "none") == 0){
			return Human::removeFriend(human.getName());
		}
	}
	virtual int markPower(){
		int sum = 0;
		for (size_t i = 0; i < friendCount; i++)
		{
			sum += friends[i]->getPower();
		}
		return sum;
	}
	NormalHuman(char* name, int power, int loyal, int friendCount, Human**friends) :Human(name, power, loyal, friendCount, friends){
	}
	NormalHuman(const Human& other) :Human(other){
	}

};
class Army {
protected:
	Human* warriers[100];
	int countWarriers;
	Human* first;
	void cpy(int countWarriers = 0, Human*const*warriers = NULL, Human* first = NULL){
		this->countWarriers = countWarriers;
		for (int i = 0; i < countWarriers; i++){
			this->warriers[i] = warriers[i];
		}
		this->first = first;
	}
public:
	virtual double getMark() = 0;
	virtual bool addWarrier(Human& newOne){
		if (countWarriers < 100){
			warriers[countWarriers++] = &newOne;
			return true;
		}
		return false;
	}
	virtual bool removeWarrier(Human& human){
		int index = -1;
		bool isFound = false;
		for (int i = 0; i < countWarriers; i++){
			if (strcmp(warriers[i]->getName(), human.getName()) == 0){
				index = i;
				isFound = true;
				break;
			}
			if (isFound){
				for (int i = index; i < countWarriers - 1; i++){
					warriers[i] = warriers[i + 1];
				}
				countWarriers--;
			}
			return isFound;
		}

	}
	virtual bool chargeFirst(Human& newFirst){
		for (int i = 0; i < countWarriers; i++){
			if (strcmp(warriers[i]->getName(), newFirst.getName()) == 0){
				first = &newFirst;
				return true;
			}
		}
		return false;
	}
	Army(int countWarriers, Human** warriers, Human* first){
		cpy(countWarriers, warriers, first);
	}
	Army(const Army& other){
		cpy(other.countWarriers, other.warriers, other.first);
	}
	Army& operator=(const Army&other){
		if (this != &other){
			cpy(other.countWarriers, other.warriers, other.first);
		}
		return *this;
	}
	virtual bool operator>(Army& other) = 0;

};
class PaidArmy :public Army{
private:
	int budget;
	double salary;
public:
	void setSalary(){
		salary = budget*0.8 / countWarriers;
	}
	virtual bool changeFirst(Human& newFirst){
		if (strcmp(newFirst.getSkill(), "none") == 0 || strcmp(newFirst.getName(), "fire")){
			return Army::addWarrier(newFirst);
		}
		return false;
	}
	double getSalary(){
		return salary;
	}
	virtual double getMark(){
		double sum = 0;
		for (int i = 0; i < countWarriers; i++){
			sum += warriers[i]->getPower();
		}
		return countWarriers*getSalary()*first->getLoyal() + sum;
	}
	bool operator>(Army& other){
		return this->getMark() > other.getMark();
	}
	PaidArmy(int countWarriers, Human** warriers, Human* first, int budget = 0, int salary = 0) :Army(countWarriers, warriers, first){
		this->budget = budget;
		setSalary();
	}
	PaidArmy(const PaidArmy& other) :Army(other){
		this->budget = other.budget;
		this->salary = other.salary;
	}
	PaidArmy& operator=(const PaidArmy&other){
		if (this != &other){
			this->budget = other.budget;
			this->salary = other.salary;
			Army::operator=(other);
		}
		return *this;
	}

};
class ConscriptArmy :public Army{
public:

	virtual bool changeFirst(Human& newFirst){
		if (strcmp(newFirst.getSkill(), "none") == 0 || strcmp(newFirst.getName(), "fire")){
			return Army::addWarrier(newFirst);
		}
		return false;
	}
	virtual double getMark(){
		double sum = 0;
		for (int i = 0; i < countWarriers; i++){
			sum += warriers[i]->getPower();
		}
		double suml = 0;
		for (int i = 0; i < countWarriers; i++){
			suml += warriers[i]->getLoyal();
		}
		return countWarriers*suml + sum;
	}
	bool operator>(Army& other){
		return this->getMark() > other.getMark();
	}
	ConscriptArmy(int countWarriers, Human** warriers, Human* first, int budget = 0, int salary = 0) :Army(countWarriers, warriers, first){

	}
	ConscriptArmy(const ConscriptArmy& other) :Army(other){

	}
	ConscriptArmy& operator=(const ConscriptArmy&other){
		if (this != &other){

			Army::operator=(other);
		}
		return *this;
	}

};
class Targaryen :virtual public Human{
protected:
	int years;
public:
	char* getName(){
		return Human::getName();
	}
	void setName(char*name){
		Human::setName(name);
	}
	int getLoyal(){
		return Human::getLoyal() + years;
	}
	int getPower(){
		return Human::getPower();
	}
	char* getSkill(){
		return "fire";
	}
	virtual bool addFriend(Human& newOne){
		if (strcmp(newOne.getSkill(), "fire") == 0){
			return Human::addFriend(newOne);
		}
		return false;
	}
	virtual double getRevenge(){
		double sum = 0;
		for (int i = 0; i < friendCount; i++){
			sum += friends[i]->getPower();
		}
		return 2 * sum;
	}
	Targaryen(char* name, int power, int loyal, int friendCount, Human** friends, int years = 0) :Human(name, power, loyal, friendCount, friends){
		this->years = years;
	}
	Targaryen(const Targaryen& other) :Human(other){
		this->years = other.years;
	}
	int getYears(){
		return years;
	}
	virtual bool removeFriend(Human& human){
		return Human::removeFriend(human.getName());
	}

};
class Stark :virtual public Human{
public:
	char* getName(){
		return Human::getName();
	}
	void setName(char*name){
		Human::setName(name);
	}
	int getLoyal(){
		return Human::getLoyal() + friendCount;
	}
	int getPower(){
		return Human::getPower();
	}
	char* getSkill(){
		return "ice";
	}
	virtual bool addFriend(Human& newOne){

		if (strcmp(newOne.getSkill(), "fire") == 0){
			for (int i = 0; i < friendCount; i++){
				if (strcmp(friends[i]->getSkill(), "fire") == 0){
					return false;
				}
			}
			return Human::addFriend(newOne);
		}
		return false;
	}
	virtual double getRevenge(){
		double sum = 0;
		for (int i = 0; i < friendCount; i++){
			if (strcmp(friends[i]->getSkill(), "fire") == 0){
				sum += friends[i]->getPower() * 2;
			}
			if (strcmp(friends[i]->getSkill(), "ice") == 0){
				sum += friends[i]->getPower() * 3;
			}
			if (strcmp(friends[i]->getSkill(), "none") == 0){
				sum += friends[i]->getPower() * 3;
			}
		}
		return 2 * sum;
	}
	void setLoyal(int loyal){
		Human::setLoyal(loyal - friendCount);
	}
	Stark(char* name, int power, int loyal, int friendCount, Human** friends) :Human(name, power, loyal, friendCount, friends){

	}
	Stark(const Stark& other) :Human(other){

	}
	virtual bool removeFriend(Human& human){
		return Human::removeFriend(human.getName());
	}

};
class Targaryen_Stark :public Targaryen, public Stark{
public:
	char* getName(){
		return Human::getName();
	}
	void setName(char*name){
		strcat(name, " Snow");
		Human::setName(name);
	}
	int getLoyal(){
		return Targaryen::getLoyal() + friendCount;
	}
	int getPower(){
		return Human::getPower();
	}
	char* getSkill(){
		char skill[60];
		strcat(skill, "I am the son of ");
		strcat(skill, Targaryen::getSkill());
		strcat(skill, " and ");
		strcat(skill, Stark::getSkill());
		return skill;
	}
	virtual bool addFriend(Human& newOne){
		return Human::addFriend(newOne);
	}
	virtual double getRevenge(){
		return Targaryen::getRevenge();
	}
	virtual bool removeFriend(Human& human){
		return Human::removeFriend(human.getName());
	}
	void setLoyal(int loyal){
		Human::setLoyal(loyal - friendCount + getYears());
	}
	Targaryen_Stark(char* name, int power, int loyal, int friendCount, Human** friends, int years = 0)
		:Human(name, power, loyal, friendCount, friends), Stark(name, power, loyal, friendCount, friends)
		, Targaryen(name, power, loyal, friendCount, friends, years)
	{}
	Targaryen_Stark(const Targaryen_Stark& other) :Human(other), Stark(other), Targaryen(other){}

};
int main(){


	return 0;
}