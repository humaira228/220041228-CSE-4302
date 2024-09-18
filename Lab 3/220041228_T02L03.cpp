#include <iostream>
using namespace std;

class RationalNumber{
private:
    int num;
    int den;

public:
    RationalNumber(): num(0),den(1){}

    void assign(int n, int d){
        if(den==0){
            cout<<"You cannot assign 0 as denominator"<<endl;

        }
        else{
       num=n;
       den=d;
        }

    }

   void convert(){
      float res= (float(num)/float(den));
      cout<<res<<endl;
    }

    void invert(){
         if(den==0){
            cout<<"You cannot assign 0 as denominator"<<endl;
            return;
        }
        int temp;
        temp=num;
        num=den;
        den=temp;


    }

    void print(){
        cout<<"The rational number is : "<<num<<"/"<<den<<endl;
    }
};
int main(){
    RationalNumber rn;
    rn.assign(3,2);
    rn.print();
    rn.convert();
    rn.invert();
    rn.print();

}

