#include<bits/stdc++.h>
using namespace std;

class Account{
    protected:
    string accountNo;
    string accountName;
    float balance;

    public:
    Account get(){
        return *this;
    }
    void set(string accNo, string accName, float bal){
        accountNo=accNo;
        accountName=accName;
        balance=bal;
    }

    void description(){
        cout<<"accountNo: "<<accountNo<<endl;
        cout<<"accountName: "<<accountName<<endl;
        cout<<"balance: "<<balance<<endl;
    }


};

class CurrentAccount:public Account{
    private:
    const static int serviceCharge=100;
    const static int accountPrefix=100;
    static int nextAccount;

    static int nexAccountNo(){
        return nextAccount;
    }

    public:

    CurrentAccount():{
        accountNo=accountPrefix-nextAccount;
    }
    
    CurrentAccount get(){
        return *this;
    }

    void set(int nextAcc){
        nextAccount=nextAcc;

    }

    void description(){
        cout<<"serviceCharge: "<<serviceCharge<<endl;
        cout<<"accountPrefix: "<<accountPrefix<<endl;
        cout<<"nextAccount: "<<nextAccount<<endl;
    }



};


class SavingsAccount:public Account{
    private:
    double interestrate;
    double monthlyDepositAmount;
    const static int accountPrefix=200;
    static int nextAccount;

    static int nexAccountNo(){
        return nextAccount;
    }

    public:
    SavingsAccount get(){
        return *this;
    }
    void set(double iRate, double monDepo,int nextAcc){
        interestrate=iRate;
        monthlyDepositAmount=monDepo;
        nextAccount=nextAcc;

    }

    void description(){
        
    }


};

class monthlyDepositScheme:public Account{
    protected:
    double interestrate;
    double monthlyDepositAmount;
    const static int accountPrefix=300;
    static int nextAccount;

    static int nexAccountNo(){
        return nextAccount;
    }

    public:
    monthlyDepositScheme get(){
        return *this;
    }
    void set(double iRate, double monDepo,int nextAcc){
        interestrate=iRate;
        monthlyDepositAmount=monDepo;
        nextAccount=nextAcc;

    }

};

class LoanAccount{
    private:
    double interestrate;
    double monthlyDepositAmount;
    const static int accountPrefix=900;
    static int nextAccount;

    static int nexAccountNo(){
        return nextAccount;
    }

    public:
    LoanAccount get(){
        return *this;
    }
    void set(double iRate, double monDepo,int nextAcc){
        interestrate=iRate;
        monthlyDepositAmount=monDepo;
        nextAccount=nextAcc;

    }

};

class TwoYearMDS:public monthlyDepositScheme{
    private:
    int maximumInterest;

    public:
    int get(){
        return maximumInterest*2;
    }

    void set(int mi){
        maximumInterest=mi;
    }
};

class FiveYearMDS:public monthlyDepositScheme{
    private:
    int maximumInterest;

    public:
    int get(){
        return maximumInterest*5;
    }

    void set(int mi){
        maximumInterest=mi;
    }
};

class InitialDepositMDS:public monthlyDepositScheme{
    private:
    int maximumInterest;
    double initialDepositAmount;

    public:
    InitialDepositMDS get(){
        return *this;
    }

    void set(int mi, int inDep){
        maximumInterest=mi;
        initialDepositAmount=inDep;

    }
};

int CurrentAccount::nextAccount=0;



int main(){
    Account a1;
    a1.set("123", "Raihan",  500.00);
    a1.description();

     CurrentAccount ca1;
    ca1.set(1234);
    ca1.description();

       SavingsAccount sa;
    monthlyDepositScheme mds;
    
    LoanAccount la;
    
    TwoYearMDS tym;
    FiveYearMDS fym;
    


}
