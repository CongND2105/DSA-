#include <iostream>

using namespace std;


void initData(int* a, int* n)
{
    *a = 12;
    *(a + 1) = 24 ;
    *(a + 2) = 48 ;
    *(a + 3) = 58 ;
    *n = 4 ;

}
void printArr(int* a, int* n)
{
    for(int i = 0 ; i < *n ; i++){
        cout<< a[i] << endl;
    }
}


int main()
{
    //ARRAY 1 chieu, tao mang voi cap phat dong

    int* a = new int[10];
    int* n = new int ;
    cout<<a<< endl;
    cout<< n << endl;

    initData(a,n);
    printArr(a,n);

    delete[] a;
    a = nullptr;
    delete n ;
    n = nullptr;
    return 0;
}
