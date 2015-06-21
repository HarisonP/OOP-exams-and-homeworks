#include <iostream>
#include <cassert>
#include <cstring>

//Abstrakciq, enkapsulaciq, nasledqvane, polimorfizum

using namespace std;

class Human
{
protected:
    char* name;
    int power;
    int loyalty;
    Human** friends;
    int size;

public:
    virtual void setName(char* name)
    {
        delete[] this->name;
        size_t length = strlen(name) + 1;
        this->name = new char[length];
        strncpy(name,this->name,length);
    }
    virtual char* getName() const
    {
        return this->name;
    }
    virtual void setPower(int power)
    {
        this->power = power;
    }
    virtual int getPower() const
    {
        return this->power;
    }
    virtual void setLoyalty(int loyalty)
    {
        this->loyalty = loyalty;
    }
    virtual int getLoyalty() const
    {
        return this->loyalty;
    }
    Human()
    {
        name = "";
        power = 0;
        size = 0;
        loyalty = 1;
        friends = new Human*[loyalty];
        Human a("Hi", 0, 0, nullptr);
        this->friends[0] = &a;
    }
    Human(char* name, int power, int size, int loyalty, Human** friends)
    {
        setName(name);
        setPower(power);
        setLoyalty(loyalty);
        this->size = size;
        delete[] friends;
        del();
        this->friends = new Human*[loyalty];
        for(int i=0; i < size; i++)
        {
            this->friends[i] = friends[i];
        }

    }
    Human(const Human& other)
    {
        setName(other.name);
        setPower(other.power);
        setLoyalty(other.loyalty);
        this->size = other.size;
        del();
        this->friends = new Human*[loyalty];
        for(int i=0; i < size; i++)
        {
            this->friends[i] = other.friends[i];
        }
    }
    Human& operator=(const Human& other)
    {
        if(this != &other)
        {
            delete[] name;
            del();
            setName(other.name);
            setPower(other.power);
            setLoyalty(other.loyalty);
            this->size = other.size;
            this->friends = new Human*[loyalty];
            for(int i=0; i < size; i++)
            {
                this->friends[i] = other.friends[i];
            }
        }
        return *this;
    }
    void del()
    {
        delete[] friends;
        for(int i = 0; i < size; i++)
        {
            delete friends[i];
        }
    }
    virtual~Human()
    {
        delete[] this->name;
        del();
    }
    int lessPower(int n)
    {
        int lessPower = power - n;
        if(lessPower >= 0)
        {
            return lessPower;
        }
        else
        {
            return power;
        }
    }
   virtual bool addFriend() = 0;
   virtual bool removeFriend() = 0;
   virtual char* getSpecialSkill() = 0;
   virtual int getRevengeMark() = 0;
};

class NormalHuman: public Human
{
public:
    char* getSpecialSkill()
    {
        return "none";
    }
    bool addFriend(const Human& new)
    {
        if(strcmp(new.getSpecialSkill(), "none") == 0)
        {
            friends*[loyalty] = &new;
            loyalty++;
            return true;
        }
        else return false;
    }
    bool removeFriend(const Human& rem)
    {
        for(int i = 0, i < size; i++)
        {
            if(strcmp(getName(),rem.getName()) == 0)
            {
                for(int j = i+1; j<size; j++)
                {
                    friends[j] = j[j-1];
                }
            }
            size--;
            return true;
        }
        return false;
    }
    int getRevengeMark()
    {
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += friends[i]->getPower();
        }
        return sum;
    }
    ~NormalHuman()
    {

    }
};

class Army
{
protected:
    Human* army[100];
    int soldiers;
    Human* leader;

public:
    Army()
    {
        soldiers = 1;
        leader("", 0, 1000);
        army[0] = &leader;
    }
    Army(Human* army[100], int soldiers, Human* leader)
    {
        dele();
        this->army = new Human*[soldiers];
        this->soldiers = soldiers;
        this->leader = &leader;
    }
    Army(const Army& other)
    {
        this->army = new Human*[other.soldiers];
        for(int i = 0; i < other.soldiers; i++)
        {
            army[i] = other.army[i];
        }
        this->soldiers = other.soldiers;
        this->leader = &other.leader;
    }
    Army& operator=(const Army& other)
    {
        if(this != &other)
        {
            dele();
            this->army = new Human*[other.soldiers];
            for(int i = 0; i < other.soldiers; i++)
            {
                army[i] = other.army[i];
            }
            this->soldiers = other.soldiers;
            this->leader = &other.leader;
        }

    }
    void dele()
    {
        delete[] army;
        for(int i = 0; i < soldiers; i++)
        {
            delete army[i];
        }
    }
    virtual~Army()
    {
        dele();
    }
    virtual bool addSoldier() = 0;
    virtual bool removeSoldier() = 0;
    virtual void addLeader() = 0;
    virtual double gradeOfArmy() = 0;
    virtual bool operator>() = 0;

};

class PaidArmy: public Army
{
private:
    int money;
public:
    PaidArmy():Army()
    {
        money = 0;
    }
    PaidArmy(Human* army[100], int soldiers, Human* leader, int money):Army(army[100], soldiers, leader)
    {
        this->money = money;
    }
    PaidArmy(const Army& other):Army(other)
    {
        this->money = other.money;
    }
    PaidArmy& operator=(const PaidArmy& other)
    {
        if(this != &other)
        {
            Army::dele();
            Army::operator=(other);
            this->money = other.money;
        }
        return *this;
    }
    ~PaidArmy()
    {

    }
    double getSalary()
    {
        return (0.2*leader->money) / soldiers;
    }
    void addLeader(const Human& new)
    {
        if(new != &leader)
        {
            for(int i = 0; i < soldiers; i++)
            {
                if(((strcmp(army[i]->getPower(), "none") == 0) || (strcmp(army[i]->getPower(), "fire") == 0) )&& (strcmp(army[i]->getName(), new.getName()) == 0) )
                {
                    leader = &new;
                }
            }
        }
    }
    double gradeOfArmy()
    {
        int sumPower=0;
        for(int i = 0; i < soldiers; i++)
        {
            if(army[i] != &leader)
            {
                sumPower += army[i]->getPower();
            }
        }

        return leader->loyalty*getSalary()*soldiers + sumPower + leader->getPower();
    }
    bool operator>(const Army& other)
    {
        return (this->gradeOfArmy() > other.gradeOfArmy());
    }


};

class ConscriptArmy: public Army
{
public:
    ConscriptArmy():Army(){}
    ConscriptArmy(Human* army[100], int soldiers, Human* leader): Army(army[100], soldiers, leader){}
    ConscriptArmy(const Army& other): Army(other){}
    ConscriptArmy operator=(const Army& other){}
    {
        if(this != &other)
        {
            Army::dele();
            Army::operator=(other);
        }
    }
    ~ConscriptArmy()
    {

    }
    double gradeOfArmy()
    {
        int sumLoyalty = 0;
        for(int i = 0; i < soldiers; i++)
        {
            sumLoyalty += army[i]->getLoyalty();
        }
        int sumPower2 = 0;
        for(int i = 0; i < soldiers; i++)
        {
            sumPower2 += army[i]->getPower();
        }

        return (leader->loyalty*sumLoyalty) + sumPower2;
    }
    bool operator>(const Army& other)
    {
        return (this->gradeOfArmy() > other.gradeOfArmy());
    }
};


class Targaryen: virtual public Human
{
protected:
    int age;
private:
    void setLoyalty(int loyalty)
    {
        this->loyalty = loyalty;
    }

public:
    Targaryen():Human()
    {
        age = 0;
    }
    Targaryen(int age, char* name, int power, int size, int loyalty, Human** friends):Human(name,power,size,loyalty,friends)
    {
        this->age = age;
    }
    Targaryen(const Targaryen& other): Human(other)
    {
        this->age = other.age;
    }
    Targaryen& operator=(const Targaryen& other)
    {
        if(this != &other)
        {
            Human::del();
            Human::operator=(other);
            this->age = other.age;
        }
        return *this;
    }
    int getAge()
    {
        return this->age;
    }
    ~Targaryen()
    {
        Human::del();
    }
    void setName(char* name)
    {
        delete[] this->name;
        size_t length = strlen(name) + 1;
        this->name = new char[length];
        strncpy(name,this->name,length);
    }
    char* getName() const
    {
        return this->name;
    }
    void setPower(int power)
    {
        this->power = power;
    }
    int getPower() const
    {
        return this->power;
    }
    int getLoyalty() const
    {
        return this->loyalty + age;
    }
    char* specialSkilled()
    {
        return "fire";
    }
    bool addFriend(const Targaryen& new)
    {
        if(strcmp(new.getSpecialSkill(), specialSkilled()) == 0)
        {
            friends*[loyalty] = &new;
            loyalty++;
            return true;
        }
        else return false;
    }
    bool removeFriend(const Targaryen& rem)
    {
        for(int i = 0, i < size; i++)
        {
            if(strcmp(getName(),rem.getName()) == 0)
            {
                for(int j = i+1; j<size; j++)
                {
                    friends[j] = j[j-1];
                }
            }
            size--;
            return true;
        }
        return false;
    }
    int getRevengeMark()
    {
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += friends[i]->getPower();
        }
        return 2*sum;
    }
};

class Stark: virtual public Human
{
public:
    Stark():Human(){}
    Stark(char* name, int power, int size, int loyalty, Human** friends):Human(name,power,size,loyalty,friends){}
    Stark(const Stark& other): Human(other){}
    Stark& operator=(const Stark& other)
    {
        if(this != &other)
        {
            Human::del();
            Human::operator=(other);
        }
        return *this;
    }
    ~Stark()
    {
        Human::del();
    }
    void setName(char* name)
    {
        delete[] this->name;
        size_t length = strlen(name) + 1;
        this->name = new char[length];
        strncpy(name,this->name,length);
    }
    char* getName() const
    {
        return this->name;
    }
    void setPower(int power)
    {
        this->power = power;
    }
    int getPower() const
    {
        return this->power;
    }
     void setLoyalty(int loyalty)
    {
        this->loyalty = loyalty - size;
    }
    int getLoyalty() const
    {
        return this->loyalty + size;
    }
    char* specialSkilled()
    {
        return "ice";
    }
};

class Targaryen_Stark: public Targaryen, public Stark
{
public:
    Targaryen_Stark(): Stark(), Targaryen(), Human(){}
    Targaryen_Stark(int age, char* name, int power, int size, int loyalty, Human** friends): Stark(),Targaryen(age),Human(name,power,size,loyalty,friends){}
    Targaryen_Stark(const Targaryen_Stark& other):Stark(other), Targaryen(other), Human(other){}
    Targaryen_Stark& operator=(const Targaryen_Stark& other)
    {
        if(this != &other)
        {
            Human::del();
            Human::operator=(other);
            Stark::operator=(other);
            Targaryen::operator=(other);
        }
        return *this;
    }
    ~Targaryen()
    {
        Human::del();
    }
    void setName(char* name)
    {
        delete[] this->name;
        size_t length = strlen(name) + 1;
        this->name = new char[length];
        strncpy(name,this->name,length);
    }
    char* getName() const
    {
        return this->name;
    }
    void setPower(int power)
    {
        this->power = power;
    }
    int getPower() const
    {
        return this->power;
    }
    void setLoyalty(int loyalty)
    {
        this->loyalty = loyalty - size - getAge();
    }
    int getLoyalty() const
    {
        return this->loyalty + size + getAge();
    }
};

int main()
{
    return 0;
}
