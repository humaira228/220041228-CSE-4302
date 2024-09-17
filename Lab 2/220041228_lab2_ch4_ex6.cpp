#include <iostream>

using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

int main(){

    etype e1;
    char t;
    cin>>t;

    switch(t){
        case 'l' : e1 = laborer; break;
        case 's' : e1 = secretary; break;
        case 'm' : e1 = manager; break;
        case 'a' : e1 = accountant; break;
        case 'e' : e1 = executive; break;
        case 'r' : e1 = researcher; break;
        default:
            break;
    }

    switch(e1){
        case laborer:
            cout<<"Employee type is laborer"; break;

        case secretary:
            cout<<"Employee type is secretary"; break;
        case manager:
            cout<<"Employee type is manager"; break;
        case accountant:
            cout<<"Employee type is accountant"; break;
        case executive:
            cout<<"Employee type is executive"; break;
        case researcher:
            cout<<"Employee type is researcher"; break;



        }
        return 0;
    }



