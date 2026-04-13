#include <iostream>
using std::cout;
using std::endl;
using std::string;
class clsPerson
{
private:
    struct stAddress
    {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };

public:
    // stAddress Address;
    string FullName;
    stAddress Address;
    clsPerson() // constructor
    {
        FullName = "Abd_Elrahman Ebrahim Abdo Mohammed";
        Address.AddressLine1 = "Building 10";
        Address.AddressLine2 = "Cima Street";
        Address.City = "Qus";
        Address.Country = "Egypt";
    }
    void PrintAddress()
    {
        cout << "\nAddress :\n\n";
        cout << FullName << endl;
        cout << Address.AddressLine1 << endl;
        cout << Address.AddressLine2 << endl;
        cout << Address.City << endl;
        cout << Address.Country << endl;
    }
};

int main()
{
    clsPerson Person1;

    Person1.PrintAddress();

    std::cin.get();
}