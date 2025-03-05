#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <fstream>
#include <limits>

using namespace std;

class Employee
{
protected:
    string name;
    int id;

public:
    Employee(int empID, string &empName) : id(empID), name(empName) {}


    virtual void display()
    {
        cout << "ID: " << id << " Name: " << name << endl;
    }

    virtual void saveTofile(ofstream &file)
    {
    }
    int getID()
    {
        return id;
    }

    string getname()
    {
        return name;
    }
};

class FullTimeEmployee : public Employee
{
private:
    set<string> workSchedule;

public:
    FullTimeEmployee(int empID, string &empName) : Employee(empID, empName) {}

    void addSchedule(string &schedule)
    {
        if (!schedule.empty())
        {
            workSchedule.insert(schedule);
        }
    }

    void display()
    {
    Employee:
        display();
        cout << " Work Schedule: ";
        for (auto &s : workSchedule)
        {
            cout << s << " " << endl;
        }
        cout << endl;
    }

    void saveTofile(ofstream &file)
    {
        file << id << "," << name << " FullTime ";
        for (auto it = workSchedule.begin(); it != workSchedule.end(); ++it)
        {
            file << *it;
            if (next(it) != workSchedule.end())
                file << ";";
        }

        file << endl;
    }
};

class PartTimeEmployee : public Employee
{
private:
    set<string> workshift;

public:
    PartTimeEmployee(int empID, string &empName) : Employee(empID, empName) {}

    void addShift(string &shift)
    {
        if (!shift.empty())
        {
            workshift.insert(shift);
        }
    }

    void display()
    {
    Employee:
        display();
        cout << " Shifts: ";
        for (auto &s : workshift)
        {
            cout << s << " " << endl;
        }
        cout << endl;
    }

    void saveTofile(ofstream &file)
    {
        file << id << "," << name << " FullTime ";
        for (auto it = workshift.begin(); it != workshift.end(); ++it)
        {
            file << *it;
            if (next(it) != workshift.end())
                file << ";";
        }

        file << endl;
    }
};

map<int, Employee *> employees;

void addEmployee(int id, string &name, string &type)
{
    cout << "Enter employee ID: ";
    cin >> id;
    cout << "Enter employee name: ";
    getline(cin, name);
    cin.ignore();
    // employees[id]=name;
    cout << "\nEnter employee type(Full-Time/Part-Time): ";
    getline(cin, type);
    if (type == "Full-Time")
    {
        employees[id] = new FullTimeEmployee(id, name);
    }
    else if (type == "Part-Time")
    {
        employees[id] = new PartTimeEmployee(id, name);
    }
    else
    {
        cout << "Invalid Type!" << endl;
        return;
    }

    cout << "Employee added successfully!\n";
}

void assignSchedule(int id, string &schedule)
{

    auto it = employees.find(id);
    if (it == employees.end())
    {
        cout << "Employee Not Found.\n";
        return;
    }
}

void assignShift(int id,string &shift){
    auto it = employees.find(id);
    if (it == employees.end())
    {
        cout << "Employee Not Found.\n";
        return;
    }

}

void display()
{
    if (employees.empty())
    {
        if (employees.empty())
        {
            cout << "None added\n";
            return;
        }

        for (const auto &pair : employees)
        {
            pair.second->display();
        }
    }
}

void saveData()
{
    ofstream fullFile("fullTime.txt");
    ofstream partFile("partTime.txt");

    if (!fullFile.is_open() || !partFile.is_open())
    {
        cout << "Error opening to Write\n";
        return;
    }

    fullFile.close();
    partFile.close();
    cout << "Data saved successfully\n";
}

void LoadData()
{
    ifstream fullFile("fullTime.txt");
    ifstream partFile("partTime.txt");

    if (!fullFile.is_open() || !partFile.is_open())
    {
        cout << "Error opening to Read\n";
        return;
    }

    fullFile.close();
    partFile.close();
    cout << "Data saved successfully\n";
}

int main()
{   
    int id;
    string name, type, str;
    int choice = 0;
    while (1)
    {
        cout << "1. Add Employee\n"
             << "2. Assign Work Schedule\n"
             << "3.Assign Shift\n"
             << "4.Display Data\n"
             << "5.Save Data\n"
             << "6.Load Data\n"
             <<"Enter choice: ";
             cin>>choice;

             if(choice==7){
                cout<<"Exiting program...\n";
                break;
             }

             switch (choice){
                case 1:addEmployee(id,name,type); break;
                case 2:assignSchedule(id,str); break;
                case 3:assignShift(id,str); break;
                case 4:display(); break;
                case 5:saveData(); break;
                case 6:LoadData(); break;
                default:cout<<"invalid choice\n"; break;
                
             }
  
    }

}