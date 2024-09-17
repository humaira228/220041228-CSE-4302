#include <iostream>

using namespace std;

int main(){
    int a,b,c,d;
    char x;

    cin>>a>>x>>b;
    cin>>c>>x>>d;

    int p =a*d + b*c;
    int q =b*d;

    cout<< p<<"/"<<q<<endl;
    return 0;

}
