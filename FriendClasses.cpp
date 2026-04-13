#include <iostream>

// by this method the classes can reach the (Private and Protected) members without inheritance
// note : we can reach private and protected members just in the same friend class of the first class but not outside (in the main function)
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

    friend class clsB; // Friend class
};

class clsB
{

public:
    void Display(clsA A1)
    {
        // here we can reach the private protected and public (members or methods)
        std::cout << "The Value of Var1 : " << A1._Var1 << std::endl;
        std::cout << "The Value of Var2 : " << A1.Var2 << std::endl;
        std::cout << "The Value of Var3 : " << A1._Var3 << std::endl;
    }
};

int main()
{
    clsA A1;

    clsB B1;

    B1.Display(A1);

    std::cin.get();
    return 0;
}