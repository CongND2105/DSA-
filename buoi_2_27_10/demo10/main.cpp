#include <iostream>
#include <iomanip>
using namespace std;

typedef struct NhanVien{
    int maNV;
    string hoTenNV;
    float luongCB;
    int soNg;
    float luongHT;
}NV;

/* Tính năng in ra Nhan Vien
Input :
    + NhanVien
Output :
    + none
*/

void inNV(NhanVien nv){
    cout<< "Ma Nhan Vien : " << nv.maNV << endl;
    cout<< "Ho Ten NV  : " << nv.hoTenNV << endl;
    cout << "Luong Co Ban : " << fixed << setprecision(0) << nv.luongCB << endl;
    cout<< "So Ngay lam viec : " << nv.soNg << endl;
    cout << "Luong Hang Thang: " << fixed << setprecision(0) << nv.luongHT << endl;
}

/* Tính năng đưa data vào Nhan Vien
Input :
    + NhanVien
    + n 
Output :
    + int n (số lượng nhân viên)
*/

int initData(NhanVien* nv, int& n){
    *nv ={10,"Nguyen Van teo",2000000,20,0};
    *(nv + 1) = {11,"Nguyen Van A", 8000000,24,0};
    *(nv + 2) = {12,"Nguyen Van B", 5000000,21,0};
    *(nv + 3) = {13,"Nguyen Van C", 2000000,12,0};
    *(nv + 4) = {14,"Nguyen Van D", 3000000,26,0};
    *(nv + 5) = {15,"Nguyen Van D", 3000000,26,0};
    *(nv + 6) = {16,"Nguyen Van F", 1000000,26,0};
    *(nv + 7) = {17,"Nguyen Van G", 5000000,26,0};
    *(nv + 8) = {18,"Nguyen Van H", 4000000,26,0};
    *(nv + 9) = {19,"Nguyen Van K", 3000000,26,0};
    return n = 10;
}

/* Tính năng in ra tất cả Nhan Vien
Input :
    + NhanVien
    + n
Output :
    + none
*/

void printArrNv(NhanVien* nv, int n){
    for (int i = 0 ; i < n ; i ++){
        inNV(*(nv+i));
        cout<< "==============================="<<endl;
    }
}
/* Tính năng tính lương nhân viên
Input :
    + NhanVien
    + n
Output :
    + none
*/
void tinhLuongNV(NhanVien* nv){
    float luongChuaThuong = nv->luongCB + nv->soNg *180000;
    if(luongChuaThuong > 8000000){
        nv->luongHT = luongChuaThuong + (luongChuaThuong * 0.05);
    }else if(luongChuaThuong < 5000000){
        nv->luongHT = luongChuaThuong + (luongChuaThuong * 0.1);
    }
    else{
        nv->luongHT = luongChuaThuong;
    }
}
/* Tính năng tính lương nhân viên hàng tháng
Input :
    + NhanVien
    + n
Output :
    + none
*/
void luongHT(NhanVien* nv , int n){
    for(int i = 0 ; i < n ; i++){
        tinhLuongNV(nv+i);
    }
}

int main(){
    int n = 0;
    NhanVien* nv = new NhanVien[1000];
    cout<<"Test 1 . Du lieu duoc tao :"<< endl;
    cout<< "Ket qua : " <<endl;
    cout<<initData(nv,n)<< endl;
    printArrNv(nv,n);
    cout<<"Test 2 . Sau Khi da tinh luong"<< endl;
    cout<< "Ket qua : " <<endl;
    luongHT(nv,n);
    printArrNv(nv,n);
    return 0;
}