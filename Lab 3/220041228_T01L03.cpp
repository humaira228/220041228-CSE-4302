#include <iostream>
using namespace std;

class Counter{
private:
    int cnt;
    int step;
public:
   // Counter(): cnt(0),step(1){}

    void setIncrementStep(int st){
        step=st;
    }

    int getCount(){
        return cnt;
    }

    void increment(){
        cnt+=step;
    }
    void resetCount(){
        cnt=0;
    }
    void show(){
        cout<<"Count "<<cnt<<endl;
        cout<<"Current Step "<<step<<endl;
    }
};

int main(){
    Counter cr;

    cr.setIncrementStep(3);
    //cr.show();
    cr.increment();
    cr.show();


    cr.getCount();
    cr.resetCount();
    cr.show();

}
