#include<fstream>
#include<iostream>
using namespace std;

const int MAX =100;
int buff[MAX];

int main(){

    for(int j=0; j<MAX; j++)
    buff[j]=j;

    ofstream os;
    os.open("a:edata.dat",ios::trunc | ios::binary);

    if(!os)
    {cerr<<"Could not open output file\n"; exit(1);}

    cout<<"Writing...\n";

    os.write( reinterpret_cast<char*>(buff), MAX*sizeof(int) );
    os.close();

    for(int j=0; j<MAX; j++)
    buff[j]=0;

    ifstream is;
    is.open("a:edata.dat",ios::binary);
    if(!is)
    {cerr<<"Could not open input file\n"; exit(1);}

    cout<<"Reading...\n";

    is.read( reinterpret_cast<char*>(buff), MAX*sizeof(int));

    for(int j=0; j<MAX; j++)
    if(buff[j]!=j)
       {cerr<<"Data is incorrect\n"; exit(1);}
       cout<<"Data is incorrect\n";
}