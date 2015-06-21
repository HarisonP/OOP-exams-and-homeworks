#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
//1. Abstrakciq
//2. Nasledqvane
//3. Polimorfizum
//4. Enkapsulaciq

class Human
{
public:
    Human (char* name = "", int power = 0, int loyalty = 0) {
        init(name, power, loyalty);
    }
    Human(const Human& other) {
        init(other.name, other.power, other.loyalty);
    }

    Human& operator=(const Human& other) {
        if(this != &other) {
            init(other.name, other.power, other.loyalty);
        }
        return *this;
    }
    ~Human() {
        delete[] name;
        delete[] friends;
    }

    void setName(char* name) {
        delete[] name;
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
    }
    char* getName() const {
        return this->name;
    }

    void setPower(int power) {
        this -> power = power;

    }
    int getPower() const {
        return this -> power;
    }

    void setLoyalty(int loyalty) {
        this -> loyalty = loyalty;
    }
    int getLoyalty() const {
        return this -> loyalty;
    }

    bool reducePower(int n) {
        if (this -> power >= 0 && (this -> power - n >= 0) && (n >= 0)) {
            this -> power -= n;
            return true;
        } else {
            return false;
        }
    }
    bool addFriend(Human someFriend) {
        if (this -> friendsCount < loyalty - 1) {
            this -> friends[this -> friendsCount] = someFriend;
            this -> friendsCount++;
            return true;
        } else {
            return false;
        }
    }
    bool removeFriend(Human someFriend) {
        int index = -1;
        for (int i = 0; i < this -> friendsCount; i++) {
            if (strcmp(someFriend.getName(), this -> friends[i].getName()) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return false;
        } else {
            for (int i = index; i < this -> friendsCount - 1; i++) {
                this -> friends[i] = this -> friends[i + 1];
                this -> friendsCount--;
            }
        }
    }
    int getRevenge() const {
        int revengeCount = 0;
        for (int i = 0; i < this -> friendsCount; i++) {
            revengeCount += this -> friends[i].getPower();
        }
        return revengeCount;
    }
protected:
    char *name;
    int power;
    int loyalty;
    void init(char* name, int power, int loyalty) {
        this -> name = name;
        this -> power = power;
        this -> loyalty = loyalty;
        this -> friends = new Human[loyalty];
        this -> friendsCount = 0;
    }
    Human* friends;
    int friendsCount;
};

class Normal_human : public Human
{
public:
    char* getSpecial() const {
        return "none";
    }
};

class Army
{
public:
    Army(int soldiersCount = 100, Human* soldiers = NULL, Human* leader = NULL) {
        armyInit(soldiersCount, soldiers, leader);
    }
    Army(const Army& other) {
        armyInit(other.soldiersCount, other.soldiers, other.leader);
    }
    Army& operator=(const Army& other) {
        if (this != &other) {
            armyInit(other.soldiersCount, other.soldiers, other.leader);
        }
        return *this;
    }
    ~Army() {
        delete[] soldiers;
    }
    void addLeader(Human leader) {
        this -> leader = &leader;
    }
    bool addSoldier(Human someSoldier) {
        if (this -> soldiersCount < 99) {
            this -> soldiers[this -> soldiersCount] = someSoldier;
            this -> soldiersCount++;
            return true;
        } else {
            return false;
        }
    }
    bool removeSoldier(Human someSoldier) {
        int index = -1;
        for (int i = 0; i < this -> soldiersCount; i++) {
            if (strcmp(someSoldier.getName(), this -> soldiers[i].getName()) == 0) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return false;
        } else {
            for (int i = index; i < this -> soldiersCount - 1; i++) {
                this -> soldiers[i] = this -> soldiers[i + 1];
                this -> soldiersCount--;
            }
        }
    }
    int getMark() const {
        int mark = 0;
        for (int i = 0; i < soldiersCount; i++) {
            mark += this -> soldiers[i].getPower();
        }
        return mark;
    }
protected:
    Human* soldiers;
    int soldiersCount;
    Human* leader;
    void armyInit(int soldiersCount, Human* soldiers, Human* leader) {
        this -> soldiersCount = soldiersCount;
        this -> soldiers = new Human[soldiersCount];
        this -> leader = leader;
    };
};

class Paid_Army: virtual public Army
{
public:
private:
    int budget;
};
class Conscript_army:virtual public Army
{
public:

};
class Targaryen: public Human
{
public:
private:
    int age;

};
class Stark: public Human
{
public:
private:
    int age;
};
int main()
{
    return 0;
}
