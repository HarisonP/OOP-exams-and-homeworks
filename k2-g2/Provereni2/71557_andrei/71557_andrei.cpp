//Принципи: 1.Абстракция с данни. 2. Енкапсулация. 3.Наследяване. 4.Полиморфизъм.


#include <iostream>
using namespace std;
class Human
{
	char *name;
	int strength, loyality, capacity;
protected:
	Human **friends;
public:
	virtual void setName(const char *);
	Human();
	//Human(const Human&);
	//Human& operator=(const Human&);
	virtual ~Human();
	const char * getName() const;
	virtual void setStrength(int);
	virtual void setLoyality(int);
	virtual int getStrength() const;
	virtual int getLoyality();
	void strengthDown(int);
	virtual char *getSkill() const = 0;
	virtual Human** addFriend(const Human&) = 0;
	virtual Human* clone() const = 0;
	virtual Human** remove(const char *) = 0;
	virtual int getOcenka() = 0;
	
	int getCapacity() const;
	virtual double getStr() const = 0;
	void setCapacity(int);
};
void Human::setLoyality(int loy)
{
	this->loyality= loy;
}
void Human::setCapacity(int cap)
{
	this->capacity = cap;
}
void Human::setName(const char *name)
{
	delete[] this-> name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

}
int Human::getLoyality() 
{
	return this->loyality;
}
int Human::getCapacity() const
{
	return this->capacity;
}
Human::Human()
{
	this->setName("test");
	this->strength = 50; this->loyality = 0; this->capacity = 10;
	this->friends = new Human*[this->capacity];
}
Human::~Human()
{
	delete[] this->name;
	for (int i = 0; i < this->loyality; i++)
	{
		delete this->friends[i];
	}
	delete[] this->friends;
}
const char * Human::getName() const
{
	return this->name;
}
void Human::setStrength(int power)
{
	if (power <= 0)
	{
		this->strength = 0;
	}
	this->strength = power;
}

int Human::getStrength() const
{
	return this->strength;
}
void Human::strengthDown(int n)
{
	this->setStrength(this->getStrength() - n);
}
class NormalHuman :  public Human
{
public:
	virtual char *getSkill() const;
	virtual Human** addFriend(const Human&);
	virtual Human* clone() const;
	virtual Human** remove(const char *);
	virtual int getOcenka();
	virtual double getStr() const
	{
		return this->getStrength();
	}
	virtual void setName(const char *name)
	{
		Human::setName(name);
	}
};
char * NormalHuman::getSkill() const
{
	return "none";
}
Human* NormalHuman::clone() const
{
	return new NormalHuman(*this);
}
Human** NormalHuman::addFriend(const Human& other)
{
	if (this->getLoyality() >= this->getCapacity())
	{
		this->setCapacity(this->getCapacity() * 2);
		Human **old = this->friends;
		this->friends = new Human*[this->getCapacity()];
		for (int i = 0; i < this->getLoyality(); i++)
		{
			this->friends[i] = old[i];
		}
		delete[] old;
	}
	this->friends[this->getLoyality()] = other.clone();
	this->setLoyality(this->getLoyality() + 1);
	return this->friends;
}
Human** NormalHuman::remove(const char * name)
{
	Human** old = this->friends;
	this->friends = new Human*[this->getCapacity()];
	bool flag = true;
	int j = 0;
	for (int i = 0; i < this->getLoyality(); i++)
	{		
		if (!strcmp(this->getName(), name))
		{
			flag = false;
		}
		if (flag)
		{
			this->friends[j] = old[i];
			j++;
		}		
	}
	this->setLoyality(this->getLoyality() - 1);
	delete[] old;
	return this->friends;
}
int NormalHuman::getOcenka()
{
	int all = 0;
	for (int i = 0; i < this->getLoyality(); i++)
	{
		all += this->friends[i]->getStrength();
	}
	return all;
}
class Army 
{
	int count, capacity, salaryLeader;
protected:
	Human** voinici;
	Human * leader;
	
public:
	Army();
	//Army(const Army& other);
	//Army& operator=(const Army&);
	virtual ~Army();
	virtual Human** add(const Human&) =0;
	virtual Human** remove(const char *) = 0;
	virtual void setLeader(const Human&) = 0;
	virtual double getPrice() const = 0;	
	int getCount() const;
	int getSalaryleader() const;
	virtual int getSalary();
	int getCapacity() const;
	void setCapacity(int cap)
	{
		this->capacity = cap;
	}
	void setCount(int c)
	{
		this->count = c;
	}	
	virtual bool operator>(const Army&) = 0;
};
int Army::getCapacity() const
{
	return this->capacity;
}
int Army::getCount() const
{
	return this->count;
}
int Army::getSalaryleader() const
{
	return this->salaryLeader;
}
Army::Army() :leader(nullptr)
{
	this->capacity = 5;
	this->count = 0;	
	this->salaryLeader = 500;
	this->voinici = new Human*[this->capacity];
}
Army::~Army()
{
	for (int i = 0; i < this->count; i++)
	{
		delete this->voinici[i];
	}
	delete[] this->voinici;
	delete[] this->leader;
}
class Paid_army : public Army
{
	int budjet;
	double salary;
public:
	Paid_army();
	virtual Human** add(const Human&);
	virtual Human** remove(const char *);
	virtual void setLeader(const Human&);
	virtual double getPrice() const;
	bool operator>(const Army&);
	
};

Paid_army::Paid_army() : Army()
{
	this->budjet = 1000;
	double salary = this->budjet - 0.20*this->getSalaryleader();
	if (this->getCount() != 0)
	{
		this->salary = salary / this->getCount();
	}
	if (this->getCount() == 0)
	{
		this->salary = salary;
	}
}
Human** Paid_army::add(const Human& other)
{
	if (this->getCount() >= this->getCapacity())
	{
		this->setCapacity(this->getCapacity() * 2);
		Human **old = this->voinici;
		this->voinici = new Human*[this->getCapacity()];
		for (int i = 0; i < this->getCount(); i++)
		{
			this->voinici[i] = old[i];
		}
		delete[] old;
	}
	this->voinici[this->getCount()] = other.clone();
	this->setCount(this->getCount() + 1);
	return this->voinici;
}
Human** Paid_army::remove(const char *name)
{
	Human** old = this->voinici;
	this->voinici = new Human*[this->getCapacity()];
	bool flag = true;
	int j = 0;
	for (int i = 0; i < this->getCount(); i++)
	{
		if (!strcmp(this->voinici[i]->getName(), name))
		{
			flag = false;
		}
		if (flag)
		{
			this->voinici[j] = old[i];
			j++;
		}
	}
	this->setCount(this->getCount() - 1);
	delete[] old;
	return this->voinici;
}
void Paid_army::setLeader(const Human& other)
{

	delete this->leader;
	this->leader = other.clone();
}
double Paid_army::getPrice() const
{
	double salaryAll = (this->salary * this->getCount()) * this->leader->getLoyality();
	double s = 0;
	for (int i = 0; i < this->getCount(); i++)
	{
		s += this->voinici[i]->getStrength();
	}
	return s + salaryAll;
}
bool Paid_army:: operator>(const Army& other)
{
	return this->getPrice() > other.getPrice();
}
class Conscript_army: public Army
{
public:	
	virtual Human** add(const Human&);
	virtual Human** remove(const char *);
	virtual void setLeader(const Human&);
	virtual double getPrice() const;
	bool operator>(const Army&);
};
Human** Conscript_army::add(const Human& other)
{
	if (this->getCount() >= this->getCapacity())
	{
		this->setCapacity(this->getCapacity() * 2);
		Human **old = this->voinici;
		this->voinici = new Human*[this->getCapacity()];
		for (int i = 0; i < this->getCount(); i++)
		{
			this->voinici[i] = old[i];
		}
		delete[] old;
	}
	this->voinici[this->getCount()] = other.clone();
	this->setCount(this->getCount() + 1);
	return this->voinici;
}
Human** Conscript_army::remove(const char *name)
{
	Human** old = this->voinici;
	this->voinici = new Human*[this->getCapacity()];
	bool flag = true;
	int j = 0;
	for (int i = 0; i < this->getCount(); i++)
	{
		if (!strcmp(this->voinici[i]->getName(), name))
		{
			flag = false;
		}
		if (flag)
		{
			this->voinici[j] = old[i];
			j++;
		}
	}
	this->setCount(this->getCount() - 1);
	delete[] old;
	return this->voinici;
}
void Conscript_army::setLeader(const Human& other)
{
	delete this->leader;
	this->leader = other.clone();
}
double Conscript_army::getPrice() const
{
	double allLoayity = 0;
	for (int i = 0; i, this->getCount(); i++)
	{
		allLoayity += this->voinici[i]->getLoyality();
	}
	double s = 0;
	for (int i = 0; i < this->getCount(); i++)
	{
		s += this->voinici[i]->getStrength();
	}
	double res = this->leader->getLoyality()*allLoayity + s;
	return res;
}
bool Conscript_army:: operator>(const Army& other)
{
	return this->getPrice() > other.getPrice();
}


class Targaryen : virtual public Human
{
	int age;
public:
	virtual void setStrength(int x)
	{
		Human::setStrength(x);
	}
	virtual void setLoyality(int x)
	{
		return;
	}
	virtual int getStrength() const
	{
		return Human::getStrength();
	}
	virtual int getLoyality() 
	{
		return Human::getLoyality() + age;
	}
	virtual char *getSkill() const = 0
	{
		return "fire";
	}
	virtual Human** addFriend(const Human& o)
	{
		Human::addFriend(o);
	}	
	virtual Human** remove(const char * name)
	{
		Human::remove(name);
	}
	virtual int getOcenka()
	{
		double sila = 0;
		for (int i = 0; i < this->getLoyality(); i++)
		{
			sila += this->friends[i]->getStrength();
		}
		return 2 * sila;
	}
	virtual double getStr() const
	{
		this->getStrength() * 2;
	}
	virtual void setName(const char *name)
	{
		Human::setName(name);
	}
};
class Stark : virtual public Human
{
	int age;
public:
	int getage()
	{
		return age;
	}
	virtual void setStrength(int x)
	{
		Human::setStrength(x);
	}
	virtual void setLoyality(int x)
	{
		Human::setLoyality(x - this->getLoyality());
	}
	virtual int getStrength() const
	{
		return Human::getStrength();
	}
	virtual int getLoyality() 
	{
		return Human::getLoyality() + this->getLoyality();
	}
	virtual char *getSkill() const = 0
	{
		return "ice";
	}
	virtual Human** addFriend(const Human&);
	
	virtual Human** remove(const char *);
	virtual double getStr() const
	{
		this->getStrength() * 3;
	}
	virtual int getOcenka()
	{
		double sila = 0;
		for (int i = 0; i < this->getLoyality(); i++)
		{
			sila += this->friends[i]->getStr();
		}
		return sila;
	}
	virtual void setName(const char *name)
	{
		Human::setName(name);
	}
};
class Targaryen_Stark : public Targaryen, public Stark
{
public:
	virtual void setStrength(int x)
	{
		Human::setStrength(x);
	}
	virtual void setLoyality(int x)
	{
		Human::setLoyality(x - this->getLoyality() - this->getage());
	}
	virtual int getStrength() const
	{
		return Human::getStrength();
	}
	virtual int getLoyality() 
	{
		return Human::getLoyality() + this->getLoyality() + this->getage();
	}
	virtual char *getSkill() const = 0
	{
		
		return strcat(strcat(strcat((strcat("I am the son of  ", Targaryen::getSkill())), "and"), Stark::getSkill()),"!");
	}
	virtual Human** addFriend(const Human& o)
	{
		Human::addFriend(o);
	}
	virtual Human** remove(const char * name)
	{
		Human::remove(name);
	}
	virtual int getOcenka()
	{
		double sila = 0;
		for (int i = 0; i < this->getLoyality(); i++)
		{
			sila += this->friends[i]->getStr();
		}
		return sila;
	}
	virtual double getStr() const
	{
		this->getStrength();
	}
	virtual void setName(const char *name)
	{
		Human::setName(strcat("Snow ",name));
	}
};


