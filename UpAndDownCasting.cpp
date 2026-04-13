#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class clsPerson
{
public:
    string FullName = "Abd_Elrahman Ebrahim Abdo \n";
};

class clsEmployee : public clsPerson
{
public:
    string Title = "Manager\n";
};

int main()
{

    clsEmployee Employee1;

    cout << Employee1.FullName << endl;

    // upcasting
    // this will convert employee to person.
    // القليل ينفع يشاور علي الكثير
    clsPerson *Person1 = &Employee1;
    cout << Person1 << endl;
    cout << Person1->FullName << endl;

    // Down Casting
    // You cannot convert person to employee
    //  مينفع الكثير يشاور على القليل
    clsPerson Person2;
    cout << Person2.FullName << endl;
    // clsEmployee *Employee2 = &Person2;

    std::cin.get();
    return 0;
}