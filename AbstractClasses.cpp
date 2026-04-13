#include <iostream>

// Difference between overloading and overriding

// overloading : the functions take the same name with different (parameters) difference may be in (types - number - arrangement)

// overriding : the functions take the smae name and the same parameters with difference in definition (Redefinition) we use it when we make inheritance

// Abstract Calss (looks like the contract between two companies and it has a conditions)
// The conditions are the pure virtual functions
class clsMobile // we can't Definate any objects of this class
{
    // how to write a pure virtual function

    virtual void Dial(std::string PhoneNumber) = 0;
    virtual void SendSMS(std::string PhoneNumber, std::string Text) = 0;
    virtual void TakePicture() = 0;
    virtual int Sum(int a, int b) = 0;
};

class clsiPhone : public clsMobile
{
public:
    void Dial(std::string PhoneNumber) {

        // Any Code

    };

    void SendSMS(std::string PN, std::string T) {

    };

    void TakePicture() {

    };

    int Sum(int a, int b)
    {
        return a + b;
    };

    // after you write the pure functions you can do whatever you want

    // Any code here
};

class clsSamsungA10 : public clsMobile
{
public:
    void Dial(std::string PhoneNumber) {

    };

    void SendSMS(std::string PN, std::string T) {

    };

    void TakePicture() {

    };

    int Sum(int a, int b)
    {
        return a + b;
    };
};

int main()
{
    clsiPhone iPhone13;

    clsSamsungA10 S1;

    std::cin.get();
    return 0;
}