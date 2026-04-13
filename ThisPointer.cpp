#include <iostream>
// (this) can only be used inside the class
// it points to all members and functions inside the class even if it is (private or protected or public) but it cannot point to a (friend classes because they are't considered as members of the class)
// we cannot use (this) inside (static functions inside the class) or out the class like in main()Function or any other functions
class Person
{
    int Code;

public:
    int ID;
    std::string name;
    float salary;

    Person(int ID, std::string name, float salary)
    {
        this->ID = ID;
        this->name = name;
        this->salary = salary;
    }

    static void Func1(Person P)
    {

        P.Print();
    }

    void func2()
    {

        Func1(*this);
    }

    void Print()
    {
        std::cout << ID << "  " << name << "  " << salary << std::endl;

        std::cout << this->ID << "  " << this->name << "  " << this->salary << std::endl;

        this->Code;
    }
};

int main()
{

    Person p(20, "Mahrous", 300);

    // these two ways are doing the same thing but theres differences

    Person::Func1(p); // this way does't use oop principels like encapsulation
    // remember that only static functions can be called through the class (on class level)
    p.func2(); // this way is will be in the future esier (use oop principels)
    // انا كدة خفيت عن المسبخدم ان فيه كائن لازم يتمرر وان فيه دالة تانية داخل الدالة func2()

    p.Print();

    std::cin.get();
}