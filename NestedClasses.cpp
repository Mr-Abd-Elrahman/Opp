#include <iostream>

using namespace std;

class clPerson // enclosure  class
{
    std::string _FullName;

public:
    class clsAddress // inner class
    {
    private:
        std::string _AddressLine1;
        std::string _AddressLine2;
        std::string _Street;
        std::string _City;

    public:
        clsAddress(string AddLin1, string Addlin2, string Street, string City)
        {
            _AddressLine1 = AddLin1;
            _AddressLine2 = Addlin2;
            _Street = Street;
            _City = City;
        }
        // Set and get Properties

        // Address Line 1
        void SetAddressLine1(string Line1)
        {
            _AddressLine1 = Line1;
        }
        std::string AddressLine1()
        {
            return _AddressLine1;
        }

        // Address Line 2
        void SetAddressLine2(string Line2)
        {
            _AddressLine2 = Line2;
        }
        std::string AddressLine2()
        {
            return _AddressLine2;
        }

        // Street
        void SetStreet(string S)
        {
            _Street = S;
        }
        std::string Street()
        {
            return _Street;
        }

        // City
        void SetCity(string City)
        {
            _City = City;
        }
        std::string City()
        {
            return _City;
        }

        void PrintAddress()
        {

            std::cout << "\n\nFull Address :\n\n";
            std::cout << _AddressLine1 << std::endl;
            std::cout << _AddressLine2 << std::endl;
            std::cout << _Street << std::endl;
            std::cout << _City << std::endl;
        }
    };

    void SetFullName(std::string FullName)
    {
        _FullName = FullName;
    }
    std::string FullName()
    {
        return _FullName;
    }

    clsAddress Address; // an object of inner class
    // how to fill a constructor in nested classes
    clPerson(string AddLin1, string Addlin2, string Street, string City, string FullName)
        : Address(AddLin1, Addlin2, Street, City)
    {
        _FullName = FullName;
    }
};

/******************************************************************/

// Master Solution of how to intiate the Address Class by its consturctor
class clsPerson
{

    string _FullName;

    class clsAddress
    {

    private:
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;

    public:
        clsAddress(string AddressLine1, string AddressLine2, string City, string Country)
        {
            _AddressLine1 = AddressLine1;
            _AddressLine2 = AddressLine2;
            _City = City;
            _Country = Country;
        }

        void setAddressLine1(string AddressLine1)
        {
            _AddressLine1 = AddressLine1;
        }

        string AddressLine1()
        {
            return _AddressLine1;
        }

        void setAddressLine2(string AddressLine2)
        {
            _AddressLine2 = AddressLine2;
        }

        string AddressLine2()
        {
            return _AddressLine2;
        }

        void setCity(string City)
        {
            _City = City;
        }

        string City()
        {
            return _City;
        }

        void setCountry(string Country)
        {
            _Country = Country;
        }

        string Country()
        {
            return _Country;
        }

        void Print()
        {
            cout << "\nAddress:\n";
            cout << _AddressLine1 << endl;
            cout << _AddressLine2 << endl;
            cout << _City << endl;
            cout << _Country << endl;
        }
    };

public:
    void setFullName(string FullName)
    {
        _FullName = FullName;
    }

    string FullName()
    {
        return _FullName;
    }

    clsAddress Address = clsAddress("", "", "", "");

    clsPerson(string FullName, string AddressLine1, string AddressLine2, string City, string Country)
    {
        _FullName = FullName;

        // initiate address class by it's constructor
        Address = clsAddress(AddressLine1, AddressLine2, City, Country);
    }
};

int main()

{
    // Master Solution
    clsPerson Person1("Mohammed Abu-Hadhoud", "Building 10", "Queen Rania Street", "Amman", "Jordan");

    Person1.Address.Print();

    // Another Solution
    clPerson Person("Building 10", "Arafat house", "Askalany street", "Qus", "Zakaria Arafat Saeed Taha");

    Person.Address.PrintAddress();
    std::cin.get();
    return 0;
}
/*
========================================================
Comparison Between Two Ways of Initializing Nested Class
========================================================

We have:
Person class contains Address class (nested class)
This is called: Composition (Person "has a" Address)

--------------------------------------------------------
First Method (clPerson) → Using Initializer List
--------------------------------------------------------

Constructor:
clPerson(...): Address(AddLin1, Addlin2, Street, City)

Idea:
- Address object is initialized directly using its constructor
- This happens BEFORE entering the constructor body

Execution Steps:
1) When creating object:
   clPerson Person(...);

2) C++ does:
   - Calls Address constructor مباشرة بالقيم
   - Then enters constructor body

Advantages:
✔ Faster (only one construction)
✔ Cleaner and professional
✔ Best practice in C++
✔ Works with:
   - const objects
   - references
   - objects without default constructor

Important:
- If inner class has NO default constructor → you MUST use this method

--------------------------------------------------------
Second Method (clsPerson) → Using Assignment
--------------------------------------------------------

Code:
clsAddress Address = clsAddress("", "", "", "");

Then inside constructor:
Address = clsAddress(AddressLine1, AddressLine2, City, Country);

Idea:
- First create Address with empty values
- Then reassign new values inside constructor

Execution Steps:
1) Create Address with empty values
2) Create temporary object with real values
3) Copy/assign it to Address

Disadvantages:
❌ Slower (2 operations instead of 1)
❌ Not optimal
❌ Not clean design
❌ Cannot be used with:
   - const objects
   - references
❌ May cause issues in large projects

--------------------------------------------------------
Direct Comparison
--------------------------------------------------------

Initializer List:
✔ One-time initialization
✔ Better performance
✔ Professional way
✔ Required in some cases

Assignment:
❌ Double work (create + assign)
❌ Worse performance
❌ Not recommended

--------------------------------------------------------
Which is better?
--------------------------------------------------------

✅ The BEST method:
Initializer List

Reason:
C++ is designed so that member objects are initialized
BEFORE entering constructor body.

So:
- Initializer List = correct way
- Assignment = workaround

--------------------------------------------------------
Simple Analogy
--------------------------------------------------------

Initializer List:
→ Build the house once

Assignment:
→ Build empty house, destroy it, rebuild again

--------------------------------------------------------
Important Rule to Remember
--------------------------------------------------------

Always prefer:

ClassName(...) : member(...)

Avoid assigning objects inside constructor unless necessary

========================================================
*/