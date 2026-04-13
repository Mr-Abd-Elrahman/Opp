#include <iostream>

class clsA
{
private:
    int Var;
    void Fun1()
    {
        std::cout << "Function1\n";
    }

protected:
    int var2;
    void Func2()
    {
        std::cout << "Function2\n";
    }

public:
    int Var3;
    void Func3()
    {
        std::cout << "Function3\n";
    }
};

// the first normal mode
class clsB : protected clsA
{

public:
    void Class_B_Function()
    {
        clsA::Func3();
        std::cout << "Hi, I'm the function in claas B\n";
    }
};

class clsC : public clsB
{
public:
    void Function()
    {
        clsB::Func3();
    }
};

class clsD : public clsC
{
public:
    void ff()
    {
        clsC::Func2();
    }
};
int main()
{
}
