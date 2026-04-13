#include <iostream>

class clsPerson
{
public:
    virtual void Print()
    {
        std::cout << "Hi, i'm a Person!\n";
    }
};

class clsEmployee : public clsPerson
{
public:
    void Print()
    {
        std::cout << "Hi, i'm an Employee\n";
    }
};

class clsStudent : public clsPerson
{
public:
    void Print()
    {
        std::cout << "Hi,i'm a Student\n";
    }
};

int main()
{
    clsPerson *Person1, *Person2, Person3;

    clsEmployee Employee1;

    clsStudent Student1;
    // Static_Early Binding (in compiletime) the compiler know where to go before run time (Early)[Faster]
    Employee1.Print();
    Student1.Print();
    std::cout << "****************************\n\n";
    Person1 = &Employee1;
    Person2 = &Student1;

    // Dynamic_Late Binding (in Runtime) the compiler doesn't know where to go unless in runtime (Late)
    Person1->Print();
    Person2->Print();

    std::cin.get();
}