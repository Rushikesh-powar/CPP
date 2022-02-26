#include <bits/stdc++.h>
#include "Array.h"

int main()
{
    using namespace std;
    // Array declarations.
    // Array<int, 5> a{1, 2, 3, 4, 5};
    // Array<int, 5> a({1, 2, 3, 4, 5});
    int ar[] = {1};
    Array<int, 1> a(ar);

    // Array Functions.
    // cout << a.getValue(8) << "\n";
    // a.print_array();
    // cout << a.len() << "\n";
    // cout << a.getKey(4) << "\n";
    // cout << a.getValue(0) << "\n";
    // a.append(45);
    // a.setItem(0, 45);
    // a.sort();
    // a.delKey(0);
    // a.delValue(5);
    // a.printArray();

    // Array<string, 3> a({"Rushi", "powar"});
    // a.setItem(2, "rp");
    // a.printArray();
    int op{};
    int x{}, id{};
    bool run = true;
    while (run)
    {
        cout << "ENTER YOUR CHOICE:"
             << "\n"
             << "1.Print Array\n"
             << "2.Print Array length\n"
             << "3.Add Element\n"
             << "4.Set Element at index\n"
             << "5.Delete Index\n"
             << "6.Delete Element\n"
             << "7.Get Value at index\n"
             << "8.Get Index of value\n"
             << "9.Sort Ascending\n"
             << "10.Sort Decending\n"
             << "11.Exit\n"
             << "Ans: ";

        cin >> op;
        switch (op)
        {
        case 1:
            a.printArray();
            break;
        case 2:
            cout << a.len() << "\n";
            break;
        case 3:
            cout << "Enter a Value: ";
            cin >> x;
            a.append(x);
            break;
        case 4:
            cout << "Enter index: ";
            cin >> id;
            cout << "Enter a Value: ";
            cin >> x;
            a.setValue(id, x);
            break;
        case 5:
            cout << "Enter index: ";
            cin >> id;
            a.delKey(id);
            break;
        case 6:
            cout << "Enter a Value: ";
            cin >> x;
            a.delValue(x);
            break;
        case 7:
            cout << "Enter index: ";
            cin >> id;
            cout << a.getValue(id) << "\n";
            break;
        case 8:
            cout << "Enter a Value: ";
            cin >> x;
            cout << a.getKey(x) << "\n";
            break;
        case 9:
            a.sort(false);
            break;
        case 10:
            a.sort(true);
            break;
        case 11:
            run = false;
            break;
        }
    }
    return 0;
}