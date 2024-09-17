#include <iostream>
#include <iomanip>

using namespace std;

struct frac {
    int num;
    int den;
};

int main(){
    frac n1, n2,n3;
    char x;
    cin>>n1.num>>x>>n1.den;
    cin>>n2.num>>x>>n2.den;

    n3.num=n1.num * n2.den + n1.den * n2.num;
    n3.den=n1.den * n2.den;

    cout<<n3.num<<"/"<<n3.den;

}
