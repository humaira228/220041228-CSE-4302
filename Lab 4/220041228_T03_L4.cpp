#include<iostream>
#include<cstring>

using namespace std;

class Employee{
    private:
    string EmpName;
    int ID;
    int Age;
    int Salary;

    void getStatus(){
        if(Age<=25 ){
            if(Salary<=20000)
            cout<<"Low";
            else
            cout<<"Moderate"<<endl;


        }
        else if(Age>25){
            if(Salary<=21000)
            cout<<"Low"<<endl;
            else if(Salary>21000 && Salary<=60000)
            cout<<"Moderate"<<endl;
            else if(Salary>60000)
            cout<<"High";
        }

    }

    public:
    void FeedInfo(){
       cout<<"Enter Employee Name:";
        cin.ignore();
        getline(cin,EmpName);
        cout<<"Enter Id:";
        cin>>ID;
        cout<<" Enter Salary: ";
        cin>>Salary;
        cout<<"Enter Age :";
        cin>>Age;
    }
    
    void showInfo(){
        cout<<"Employee Name:"<<EmpName<<endl;
        cout<<"Id:"<<ID<<endl;
        cout<<"Salary: "<<Salary<<endl;
        cout<<"Age: "<<Age<<endl;
    

    getStatus();

    }
};

int main(){
    Employee employee;
    employee.FeedInfo();
    employee.showInfo();


}