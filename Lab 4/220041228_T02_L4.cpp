#include<iostream>
#include<cstring>
using namespace std;

class BankAccount{
    private:
    int accNo;
    string accHolderName;
    string accType;
    float curBal;
    const float minBalance;

    static int totAcc;
    static int activeAcc;
    static float totTax;

    public:
    BankAccount(int accNum, string Name, string type,float balance,float minBal):
    accNo(accNum),accHolderName(Name), accType(type),curBal(balance),minBalance(minBal){
        totAcc++;
        activeAcc++;
    }
    
    ~BankAccount(){
        cout<<"Account Of "<<accHolderName<<" Is Destroyed "<<endl;
        activeAcc--;
    }

    void showInfo(){
        cout<<"Account Number: "<<accNo<<endl;
        cout<<"Account Holder name: "<<accHolderName<<endl;
        cout<<"Account Type: "<<accType<<endl;
        cout<<"Current Balance: "<<curBal<<endl;
        cout<<"Minimum Balance: "<<minBalance<<endl;
    }
    void showBalance(){
        cout<<"Current Balance: "<<curBal<<endl;

    }

    void deposit(float amount){
        if(amount<0)
        cout<<"Invalid Deposit"<<endl;
        else{
            curBal+=amount;
        }
    }

    void withdrawal(float amount){
        if(amount<0)
        cout<<"Invalid Withdrawal"<<endl;
        else if(curBal-amount<minBalance)
        cout<<"Invalid Withdrawal"<<endl;
        else{
            curBal-=amount;
        }
    }

    void giveInterest(float rate= 3.0){
        float interest = (curBal*rate) / 100;
        float sourceTax = interest * 0.10;
        totTax += sourceTax;
        interest -= sourceTax;
        curBal += interest;
    }
    float getBalance()const{
        return curBal;
    }

  
    static int getTotAcc() {
        return totAcc;
    }
    static int getActiveAcc() {
        return activeAcc;
    }
    static float getTotTax() {
        return totTax;
    }



    
};
    int BankAccount::totAcc=0;
    int BankAccount::activeAcc=0;
    float BankAccount::totTax=0;

    void display_stat(){
        cout<<"Total number of BankAccount created:"<<BankAccount::getTotAcc()<<endl;
        cout<<"total number of active: "<<BankAccount::getActiveAcc()<<endl;
        cout<<"total number of Tax collected: "<<BankAccount::getTotTax<<endl;
    }

BankAccount larger(const BankAccount A, const BankAccount B){
    if(A.getBalance()>B.getBalance())
    return A;
    else return B;
}

int main(){
    BankAccount a1(228, "Rubaid","Savings",2000.0,100.0);
    BankAccount a2(202,"Neil","Savings",5000.0,200.0);
    
    a1.showInfo();
    a2.showInfo();

    a1.deposit(200);
    a1.withdrawal(50);

    a1.giveInterest();

    display_stat();



}





