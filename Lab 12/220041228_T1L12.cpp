#include<iostream>
#include<vector>
#include<deque>
#include<list>
#include<fstream>
using namespace std;

class Book{
    private:
    string title;
    string author;
    string ISBN;

    public:
    Book(string t, string a, string i):title(t),author(a),ISBN(i){}

    string getTitle() const{
        return title;
    }

    string getAuthor()const{
        return author;
    }

    string getISBN()const{
        return ISBN;
    }

    void display()const{
        cout<<" Title: "<<title<<" Author: "<<author<<" ISBN: "<<ISBN;
    }

    string objTOstr()const{
        return title+","+author+","+ISBN;
    }

    static Book fromStr(const string& data){

            size_t pos1=data.find(',');
            size_t pos2=data.find(',',pos1+1);
            return Book(data.substr(0,pos1),data.substr(pos1+1,pos2-pos1-1),data.substr(pos2+1));

        }



    };

    class Library{
        private:
        vector<Book>inventory;
        deque<Book>borrowedBooks;
        list<Book> archivedBooks;

        public:
        void addBook(){
            string title,author,ISBN;
            getline(cin,title);
            getline(cin,author);
            getline(cin,ISBN);
            inventory.push_back(Book(title,author,ISBN));
        }

        void borrowBook(){
            string isbn;
            cin>>isbn;
            for(auto it=inventory.begin(); it!=inventory.end();it++){
                if(it->getISBN()==isbn){
                    borrowedBooks.push_back(*it);
                    inventory.erase(it);
                    cout<<"Borrow Success";
                    return;
                }
            }
            cout<<"Book not found"<<endl;
        }

        void returnBook(){
            string isbn;
            cin>>isbn;
            for(auto it=borrowedBooks.begin(); it!=borrowedBooks.end();it++){
                if(it->getISBN()==isbn){
                    inventory.push_back(*it);
                    borrowedBooks.erase(it);
                    cout<<"Return success";
                    return;
                }
            }
            cout<<"Book not found"<<endl;
        }

        void archiveBook(){
            string isbn;
            cin>>isbn;
            for(auto it=inventory.begin(); it!=inventory.end();it++){
                if(it->getISBN()==isbn){
                    archivedBooks.push_back(*it);
                    inventory.erase(it);
                    cout<<"Archive success";
                    return;
                }
            }
            cout<<"Book not found"<<endl;
        }

        void displayAll(){
            cout<<"Inventory Books"<<endl;
            for(const auto&book : inventory) book.display();

            cout<<"Borrowed Books"<<endl;
            for(const auto&book : borrowedBooks) book.display();

            cout<<"Archived Books"<<endl;
            for(const auto&book : archivedBooks) book.display();


        }

        void saveData(){
            ofstream inFile("invent.txt"), borrowFile("borrow.txt"),archiveFile("archived.txt");

            if(!inFile || !borrowFile || !archiveFile){
                cout<<"Could not write in Files";
                return;
            }

            for(const auto&book: inventory)
            inFile<<book.objTOstr()<<endl;
            for(const auto&book: borrowedBooks)
             borrowFile<<book.objTOstr()<<endl;
            for(const auto&book: archivedBooks)
            archiveFile<<book.objTOstr()<<endl;
            cout<<"Saved!"<<endl;
        }

        void LoadData(){
            ifstream inFile("invent.txt"), borrowFile("borrow.txt"),archiveFile("archived.txt");

            if(!inFile || !borrowFile || !archiveFile){
                cout<<"Could not read Files";
                return;
            }


            string line;

            while(getline(inFile,line)){
                inventory.push_back(Book::fromStr(line));
            }
            while(getline(borrowFile,line)){
                borrowedBooks.push_back(Book::fromStr(line));
            }
            while(getline(inFile,line)){
                archivedBooks.push_back(Book::fromStr(line));
            }


            cout<<"Loading done!"<<endl;
        }
    };



    int main(){
        Library lib;
        int op;

        do{
            cout<<"Choose any:"<<endl;
            cout<<"1. Add Book"<<endl;
            cout<<"2. Borrow Book"<<endl;
            cout<<"3. Return Book"<<endl;
            cout<<"4. Archive Book"<<endl;
            cout<<"5. Display Book"<<endl;
            cout<<"6. Save Data"<<endl;
            cout<<"7. Load Data"<<endl;
            cout<<"8. Exit"<<endl;
            cin>>op;
            cin.ignore();


            switch(op){
                case 1: lib.addBook();break;
                case 2: lib.borrowBook();break;
                case 3: lib.returnBook();break;
                case 4: lib.archiveBook();break;
                case 5: lib.displayAll();break;
                case 6: lib.saveData();break;
                case 7: lib.LoadData();break;
                case 8: cout<<"Exiting"<<endl;break;
                default:cout<<"Invalid Choice"<<endl;

            }
        }while(op!=8);

    }


