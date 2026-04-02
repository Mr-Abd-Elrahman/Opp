#include <iostream>

class clsA
{
private:
    // only accessable inside the class it self neither in inherites class nor outside class
    int _Var1;
    void Function1()
    {
        std::cout << "Function1\n";
    }

protected:
    // accessable inside the class and inside inherites class but not outside
    int _Var2;
    void Function2()
    {
        std::cout << "Function2\n";
        Function1();
    }

public:
    // accessable every where
    int _Var3;
    void Function3()
    {
        std::cout << "Function3\n";
    }
};

class clsB : public clsA
{
public:
    void Function_1_B()
    {
        clsA::Function2();
    }
};

int main()
{
    clsB B1;
    B1.Function3();
    B1.Function_1_B();
}