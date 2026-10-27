#include <iostream>

using namespace std;

struct ToaDo
{
    float x;
    float y;
};
typedef ToaDo Diem;

void inToaDo(ToaDo t){
    cout<<"("<< t.x<< ";" << t.y << ")" << endl;
}

int main()
{
    int n;
    cout<< n << endl;

    ToaDo a = {2,3},b ={5,6};
    inToaDo(a);
    inToaDo(b);
    return 0;
}
