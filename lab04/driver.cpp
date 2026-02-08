// TO DO: Implement the driver main() function to test your code.
#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;

int main() {
    cout << "\nINT LIST TESTS\n";
    cout << "----------------\n";

    LinkedList<int> list;

    cout << list;
    cout << "Length: " << list.getLength() << endl;
    cout << "Is empty: " << list.isEmpty() << endl;

    try {
        list.getElement(0);
    } catch (string& e) {
        cout << e << endl;
    }

    try {
        list.remove(0);
    } catch (string& e) {
        cout << e << endl;
    }

    list.append(10);
    list.append(20);
    list.append(30);
    cout << list;

    cout << list.getElement(0) << endl;
    cout << list.getElement(2) << endl;

    list.replace(1, 99);
    cout << list;

    list.insert(0, 5);
    cout << list;

    list.insert(list.getLength(), 100);
    cout << list;

    list.insert(2, 77);
    cout << list;

    list.remove(0);
    cout << list;

    list.remove(2);
    cout << list;

    list.remove(list.getLength() - 1);
    cout << list;

    list.clear();
    cout << list;

    cout << "\nSTRING LIST TESTS\n";
    cout << "----------------\n";

    LinkedList<string> sList;
    sList.append("Aditi");
    sList.append("CS student");
    sList.append("linked list");
    cout << sList;

    sList.insert(1, "working on");
    cout << sList;

    sList.replace(2, "learning C++");
    cout << sList;

    sList.remove(0);
    cout << sList;

    return 0;
}
