#include<iostream>
#include<cstring>
using namespace std;

class Medicine{
    private:
    char TradeName[30];
    char genrName[30];
    double unitPrice;
    double discount;
    //double sellingPrice=unitPrice-discount;

    public:
        Medicine(){
            strcpy(TradeName,"X");
            strcpy(genrName,"X");
            unitPrice=0.0;
            discount=0.0;
            }

        void assignName(char name[], char genericName[]){
           strcpy(TradeName,name);
            strcpy(genrName,genericName);
        }
    void assignPrice(double price){
        unitPrice=price;
    }
    void setDiscountPercent(double percent){
        if(percent>=0.0 || percent<=30.0)
            discount=percent;
        else
        discount=5.0;
    }
    double getSellingPrice(int nos=1){
        double sellingPrice= unitPrice-(unitPrice*discount/100);

        return sellingPrice;

    }
    void display(){
        cout<<"MRP.of " <<TradeName<<" ("<<(genrName)<<") " <<"is BDT "<<unitPrice<<" Current discount"<<" "<<" "<<discount<<". Selling price BDT "<< getSellingPrice()<<endl;
    }
};

int main(){
    Medicine med;
    char name[]="Napa";
    char genericName[]="Paracetamol";
    med.assignName(name, genericName);
    med.assignPrice(1.00);
    med.setDiscountPercent(10);
    med.display();
}
