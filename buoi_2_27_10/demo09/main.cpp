#include <iostream>

using namespace std;
typedef struct ToaDo
{
    float x;
    float y;
}Diem;

void inToaDo(ToaDo t){
    cout<<"("<< t.x<< ";" << t.y << ")" << endl;
}

void inToaDoV2(ToaDo* p){
    //cout<<"("<< (*p).x<< ";" << (*p).y << ")" << endl;
    cout<<"("<< p->x << ";" << p->y << ")" << endl;
}

void inMangTD(ToaDo* a , int n ){

    for(int i = 0 ; i < n ; i++){
        inToaDoV2(a+i);
    }
}

int main()
{
    new int[100]{2,5,6,1,2};
    ToaDo* a = new ToaDo[100]{{2,3},{4,6},{5,7},{2,1},{1,5}};
    int n = 5;

    inMangTD(a,n);
    return 0;
}
