#include <iostream>
#include "sharedptr.h"

using std::cout;
using std::endl;
using std::string;

void PrintValueAndReferenceCount(const SharedPtr<int>& number) {
    cout << "Number: " << *number << endl;
    cout << "Reference count: " << number.getCount() << endl;
}

void ChangeValue(const SharedPtr<int>& number, int newValue) {
    *number = newValue;
}

int main() {

    std::cout << "Hello, World! demo of shared pointer implementation" << std::endl;

    int *magicNumber = new int(69);
    int *meaningOfLife = new int(42);

    const SharedPtr<int> magicNumberSharedPtr(magicNumber);
    const SharedPtr<int> meaningOfLifeSharedPtr(meaningOfLife);
    const SharedPtr<string> stringSharedPtr(new string("Hello, World!"));

    if(stringSharedPtr)
    {
        cout << "String is valid and contains " << *stringSharedPtr << endl;
    }
    SharedPtr <std::string > sp(new std:: string("Hello"));
    SharedPtr <std::string > sp2(new std:: string("world"));

    if(sp == sp2)
        cout << "sp == sp2" << endl;
    else
        cout << "sp != sp2" << endl;

    sp = sp2;
    
    if (sp == sp2)
        cout << "sp == sp2" << endl;
    else
        cout << "sp != sp2" << endl;

    int x = sp2 << 1; // bool is not an int and should not be treated as one.

    PrintValueAndReferenceCount(meaningOfLifeSharedPtr);
    PrintValueAndReferenceCount(magicNumberSharedPtr);

    {
        const SharedPtr<int> meaningOfLifeSharedPtrScoped(meaningOfLifeSharedPtr);
        PrintValueAndReferenceCount(meaningOfLifeSharedPtrScoped);

        const SharedPtr<int> magicNumberSharedPtr2 = magicNumberSharedPtr;
        ChangeValue(magicNumberSharedPtr2, 42069);
        PrintValueAndReferenceCount(magicNumberSharedPtr2);
        const SharedPtr<int> magicNumberSharedPtr3 = magicNumberSharedPtr2;
        PrintValueAndReferenceCount(magicNumberSharedPtr3);
        {
            const SharedPtr<int> magicNumberSharedPtr4 = magicNumberSharedPtr;
            const SharedPtr<int> magicNumberSharedPtr5 = magicNumberSharedPtr4;
            ChangeValue(magicNumberSharedPtr5, 17);
            PrintValueAndReferenceCount(magicNumberSharedPtr4);
        }

        PrintValueAndReferenceCount(magicNumberSharedPtr2);

    }
    PrintValueAndReferenceCount(meaningOfLifeSharedPtr);
    PrintValueAndReferenceCount(magicNumberSharedPtr);




    return 0;
}
