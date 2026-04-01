#include <iostream>

#include <iostream>

// Suber/Base Class
class clsPerson
{
private:
    int _ID = 0;
    std::string _FirstName;
    std::string _LastName;
    std::string _FullName;
    std::string _Email;
    std::string _Phone;

public:
    // default constructor (Temborary solution)
    // clsPerson()
    // {
    // }

    // parameterized constructor
    clsPerson(int ID, std::string FirstName, std::string LastName, std::string Email, std::string Phone)
    {
        _ID = ID;
        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }
    // set and get properties
    int ID() // Read only Property
    {
        return _ID;
    }

    // First name
    void SetFirstName(std::string FirstName)
    {
        _FirstName = FirstName;
    }

    std::string GetFirstName()
    {
        return _FirstName;
    }

    // Last name
    void SetLastName(std::string LastName)
    {
        _LastName = LastName;
    }

    std::string GetLastName()
    {
        return _FirstName;
    }

    // Email
    void SetEmail(std::string Email)
    {
        _Email = Email;
    }

    std::string GetEmail()
    {
        return _Email;
    }

    // Phone
    void SetPhone(std::string Phone)
    {
        _Phone = Phone;
    }

    std::string GetPhone()
    {
        return _Phone;
    }

    std::string GetFullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        std::cout << "Info :\n";
        std::cout << "\n------------------------------------\n";
        std::cout << "\nID         : " << _ID;
        std::cout << "\nFirst Name : " << _FirstName;
        std::cout << "\nLast Name  : " << _LastName;
        std::cout << "\nFull Name  : " << GetFullName();
        std::cout << "\nEmail      : " << _Email;
        std::cout << "\nPhone      : " << _Phone;
        std::cout << "\n------------------------------------\n";
    }

    void SendEmail(std::string Subject, std::string Body)
    {
        std::cout << "\nThe following message sent successfully to email : " << _Email;
        std::cout << "\nSubject : " << Subject;
        std::cout << "\nBody : " << Body;
    }

    void SendSMS(std::string SMS)
    {
        std::cout << "\nThe following SMS sent successfully to phone : " << _Phone << std::endl;

        std::cout << SMS << std::endl;
    }
};

// Sub/Dervied Class
class clsEmployee : public clsPerson
{

private:
    float _Salary;
    std::string _Title;
    std::string _Department;

public:
    clsEmployee(int ID, std::string FirstName, std::string LastName, std::string Email, std::string Phone, float salary, std::string Title, std::string Department)
        : clsPerson(ID, FirstName, LastName, Email, Phone)
    {

        _Salary = salary;
        _Title = Title;
        _Department = Department;
    }

    // Salary
    void SetSalary(float Salary)
    {
        _Salary = Salary;
    }
    float GetSalary()
    {
        return _Salary;
    }
    // Title
    void SetTitle(std::string Title)
    {
        _Title = Title;
    }

    std::string GetTitle()
    {
        return _Title;
    }

    // Department
    void SetDepartmen(std::string Department)
    {
        _Department = Department;
    }

    std::string GetDepartment()
    {
        return _Department;
    }

    // Set My Own new print Function
    // it should take the same name and signature of the Print method in the super class (clsPerson)
    // this is called override
    void Print()
    {
        // Remember that you can't reach private members from the super calss
        // You can just reach Protected and public members
        std::cout << "Info :";
        std::cout << "\n------------------------------------";
        std::cout << "\nID         : " << ID();
        std::cout << "\nFirst Name : " << GetFirstName();
        std::cout << "\nLast Name  : " << GetLastName();
        std::cout << "\nFull Name  : " << GetFullName();
        std::cout << "\nEmail      : " << GetEmail();
        std::cout << "\nPhone      : " << GetPhone();
        // sub class private data members
        std::cout << "\nTitel      : " << _Title;
        std::cout << "\nDepartment : " << _Department;
        std::cout << "\nSalary     : " << _Salary;
        std::cout << "\n------------------------------------\n";
    }
};

class clsProgrammer : public clsEmployee
{
private:
    std::string _MainProgrammingLanguage;

public:
    clsProgrammer(int ID, std::string FirstName, std::string LastName, std::string Email, std::string Phone, float salary, std::string Title, std::string Department, std::string ProgLang)
        : clsEmployee(ID, FirstName, LastName, Email, Phone, salary, Title, Department)
    {
        _MainProgrammingLanguage = ProgLang;
    }

    void setMainProgrammingLanguage(std::string Language)
    {
        _MainProgrammingLanguage = Language;
    }
    std::string GetMainProgrmmingLanguage()
    {
        return _MainProgrammingLanguage;
    }

    void Print()
    {
        // Base clsperson
        std::cout << "Info :";
        std::cout << "\n------------------------------------";
        std::cout << "\nID                   : " << ID();
        std::cout << "\nFirst Name           : " << GetFirstName();
        std::cout << "\nLast Name            : " << GetLastName();
        std::cout << "\nFull Name            : " << GetFullName();
        std::cout << "\nEmail                : " << GetEmail();
        std::cout << "\nPhone                : " << GetPhone();
        // Sub clsEmployee*************************************************
        std::cout << "\nTitel                : " << GetTitle();
        std::cout << "\nDepartment           : " << GetDepartment();
        std::cout << "\nSalary               : " << GetSalary();
        // new class clsProgrammer*******************************************
        std::cout << "\nProgramming Language : " << _MainProgrammingLanguage;
        std::cout << "\n------------------------------------\n";
    }
};

int main()
{

    clsProgrammer Programmer1(10, "Ahmed", "Mohammed", "Ahmed@gmail.com", "023434543456", 2344, "Manager", "IT", "C++");
    Programmer1.Print();

    Programmer1.SendEmail("Hi", "How are you?");
    std::cout << std::endl;
    Programmer1.SendSMS("How are you?");

    std::cin.get();
}
