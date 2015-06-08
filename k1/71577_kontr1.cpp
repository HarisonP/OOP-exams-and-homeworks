#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;
//4-te principa na OOP sa: Abstrakcia, Kapsulacia, Naslediavane, Polymorfizam
class Programmer
{
private:
    char*name;
    int iq;
    double salary;
public:
    Programmer(char*name = "Ico", int iq = 120, double salary = 2500)
    {
        this->name=new char[strlen(name)+1];
        assert(this->name != NULL);
        strcpy(this->name, name);
        this->iq=iq;
        this->salary=salary;
    }
    ~Programmer()
    {
        delete []name;
    }
    Programmer (const Programmer &other)
    {
        name=new char[strlen(other.name)+1];
        assert(name != NULL);
        strcpy(name, other.name);
        iq=other.iq;
        salary=other.salary;
    }
    Programmer &operator=(const Programmer &other)
    {
        if(this != &other)
        {
            delete []name;
            name=new char[strlen(other.name)+1];
            assert(name != NULL);
            strcpy(name, other.name);
            iq=other.iq;
            salary=other.salary;
        }
        return *this;
    }
    int getIq() const
    {
        return iq;
    }
    void setIq(int i)
    {
        iq=i;
    }
    double getSalary() const
    {
        return salary;
    }
    void setSalary(double s)
    {
        salary=s;
    }
    char* getName()
    {
        return name;
    }
    void setName(char* name)
    {
        delete [] this->name;
        this->name=new char[strlen(name)+1];
        assert(this->name!=NULL);
        strcpy(this->name, name);
    }
    void print()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Level of intelligence:"<<iq<<endl;
        cout<<"Salary:"<<salary<<endl;
    }
    bool operator>(const Programmer &other)
    {
        return this->iq>other.iq;
    }
    bool operator<(const Programmer &other)
    {
        return this->iq<other.iq;
    }
    bool operator==(const Programmer &other)
    {
        return this->iq==other.iq;
    }
};
class Team
{
private:
    int size, MAX_SIZE=100;
    char* team_name;
    Programmer* programmers;
public:
char* getTeam_Name() const
{
    return team_name;
}
void setTeam_Name(char* team_name)
{
        delete [] this->team_name;
        this->team_name=new char[strlen(team_name)+1];
        assert(this->team_name!=NULL);
        strcpy(this->team_name, team_name);
}
    int getSize()
    {
        return size;
    }
    void addProgrammer(Programmer newPr)
    {
        if(size != MAX_SIZE)
        {
            programmers[size+1]= newPr;
        }
    }
    void removeProgrammer(char* n)
    {
        Programmer newList[100];
        for(int i=0; i<size; i++)
        {
            if(programmers[i].getName() != n)
            {
                newList[i]= programmers[i];
            }
        }
    }
    Programmer getProgrammer(char*n)
    {
        for(int i=0; i<size; i++)
        {
            if(programmers[i].getName() == n)
            {
                return programmers[i];
            }
        }
    }
    void print()
    {
        for(int i=0; i<size; i++)
        {
            cout<<"Name:"<<programmers[i].getName()<<endl;
            cout<<"Level of intelligence:"<<programmers[i].getIq()<<endl;
            cout<<"Salary:"<<programmers[i].getSalary()<<endl;
        }
    }
    Team (char* tea_name="Gotinite", int size=38)
    {
        
        {
            this->programmers=new Programmer[size+1];
            assert(this->programmers != NULL);
            this->team_name=new char[strlen(team_name)+1];
          assert(this->team_name != NULL);
          strcpy(this->team_name, team_name);
          this->size=size; 
        }
    }
    ~Team()
    {
        delete []programmers;
    }
    Team (const Team &other)
   {
        team_name=new char[strlen(other.team_name)+1];
       assert(team_name != NULL);
        strcpy(team_name, other.team_name);
        size=other.size;
    }
    Team &operator=(const Team & other)
    {
        if(this != &other)
        {
            delete []team_name;
            team_name=new char[strlen(other.team_name)+1];
            assert(team_name != NULL);
            strcpy(team_name, other.team_name);
            size=other.size;
        }
       return *this;
    }

};

class Company
{
private:
Team teams[20]; //pravq go statichen, poneje v uslovieto ne pishe che trqbva da e dinamichen 
 {
    double averageIq()
    {
        double avg;
        for(int i=0; i<20; i++)
        {
            double sum = team[i].programmers[i].getSize();
       }
        double avg=sum/20*team[i].programmers[i].getSize();
        cout<<"Averaga iq:"<<avg<<ednl;
       }

};
// - 1.5

// 3.4
