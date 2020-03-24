/*
This C++ program will take inputs from the user and check for the greatest number!.
it will also save the results in a text file called as the "Test.txt".
*/

#include <iostream>
#include<fstream>

using namespace std;

template<class Big>
class Test
{

public:

    Big a, b;

    template<class S>
    string smaller(S num1, S num2)
    {
        num1 = a;
        num2 = b;

        if(num1 > num2)
            return num1;

        return num2;
    }
};



int main(void)
{
    Test<string> t1;                /// This is an object of template class Test(t1)

    ofstream my_file("Test.txt");   /// This is a constructor of ofstream function from the fstream header file.
                                    /// This opens the file with the given name or file not present then will create one.


    if(my_file.is_open())           /// The is_open() is boolean function which is used to check if the file is open.
        cout<< "The File is Open!"<<endl;
    else
        cout<< "Error opening the File!"<<endl;

    cout<< "Hit ctrl+z to exit !"<<endl;

    while(cin>> t1.a >> t1.b)       /// The input from the user will be directly taken and the loop will terminate at the end of the file.
    {
        my_file << t1.a << " ? " << t1.b << " : Bigger -> " << t1.smaller(t1.a, t1.b) << endl ;
        cout<< "= " << t1.smaller(t1.a, t1.b) << endl;
    }
}
