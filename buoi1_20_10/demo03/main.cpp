#include <iostream>

using namespace std;

int main()
{
    int* p = new int;
    int result = *p = 2010;
    cout << "Gia tri cua p : " << result<< endl;
    float* p1 = new float(21.5);
    cout<<"Gia tri cua p1 : " << *p1 << endl;
    cout<< "dia chi cua p1 : " << p1 << endl;
    return 0;
}
