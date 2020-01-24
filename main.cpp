#include<iostream>
using namespace std;

class Data
{
    void xyz(void)
    {
        cout<< "This is xzy class\n";
    }
    static int b;

public:
    int a;
    void abc(void)
    {
        xyz();
        cout<< "b= "<<b;
        cout<< "\nThis is abc with xyz\n";
    }
};
static Data::b = 20;
int main()
{
    Data obj;
    cout<< "Enter Value for a: ";
    cin>> obj.a;
    obj.abc();
    cout<< obj.a;

    return 0;
}
