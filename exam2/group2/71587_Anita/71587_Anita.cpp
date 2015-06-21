//kapsulaciq, abstrakciq, polimorfizim, unasledqvane
#include <iostream>
#include <cstring>
#include <cassert>
#include <cmath>
using  namespace std;

class Human
{
protected:
	char* human_name;
	int power;
	int loyality;
	Human* friends;
	void copy_human(char* human_name, int power, int loyality)
	{
		this->human_name = new char[strlen(human_name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->human_name, strlen(human_name) + 1, human_name);
		this->power = power;
		this->loyality = loyality;
	}
	virtual char* get_special_skill() const = 0;
	virtual int get_revenge () const = 0;
public:
	void set_name(char* name)
	{
		delete[] this->human_name;
		this->human_name = new char[strlen(human_name) + 1];
		assert(this->name != NULL);
		strcpy_s(this->human_name, strlen(human_name) + 1, human_name);
	}
	void set_power(int power)
	{
		this->power = power;
	}
	void set_loyality(int loyality)
	{
		this->loyality = loyality;
	}
	char* get_name()
	{
		return this->human_name; 
	}
	int get_power()
	{
		return this->power;
	}
	int get_loyality()
	{
		return this->loyality;
	}
	Human(char* human_name = "", int power = 0, int loyality = 0)
	{
		copy_human(human_name, power, loyality);
	}
	Human(const Human& other)
	{
		copy_human(other.human_name, other.power, other.loyality);
	}
	virtual ~Human()
	{
		delete[] this->human_name;
	}
	void addHuman(const Human& other)
	{
		for (int i = 0; i < loyality; i++)
		{
			this->friends[i] = &other;
			loyality++;
		}
	}
	void removeHuman(char* human_name)
	{
		
		for (int i = 0; i < loyality; i++)
		{
			if (strcmp(this->human_name, this->friends->get_name) == 0)
			{
				this->friends[i + 1] = this->friends[i];
				loyality--;
			}
		}
	}
};

class Normal_human : virtual public Human
{
public:
	char* get_special_skill() const
	{
		return "none";
	}
	int get_revenge() const
	{
		int sum = 0;
		for (int i = 0; i < loyality; i++)
		{
			sum += this->friends[i].get_power;
		}
		return sum; 
	}
	bool addNormalHuman(const Human& other)
	{
		if (strcmp(this->get_special_skill, "none") == 0)
		{
			for (int i = 0; i < loyality; i++)
			{
				this->friends[i] = &other;
				loyality++;
			}
			return true;
		}
		return false;
	}
	bool removeNormalHuman(char* name)
	{
		removeHuman(name);
	}
	Normal_human(char* human_name = "", int power, int loyality) : Human(human_name, power, loyality){}
	Normal_human(const Normal_human& other) : Human(other.human_name, other.power, other.loyality) {}
	Normal_human& operator= (const Normal_human& other)
	{
		if (this == &other) return *this;
		delete[] this->human_name;
		copy_human(other.human_name, other.power, other.loyality)l;
		return *this;
	}
	virtual ~Normal_human()
	{
		delete[] this->human_name;
	}
};

class Army : virtual public Human
{
protected:
	Human* sold[100];
	int count_sold;
	Human* boss;
	virtual double get_army() const = 0;
	virtual double pay_sold() const = 0;
public:
	void addSold(const Human& other)
	{
		for (int i = 0; i < count_sold; i++)
		{
			this->sold[i] = &other;
			count_sold++;
		}
	}
	void removeSold(char* human_name)
	{

		for (int i = 0; i < count_sold; i++)
		{
			if (strcmp(this->human_name, this->sold[i]->get_name) == 0)
			{
				this->sold[i + 1] = this->sold[i];
				count_sold--;
			}
		}
	}
	void changeBoss(const Human& other)
	{
		this->boss = &other;
	}
	Army(Human* const* sold = NULL, int count_sold = 0, Human* boss = NULL, char* human_name = "", int power = 0, int loyality = 0) : Human(human_name, power, loyality)
	{
		this->count_sold = count_sold;
		for (int i = 0; i < count_sold; i++)
		{
			this->sold[i] = sold[i];
		}
		this->boss = boss;
	}
	Army(const Army& other)
	{
		this->count_sold = other.count_sold;
		for (int i = 0; i < count_sold; i++)
		{
			this->sold[i] = other.sold[i];
		}
		this->boss = other.boss;
	}
	Army& operator= (const Army& other)
	{
		if (this == &other) return *this;
		this->count_sold = other.count_sold;
		for (int i = 0; i < count_sold; i++)
		{
			this->sold[i] = other.sold[i];
		}
		this->boss = other.boss;
		return *this;
	}
	virtual ~Army(){}
};

class Paid_Army :  public Army
{
protected:
	int money;
	double pay;
	double boss_pay;
public:
	double pay_sold() const
	{
		return (money - boss_pay) / count_sold;
	}
	void changeBoss(const Human& other)
	{
		if (strcmp(this->get_special_skill, "none") == 0 || strcmp(this->get_special_skill, "fire" ==0))
		this->Army::changeBoss(other);
	}
	void set_pay(double pay)
	{
		this->pay = pay;
	}
	double get_pay()
	{
		return this->pay;
	}
	double get_army() const
	{
		int sum = 0;
		for (int i = 0; i < count_sold; i++)
		{
			sum += this->sold[i]->get_pay();
		}
		int sum_power = this->boss->get_power;
		for (int i = 0; i < count_sold; i++)
		{
			sum += this->sold[i]->get_power;
		}
		return (this->boss->get_loyality())* sum + sum_power;
	}
	Paid_Army(Human* const* sold = NULL, int count_sold = 0, Human* boss = NULL, char* human_name = "", int power = 0, int loyality = 0, int money = 0, double pay = 0, double boss_pay = 0) : Army(sold, count_sold, boss, human_name, power, loyality)
	{
		this->money = money;
		this->pay = pay;
		this->boss_pay = boss_pay;
	}
	Paid_Army(const Paid_Army& other)
	{
		this->money = other.money;
		this->pay = other.pay;
		this->boss_pay = other.boss_pay;
	}
	Paid_Army& operator= (const Paid_Army& other)
	{
		if (this == &other) return *this;
		this->money = other.money;
		this->pay = other.pay;
		this->boss_pay = other.boss_pay;
		return *this;
	}
	virtual ~Paid_Army(){}
};

class Conscript_Army : virtual public Army
{
public:
	Conscript_Army(Human* const* sold = NULL, int count_sold = 0, Human* boss = NULL, char* human_name = "", int power = 0, int loyality = 0) : Army(sold, count_sold, boss, human_name, power, loyality){}
	Conscript_Army(const Conscript_Army& other)	{}
	Conscript_Army& operator= (const Conscript_Army& other)	{}
	virtual ~Conscript_Army(){}
	double get_army() const
	{
		int sum = 0;
		for (int i = 0; i < count_sold; i++)
		{
			sum += this->sold[i]->get_loyality();
		}
		int sum_power = this->boss->get_power;
		for (int i = 0; i < count_sold; i++)
		{
			sum += this->sold[i]->get_power;
		}
		return (this->boss->get_loyality())* sum + sum_power;
	};
	void changeBoss(const Human& other)
	{
		this->Army::changeBoss(other);
	}
};

class Targaryen : virtual public Human
{
protected:
	int age;
public:
	void set_age(int age)
	{
		this->age = age;
	}
	int get_age()
	{
		return this->age;
	}
	char* get_name(char* name)
	{
		return this->Human::get_name;
	}
	void set_name()
	{
		this->Human::set_name;
	}
	void set_power(char* power)
	{
	 this->Human::set_power;
	}
	int get_power()
	{
	return this->Human::get_power;
	}
	void set_loyality(char* power)
	{
		this->Human::set_loyality;
	}
	int get_loyality()
	{
		return this->Human::get_loyality;
	}
	char* get_special_skill() const
	{
		return "fire";
	}
	Targaryen(char* human_name = "", int power = 0, int loyality = 0, int age = 0) : Human(human_name, power, loyality)
	{
		this->age = age;
	}
	Targaryen(const Human& other)
	{
		this->age = other.age;
	}
	Targaryen& operator= (const Targaryen& other)
	{
		if (this == &other) return *this;
		this->age = other.age;
	}
	virtual ~Targaryen() {}
};

class Stark : virtual public Human
{
protected:
	int age;
public:
	void set_age(int age)
	{
		this->age = age;
	}
	int get_age()
	{
		return this->age;
	}
	char* get_name(char* name)
	{
		return this->Human::get_name;
	}
	void set_name()
	{
		this->Human::set_name;
	}
	void set_power(char* power)
	{
		this->Human::set_power;
	}
	int get_power()
	{
		return this->Human::get_power;
	}
	void set_loyality(char* power)
	{
		this->Human::set_loyality;
	}
	int get_loyality()
	{
		return this->Human::get_loyality;
	}
	char* get_special_skill() const
	{
		return "ice";
	}
	Stark(char* human_name = "", int power = 0, int loyality = 0, int age = 0) : Human(human_name, power, loyality)
	{
		this->age = age;
	}
	Stark(const Human& other) 
	{
		this->age = other.age;
	}
	Stark& operator= (const Stark& other)
	{
		if (this == &other) return *this;
		this->age = other.age;
	}
	virtual ~Stark() {}
};
