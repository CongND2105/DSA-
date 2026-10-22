#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int* p = &a;
    cout << "gia tri cua a: " << a << endl;
    cout <<"dia chi chi cua  a " << p << endl;
    cout << "gia tri cua p : " << *(p) << endl;
    return 0;
}
