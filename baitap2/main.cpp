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
    *(nv + 5) = {15,"Nguyen Van D", 8000000,26,0};
    *(nv + 6) = {16,"Nguyen Van F", 1000000,26,0};
    *(nv + 7) = {17,"Nguyen Van G", 5000000,26,0};
    *(nv + 8) = {18,"Nguyen Van H", 4000000,26,0};
    *(nv + 9) = {19,"Nguyen Van K", 3000000,26,0};
    *(nv + 10) = {20,"Nguyen Van DC", 2000000,12,0};
    return n = 11;
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
    float luong = nv->luongCB + nv->soNg *180000;
    float thuong = 0;
    float phuCap = 0;
    if(luong > 8000000){
        thuong = luong *0.05;
    }
    if(nv->luongCB < 5000000){
        phuCap = luong * 0.1;
    }
    nv->luongHT = luong + thuong + phuCap;
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

/* 4.Tính năng tính tổng lương hàng tháng mà công ty phải trả cho toàn bộ nhan viên
Input :
    + NhanVien
    + n
Output :
    + float total;
*/
float calculateTotalSalary(NhanVien* nv , int n){
    float total = 0;
    for (int i = 0 ; i < n ; i++){
        total = total + (nv+i)->luongHT;
    }
    return total;
}

/* 5.Tính năng tính tổng lương hàng tháng của những nhân viên có mức lương cơ bản < 5 triệu
Input :
    + NhanVien
    + n
Output :
    + float total;
*/
float calculateSalaryForLowIncome(NhanVien* nv , int n){
    float total = 0;
    for(int i = 0 ; i< n ; i++){
        if((nv+i)->luongCB<5000000){
            total = total + (nv + i )->luongHT;
        }
    }
    return total;
}
/* 6.tìm nhan viên theo mã nhân viên
Input :
    + NhanVien
    + n
    + maNV
Output :
    + NhanVien
*/

NhanVien* findByMaNV(NhanVien* nv , int n , int maNV){
    for(int i = 0 ; i < n ; i++){
        if((nv+i)->maNV == maNV){
            return (nv+i);
        }
    }
    return nullptr;
}

/* 7.tìm các nhân viên có lương hàng tháng tháp nhất
Input :
    + NhanVien
    + n
    +count
Output :
    + NhanVien* nvMinSalary
*/
NhanVien* findNVMinLuong(NhanVien* nv , int n , int& count){
    count = 0 ;
    float minLuong = nv->luongHT;

    for(int i = 0 ; i< n ; i++){
        if((nv+ i)->luongHT < minLuong){
            minLuong = (nv + i)->luongHT;
        }
    }

    for(int i = 0 ; i< n; i++){
        if((nv+i)->luongHT == minLuong){
            count++;
        }
    }
    
    NhanVien* nvMinSalary = new NhanVien[count];

    int index = 0;
    for(int i = 0; i< n ;i ++){
        if((nv+i)->luongHT == minLuong){
            *(nvMinSalary + index) = *(nv+i);
            index++;
        }
    }

    return nvMinSalary;

}
/* 8.tìm các nhân viên có lương cơ bản cao nhất
Input :
    + NhanVien
    + n
    +count
Output :
    + NhanVien* nvMinSalary
*/
NhanVien* findNVMaxLuongCB(NhanVien* nv, int n, int& count){
    count = 0 ;
    float maxLuongCB = nv->luongCB;

    for(int i = 0 ; i< n ; i++){
        if((nv+i)->luongCB > maxLuongCB){
            maxLuongCB = (nv+i)->luongCB;
        }
    }

    for(int i = 0 ; i< n ; i ++){
        if((nv+i)->luongCB == maxLuongCB){
            count ++;
        }
    }
    NhanVien* nvMaxLuongCB = new NhanVien[count];
    int index = 0;
    for(int i = 0 ; i< n ; i++){
        if((nv+i)->luongCB == maxLuongCB){
            *(nvMaxLuongCB + index) = *(nv+i);
            index++;
        }
    }

    return nvMaxLuongCB;

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
    cout<<"Test 3 . Tong luong phai tra cho toan bo nhan vien vao moi thang"<< endl;
    cout<< "Ket qua : " << calculateTotalSalary(nv,n)<<endl;
    cout<<"Test 4 . Tong luong phai tra cho toan bo nhan vien LuongCB < 5000000"<< endl;
    cout<< "Ket qua : " << calculateSalaryForLowIncome(nv,n)<<endl;
    cout<<"Test 5 . Tìm Nhân viên theo mã nhân viên"<< endl;
    int maNV;
    cout<< "Nhap vao ma nhan vien can tim : " <<endl ;
    cin>>maNV;
    cout<< "Ket qua : " <<endl;
    NhanVien* kq =(findByMaNV(nv,n,maNV));
    if(kq != nullptr){
        inNV(*kq);
    }else{
        cout<< "Khong tim thay Nhan vien"<<endl;
    }
    cout<<"Test 6 . Cac nhan vien hang thang co luong thap nhat"<< endl;
    int minCount;
    NhanVien* listMin = findNVMinLuong(nv,n,minCount);
    cout<< "Ket qua : "<<endl;
    printArrNv(listMin,minCount);
     cout<<"Test 7 . Cac nhan vien co luong co ban cao nhat"<< endl;
    int maxCount;
    NhanVien* listMax = findNVMaxLuongCB(nv,n,maxCount);
    cout<< "Ket qua : "<<endl;
    printArrNv(listMax,maxCount);

    delete[] listMin;
    delete[] listMax;
    delete[] nv;
    listMin = nullptr;
    listMax = nullptr;
    nv = nullptr;

    return 0;
}