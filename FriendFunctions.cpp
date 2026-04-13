#include <iostream>

// by this method the non membered function (outside the class) can reach the (Private and Protected) members of the class
// note : we can reach private and protected members just in the function that is the friend of the class but not outside (in the main function)
class clsA
{
private:
    int _Var1 = 0;

protected:
    int _Var3 = 0;

public:
    int Var2 = 0;

    clsA()
    {
        _Var1 = 10;
        Var2 = 20;
        _Var3 = 30;
    }

    friend int MySum(clsA A1); // friend function
};

int MySum(clsA A1)
{
    return A1._Var1 + A1.Var2 + A1._Var3;
}

int main()
{

    clsA A1;

    std::cout << "Sum : " << MySum(A1) << std::endl;
    std::cin.get();
}
