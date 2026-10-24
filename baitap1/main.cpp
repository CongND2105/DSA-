#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initData(float* a, int quantity);
void printArr(float* a, int quantity);
float sumArray(float* a, int quantity);

int main()
{
    srand(time(0));

    int minQuantity = 10 ;
    int maxQuantity = 20 ;

    int quantity = minQuantity + rand()% (maxQuantity - minQuantity +1 );

    float total;

    cout << "so luong ngau nhien : " << quantity << endl;

    float* a = new float[quantity];

    initData(a,quantity);
    printArr(a,quantity);
    total = sumArray(a,quantity);
    cout<<"Tong cac gia tri trong mang :"<< total << endl;
    delete [] a;
    return 0;
}

void printArr(float* a , int quantity)
{
    for(int i = 0 ; i < quantity ; i++){
        cout<< a[i]<< endl;
    }

}

void initData(float* a , int quantity)
{
     int minVal = -268;
     int maxVal = 339 ;



     for(int i = 0 ; i < quantity ; i ++){
        float randomFloat = (minVal * 100 + rand()% ((maxVal- minVal) * 100 + 1)) /100.0f;
        *(a + i) = randomFloat;
     }
}
float sumArray(float* a,int quantity)
{
    float sum = 0 ;
    for(int i = 0 ; i < quantity ; i++){
        sum = sum + *(a +i);
    }
    return sum;
}
