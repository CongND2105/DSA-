#include <iostream>

using namespace std;

int main()
{
    //thu hoi , delete
    int* p = new int(6789);

    cout<< p << endl;
    cout << *p << endl;

    delete p;
    cout<< "sau khi thu hoi" << endl;
    cout<< p << endl;
    cout << *p << endl;
    return 0;
}
