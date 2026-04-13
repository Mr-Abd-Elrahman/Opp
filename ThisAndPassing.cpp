#include <iostream>

class Person
{
private:
    std::string name;
    std::string job;
    float salary;
    static void ModefiySalary(Person P)
    {
        P.salary = 2000;
    }
    static void ModefiySalary2(Person &P)
    {
        P.salary = 343322;
    }

public:
    Person(std::string name, std::string job, float salary)
    {
        this->name = name;
        this->job = job;
        this->salary = salary;
    }
    void Fun1(/*intstead of putting a parameter here we used (*this) */)
    {
        ModefiySalary(*this); // instead of writing the parameter again i put *this to refere to the parameter
    }
    void Fun2(/*intstead of putting a parameter here we used (*this) */)
    {
        ModefiySalary2(*this);
    }
    void Print()
    {
        std::cout << this->name << std::endl;
        std::cout << this->job << std::endl;
        std::cout << this->salary << std::endl;
    }
};

int main()
{
    Person P("Yassin Mohammed Adel", "Doctor", 4000);
    // constructor Data
    P.Print();
    std::cout << "\n======================================\n";
    // no modefication will happen because of passing by value
    P.Fun1();
    P.Print();
    std::cout << "\n======================================\n";
    // salary modefided because of Passing by reference
    P.Fun2();
    P.Print();

    std::cin.get();
}