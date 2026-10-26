#include <iostream>

using namespace std;

void checkEvenOdd(float* a , int n , float* even,int& evenCount, float* odd, int& oddCount);
void printArr(float* a , int quantity);
int minInArr(float* a , int n);
void reverseArray(float* a , int n);
int quantity
int main()
{
    //so luong phan tu trong mang
    int n = 6;
    //khai bao mang
    float* a = new float[n]{5.5f, 7.2f, 1.3f, 12.22f, 25.92f, 42.12f};
    //khai bao mang chua cac phan tu chan
    float* even = new float[n];
    //khai bao mang chua cac phan tu le
    float* odd = new float[n];

    //print arr
    cout<< "mang a : ";
    printArr(a,n);
    reverseArray(a,n);
    cout<< "mang da duoc dao nguoc : ";
    printArr(a,n);

    //khai bao 2 bien dem de thuc hien ghi tung phan tu vao mang even,odd
    int evenCount = 0;
    int oddCount = 0;

    checkEvenOdd(a,n,even,evenCount,odd,oddCount);
    cout<< "cac phan tu chan : ";
    printArr(even,evenCount);
    cout<< "cac phan tu le : ";
    printArr(odd,oddCount);

    cout<< "Vi tri phan tu nho nhat trong mang : " << minInArr(a,n)<< endl;

    delete[] a;
    delete[] even;
    delete[] odd;
    return 0;
}

void checkEvenOdd(float* a , int n , float* even,int& evenCount, float* odd, int& oddCount){

    for(int i = 0 ; i < n ; i++){
        if((int)*(a + i) %2 == 0 ){
            *(even + evenCount ) = *(a + i );
            evenCount ++;
        }else{
            *(odd + oddCount) = *(a +i);
            oddCount ++ ;
        }
    }
}

void printArr(float* a, int quantity){
    for(int i = 0 ; i < quantity ; i ++){
        cout<< *(a + i) << " " ;
    }
    cout << endl;
}

int minInArr(float* a , int n){
    int indexMin = 0;
    float minValue = *a;
    for (int i = 0 ; i< n ; i++){
        if(*(a + i) < minValue){
            minValue = *(a + i);
            indexMin = i ;
        }
    }
    return indexMin;
}

void reverseArray(float* a , int n){
    int left = 0 ;
    int right = n - 1;

    while(left < right){
        float temp = *(a + left);
        *(a + left) = *(a + right);
        *(a+ right) = temp;

        left ++;
        right -- ;
    }
}


