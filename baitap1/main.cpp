#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void initData(float* a, int quantity);
void printArr(float* a, int quantity);
float sumArray(float* a, int quantity);
void sumAndProduct(float* a, int quantity,float* outSum, float* outProduct);
int countOccurrences(float* a, int quantity,float* input);
int main()
{
    srand(time(0));

    int minQuantity = 10 ;
    int maxQuantity = 20 ;

    float total;

    float* outSum = new float;
    float* outProduct = new float;

    float* input = new float;

    int quantity = minQuantity + rand()% (maxQuantity - minQuantity +1 );

    cout << "so luong ngau nhien : " << quantity << endl;

    float* a = new float[quantity];

    initData(a,quantity);
    printArr(a,quantity);
    total = sumArray(a,quantity);
    sumAndProduct(a,quantity,outSum,outProduct);
    cout<<"Tong cac gia tri trong mang (sumAndProduct) : " << *outSum << endl;
    cout<<"Tich cac gia tri trong mang (sumAndProduct) : " << *outProduct << endl;
    cout<<"Tong cac gia tri trong mang :"<< total << endl;
    int count = countOccurrences(a,quantity,input);
    cout<<"So lan xuat hien cua :"<< *input<< " la : " <<count << endl;
    delete [] a;
    delete outProduct;
    delete outSum;
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
void sumAndProduct(float* a , int quantity, float* outSum, float* outProduct){
    *outSum = 0.0;
    *outProduct = 1.0 ;
    for(int i = 0; i < quantity; i ++){
        *outSum = *outSum + *(a + i);
        *outProduct = *outProduct * *(a + i);
    }
}
int countOccurrences(float* a, int quantity,float* input){
    cout << "Nhap vao so can dem : ";
    cin >> *input;

    int count = 0 ;

    for(int i = 0 ; i< quantity ; i++){
        if(*input == *(a + i)){
            count ++ ;
        }
    }
    return count;
}
