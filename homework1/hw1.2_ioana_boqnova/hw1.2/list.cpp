#include <iostream>
#include <cstring>
#include <cassert>
#include "list.h"

using namespace std;


Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}

void Date::setDate(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

int Date::getYear() const
{
	return year;
}

bool Date::isLeap() const
{
	return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

bool Date::isValid() const
{
	if ((getDay() >= 1 && getDay() <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
		return true;
	else if ((getDay() >= 1 && getDay() <= 29) && isLeap())
		return true;
	if ((getDay() >= 1 && getDay() <= 30) && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		return true;
	else return false;
}

Date& Date :: operator= (const Date& other)
{
	if (this != &other)
	{
		this->day = other.getDay();
		this->month = other.getMonth();
		this->year = other.getYear();
	}
	return *this;
}

void Date::print() const
{
	cout << getDay() << "/" << getMonth() << "/" << getYear() << endl;
}

void Date::setDay(int d)
{
	this->day = d;
}

void Date::setMonth(int m)
{
	this->month = m;
}

Person::Person()
{
	lastName = new char[7];
	strcpy_s(lastName, 7, "Ivanov");
	birthDate = Date();
}

Person :: ~Person()
{
	delete[] lastName;
}

Person::Person(const Person& other)
{
	lastName = new char[strlen(other.getName()) + 1];
	assert(lastName);
	strcpy_s(lastName, strlen(lastName) + 1, other.getName());

	this->birthDate = other.getDate();
}

void Person::setName(char* a)
{
	delete[] lastName;
	lastName = new char[strlen(a) + 1];
	assert(lastName);
	strcpy_s(lastName, strlen(a) + 1, a);
}

char* Person::getName() const
{
	return lastName;
}

void Person::setDate(const Date& a)
{
	this->birthDate = a;
}

Date Person::getDate() const
{
	return this->birthDate;
}

void Person::print()
{
	cout << "Last name: " << getName() << endl;
	cout << "Date of birth: "; getDate().print();
}

Person& Person :: operator= (const Person& other)
{
	if (this != &other)
	{
		delete [] lastName;
		lastName = new char[strlen(other.getName()) + 1];
		assert(lastName);
		strcpy_s(lastName, strlen(other.getName()) + 1, other.getName());
		this->birthDate = other.birthDate;
	}
	return *this;
}

ListPerson :: ListPerson()
{
	this->size = 1;
	this->count = 0;
	this->list = new Person[this->size];
}

ListPerson :: ~ListPerson()
{
	delete[] list;
}

ListPerson::ListPerson(const ListPerson& other)
{
	this->size = other.size;
	this->count = other.count;
	for (int i = 0; i < other.size; i++)
	{
		list[i] = other.list[i];
	}
}

ListPerson& ListPerson :: operator= (const ListPerson& other)
{
	if (this != &other)
	{
		this->count = other.count;
		this->size = other.size;
		delete[] list;
		list = new Person[other.size];
		assert(list);
		for (int i = 0; i < other.size; i++)
		{
			list[i] = other.list[i];
		}
	}
	return *this;
}

void ListPerson::addPerson(const Person& a)
{
	if (count == size)
	{
		size *= 2;
		Person* temp = new Person[count];
		assert(temp);
		for (int i = 0; i < count; i++)
		{
			temp[i] = list[i];
		}
		delete[] list;
		list = temp;
		delete[] temp;
	}
	list[count] = a;
	count++;
}

void ListPerson::deletePerson(char* a)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(this->list[i].getName(), a) == 0)
		{
			for (int j = i; j < count - 1; j++)
			{
				list[i + 1] = list[i];
			}
		}
	}
}

Person* ListPerson::getPerson(char* a)
{
	bool person = false;
	int i;
	for (i = 0; i < count; i++)
	{
		if (strcmp(list[i].getName(), a) == 0)
			person = true;
	}
	if (person) return &list[i];
	else return NULL;
}
 
int ListPerson::getCount() const
{
	return count;
}

ListPerson& ListPerson::unionList(const ListPerson& lp)
{
	int newSize = this->getCount() + lp.getCount();
	Person* temp = new Person[newSize];
	for (int i = 0; i < this->getCount(); i++)
	{
		temp[i] = list[i];
	}
	for (int j = this->getCount(); j < newSize; j++)
	{
		for (int k = 0; k < lp.getCount(); k++)
		{
			temp[j] = lp.list[k];
		}
	}
	//delete[] lp.list;
	//delete[] this->list;
	list = new Person[newSize];
	list = temp;
	delete[] temp;
	return *this;
}

ListPerson& ListPerson::sectionList(const ListPerson& list)
{
	int maxSize;
	if (getCount() > list.getCount()) maxSize = getCount();
	else maxSize = list.getCount();
	Person* temp = new Person[maxSize];
	for (int i = 0; i < getCount(); i++)
	{
		for (int j = 0; j < list.getCount(); j++)
		{
			if (strcmp(this->list[i].getName(), list.list[j].getName()) == 0)
			{
				temp[i] = list.list[j];
				count++;
			}
		}
	}
	delete[] this->list;
	this->list = new Person[count];
	this->list = temp;
	delete[] temp;
	return *this;
}

ListPerson& ListPerson::differenceList(const ListPerson& list)
{
	Person* temp = new Person[getCount()];
	for (int i = 0; i < getCount(); i++)
	{
		for (int j = 0; j < list.getCount(); j++)
		{
			if (strcmp(this->list[i].getName(), list.list[j].getName()) != 0)
			{
				temp[i] = this->list[i];
				count++;
			}
		}
	}
	delete[] this->list;
	this->list = new Person[count];
	this->list = temp;
	delete[] temp;
	return *this;
}

void ListPerson::print()
{
	for (int i = 0; i < count; i++)
	{
		list[i].print();
	}
}

void Zodiak::setName(char* n)
{
	delete[] name;
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
}

const char* Zodiak::getName() const
{
	return name;
}

void Zodiak::setStart(const Date& d)
{
	this->start = d;
}

Date Zodiak::getStart() const
{
	return start;
}

void Zodiak::setEnd(const Date& d)
{
	this->end = d;
}

Date Zodiak::getEnd() const
{
	return end;
}

void Zodiak::update(char* z, int sD, int sM, int eD, int eM)
{
	delete[] name;
	name = new char[strlen(z) + 1];
	assert (name);
	strcpy_s(name, strlen(z) + 1, z);
	start.setDay(sD);
	start.setMonth(sM);
	end.setDay(eD);
	end.setMonth(eM);
}

void ListPerson::getZodia(char* name)
{
	Zodiak a[12];
	a[0].update("Aries", 21, 3, 20, 4);
	a[1].update("Taurus", 21, 4, 21, 5);
	a[2].update("Gemini", 22, 5, 21, 6);
	a[3].update("Cancer", 22, 6, 22, 7);
	a[4].update("Leo", 23, 7, 22, 8);
	a[5].update("Virgo", 23, 8, 23, 9);
	a[6].update("Libra", 24, 9, 23, 10);
	a[7].update("Scorpio", 24, 10, 23, 11);
	a[8].update("Sagittarius", 23, 11, 21, 12);
	a[9].update("Capricorn", 22, 12, 20, 1);
	a[10].update("Aquarius", 21, 1, 19, 2);
	a[11].update("Pisces", 20, 2, 20, 3);

	int i;
	bool person = false;
	for (i = 0; i < count; i++)
	{
		if (strcmp(name, list[i].getName()) == 0)
		{
			person = true;
			break;
		}
	}
	if (person)
	{
		for (int j = 0; j < 12; j++)
		{
			bool isBeforeDay = a[j].start.getDay() <= list[i].getDate().getDay();
			bool isSameStartMonth = a[j].start.getMonth() == list[i].getDate().getMonth();
			bool isAfterDay = a[j].end.getDay() >= list[i].getDate().getDay();
			bool isSameEndMonth = a[j].end.getMonth() == list[i].getDate().getMonth();
			
			
	
			/*bool bigIf = ((a[j].start.getDay() <= list[i].getDate().getDay())
				&& (a[j].start.getMonth() == list[i].getDate().getMonth)) ||
				((a[j].end.getDay() >= list[i].getDate().getDay()) &&
				a[j].end.getMonth() == list[i].getDate().getMonth());*/
			bool condition = (isBeforeDay && isSameStartMonth) || (isAfterDay && isSameEndMonth);
			if (condition)
			{
				cout << list[i].getName() << "' zodia is: " << a[j].getName();
			}
		}
	}
}
