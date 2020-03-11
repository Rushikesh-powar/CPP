#include <iostream>
#define SIZE 10

using namespace std;

template<class stacktype> class stack
{
    stacktype stck[SIZE];
    int TOS;

public:
    stack()
    {
        TOS = 0;
    }
    void Push(stacktype ob);
    stacktype Pop();
};

template<class stacktype >void stack <stacktype>:: Push(stacktype ob)
{
    if(TOS == SIZE)
        cout<< "Stack Overflow"<<endl;
    else
    {
        stck[TOS] = ob;
        TOS++;
    }
}

template<class stacktype >stacktype stack <stacktype>:: Pop()
{
    if(TOS < 0)
        cout<< "Stack Underflow"<<endl;
    else
    {
        TOS--;
    }
    return stck[TOS];
}

int main(void)
{
    stack<string> s1,s2;
    string str;
    int i=1,store,op;

    cout<< "Enter Your choice: ";

    while(i == 1)
    {
        cout<< "\n1.Push \n2.Pop \nAns: ";
        cin>> op;

        if(op == 1)
        {
            cout<< "Enter the element to Push: ";
            cin>> str;
            s1.Push(str);
        }
        if(op == 2)
        {
            cout<< "POP: "<< s1.Pop()<<endl;
        }
        cout<< "Enter 1 to continue: ";
        cin>> i;
    }
}



























































