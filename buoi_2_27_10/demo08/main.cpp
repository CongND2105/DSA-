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
    cout<<"("<< (*p).x<< ";" << (*p).y << ")" << endl;
    cout<<"("<< p->x << ";" << p->y << ")" << endl;
}

int main()
{

    int* p1 = new int(10);
    cout<< *p1 << endl;

    ToaDo* p2 = new ToaDo({1.2,3});
    inToaDoV2(p2);
    return 0;

}
