#include<fstream>
#include<iostream>
#include<typeinfo>
using namespace std;
#include <process.h>

const int LEN=32;
const int MAXEM=100;

enum employee_type{tmanager, tscientist, tlaborer};

class employee{
    private:
    char name[LEN];
    unsigned long number;
    static int n;
    static int n;
    static employee* arrap[];

    public:

    virtual void getdata(){
        cin.ignore(10, '\n');
        cout<<"  Enter last name: "; cin>>name;
        cout<<"  Enter number: "; cin>>number;

    }
     virtual void putdata(){
        
        cout<<"\n  Name: " <<name;
        cout<<"\n  Number: " <<number;
        
    }
    virtual employee_type get_type();
    static void add();
    static void display();
    static void read();
    static void write();

};

int employee::n;
employee* employee:: arrap[MAXEM];

class manager: public employee{
    private:
    char title[LEN];
    double dues;
    public:
    void getdata(){
        employee::getdata();
        cout<<"  Enter title: ";
        cout<<"  Enter golf club dues: ";cin>>dues;
    }

    void putdata(){
        employee::putdata();
        cout<<"\n  Title: "<< title;
        cout<<"\n  Golf club dues: "<< dues;
    }


    
};

class scientist:public employee{

    private:
    int pubs;
    public:
    void getdata(){
        employee::getdata();
        cout<<"  Enter number of pubs: ";cin>>pubs;
    
    }
    void putdata(){
        employee::putdata();
        cout<<"\n  Number of publications:" << pubs;
    
    }

};

class laborer: public employee{

};

void employee::add(){
    char ch;
    cout<<"'m' to add a manager"
          "\n's' to a scientist"
          "\n'l' to add a laborer"
          "nEnter selection: ";

        cin>>ch;
        switch(ch)
        {
            case'm':arrap[n]=new manager; break;
            case's':arrap[n]=new scientist; break;
            case'l':arrap[n]=new laborer; break;
            default:cout<<"\nUnknown employee type\n"; return;
        }

        arrap[n++]->getdata();

        }

        void employee:: display(){

        for(int j=0; j<n; j++){
        cout<<(j+1);
        switch(arrap[j]->get_type())
        {
        case tmanager:cout<<". Type:Manager"; break;
        case tscientist:cout<<". Type:Manager"; break;
        case tlaborer:cout<<". Type:Manager"; break;
        default:cout<<". Unknown type";
        }
        arrap[j]->putdata();
        cout<<endl;
        
        }
        }
        employee_type employee::get_type(){
        if(typeid(*this) == typeid(manager))
        return tmanager;
        else if(typeid(*this) == typeid(scientist))
        return tscientist;
        else if(typeid(*this) == typeid(laborer))
        return tlaborer;
        else
        {cerr<<"\nBad employee type"; exit(1);}
        return tmanager;

        
        
        }

        void employee::write(){
        int size;
        cout<<"Writing "<<n<< " employees.\n";
        ofstream ouf;
        employee_type etype;

        ouf.open("EMPLOY.DAT", ios::trunc|ios::binary);
        if(!ouf)
        {cout<<"\nCan't open file\n";return; }

        for(int j=0; j<n;j++){
        etype=arrap[j]->get_type();

        ouf.write((char*)&etype, sizeof(etype));
        switch(etype){
        case tmanager: size=sizeof(manager);break;
        case tscientist: size=sizeof(scientist);break;
        case tlaborer: size=sizeof(laborer);break;
        }

        ouf.write( (char*)(arrap[j]), size );
        if(!ouf)
        {cout<<"\nCan't write to file\n";return; }

        }
        
        }

        void employee:: read(){
        int size;
        employee_type etype;
        ifstream inf;
        inf.open("EMPLOY.DAT",ios::binary);
        if(!inf)
        {cout<<"\nCan't open file\n";return; }
        n=0;
        while(true){
        inf.read((char*)&etype, sizeof(etype));
        if(inf.eof())
        break;
        if(!inf)
        {cout<<"\nCan't read type from file file\n";return; }
        
        switch(etype){
        case tmanager:
        arrap[n]=new manager;
        size=sizeof(manager);
        break;
        case tscientist:
        arrap[n]=new scientist;
        size=sizeof(scientist);
        break;
        case tlaborer:
        arrap[n]=new laborer;
        size=sizeof(laborer);
        break;
        default: cout << "\nUnknown type in file\n"; return;
        }
        inf.read( (char*)arrap[n], size );
        if(!inf)
        {cout<<"\nCan't read type from file file\n";return; }
        n++;
        }
        cout<<"Reading "<< n<< "employees\n";




        }
        int main()
{
char ch;
while(true)
{
cout << "'a' -- add data for an employee"
"\n'd' -- display data for all employees"
"\n'w' -- write all employee data to file"
"\n'r' -- read all employee data from file"
"\n'x' -- exit"
"\nEnter selection: ";
cin >> ch;
switch(ch)
{
case 'a':
employee::add(); break;
case 'd': 
employee::display(); break;
case 
'w':
employee::write(); break;
case 'r': 
employee::read(); break;
case 'x': exit(0); 
default: cout << "\nUnknown command";
} 
} 
return 0;
}