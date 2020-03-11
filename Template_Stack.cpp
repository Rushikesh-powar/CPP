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
    stack<int> s1,s2;
    int i;

    s1.Push('R');
    s2.Push('P');
    s1.Push('u');
    s2.Push('o');
    s1.Push('s');
    s2.Push('w');
    s1.Push('h');
    s2.Push('a');
    s1.Push('i');
    s2.Push('r');

    for(i=0 ; i<5 ; i++)
    {
        cout<< "POP: "<< s1.Pop()<<endl;
        cout<< "POP2: "<< s2.Pop()<<endl;
    }
}



























































