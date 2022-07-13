/*  
             <<< prOOPject >>>
  --------------------------------------------
            Car Rental Service
  --------------------------------------------
  | GOHAR NADEEM               (F2020266107) |
  --------------------------------------------

*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class RentedCars {
protected:
    static int counter;
    int count;
public:
    int operator++() {
        ++counter;
        count = counter;
        return count;
    }
    static void showCounter() {
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\t\t\tNumber of cars rented today : " << counter << endl;
        cout << endl;
        system("PAUSE");
    }
};
int RentedCars::counter = 0;


class Administrator:public RentedCars
{
protected:
    int input,adminChoice;
    string adminPass, adminUser;
public:
    int start_up_options() {
        do {
            cout << "\n\n\n" << endl;
            cout << "\n\n\t\t\t\t\tWelcome To G.A.M.A. Car Rental Service" << endl;

            cout << "\n\t\t\t\t\t\tPress 1 for Admin" << endl;
            cout << "\n\t\t\t\t\t\tPress 2 for User" << endl;
            cout << "\n\t\t\t\t\t\tPress 3 to exit" << endl;
            cout << "\n\t\t\t\t\t\tYour choice : "; cin >> input;
            system("cls");
        } while (input != 1 && input != 2 && input != 3);
        if (input == 1) {
            return input;
        }
        else if (input == 2) {
            return input;
        }
        else {
            return input;
        }
    }
        void end() {
            system("cls");
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\t\t*****************************************************" << endl;
            cout << "\n\n\t\t\t\t\t   Thanks for using our program!" << endl;
            cout << "\n\n\t\t\t\t*****************************************************" << endl;
            exit(0);
        }
    
    int admin_options() {
    idhar:
        cout << "\n\n\t\t\t\t\tADMIN LOGIN" << endl;
        cout << "\n\n\t\t\t\tEnter your username : "; cin >> adminUser;
        cout << "\n\n\n\t\t\t\tEnter your password : "; cin >> adminPass;
        if (adminUser == "Admin" && adminPass == "123")
        {
            do {
                system("cls");
                cout << "\n\t\t\t\t\t <<< Access granted >>>" << endl;
                cout << "\n\t\t\t\t\t      Welcome " << adminUser << endl;
                cout << "\n\n\t\t\t\t*******************************************" << endl;
                cout << "\n\t\t\t\t\tPress 1 for employee options" << endl;
                cout << "\n\t\t\t\t\tPress 2 for vehicle options" << endl;
                cout << "\n\t\t\t\t\tPress 3 to car maintanence menu" << endl;
                cout << "\n\t\t\t\t\tPress 4 to check number of cars rented today" << endl;
                cout << "\n\t\t\t\t\tPress 5 to return main menu" << endl;
                cout << "\n\n\t\t\t\t\tYour choice : "; cin >> adminChoice;
                system("cls");
            } while (adminChoice != 1 && adminChoice != 2 && adminChoice != 3 && adminChoice != 4 && adminChoice != 5);
        }
        else {
            cerr << "Incorrect email or password ! Please try again." << endl;
            system("PAUSE");
            system("cls");
            goto idhar;
        }


        return adminChoice;
    }

    void employee();
    void vehicles();
    void maintainence();
    
};

void Administrator::vehicles() {
udhr:
    system("cls");
    char x;
    cout << "\n\n\n\n" << endl;
    cout << "\n\t\t\t\t\tPress 1 to add car" << endl;
    cout << "\n\t\t\t\t\tPress 2 to remove car" << endl;
    cout << "\n\t\t\t\t\tPress 3 to display all cars coming soon" << endl;
    cout << "\n\t\t\t\t\tPress 4 to return to main menu" << endl;
    cout << "\n\t\t\t\t\tYour choice : "; cin >> x;
    system("cls");
    if (x == '1') {
        string carName;
        system("cls");
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\tEnter car name to be added : "; cin >> carName;
        
        ofstream  addcar;
        addcar.open("Cars.txt", ios::app);
        addcar << carName;
        addcar << endl;
        cout << "\n\n\t\t\t" << carName << " has been successfully added !" << endl;
        cin.ignore();
        addcar.close();
        cout << "\n\n\t\t\t\tReturning to menu !" << endl;
        cin.get();
        goto udhr;
    }
    else if (x == '2') {
        string car2, a;
   
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\tEnter car name to remove : "; cin >> car2;
            ifstream in;
            in.open("Cars.txt");
            ofstream x;
            x.open("newcars.txt");
            in >> a;
            while (in.eof() == 0) {
                if (a != car2) {
                    x << a;
                    x << endl;
                }
                else {
                    cout << "\n\n\t\t\t" << car2 << " successfully removed ! " << endl;
                }
                in >> a;
            }
            in.close();
            x.close();
            if (remove("Cars.txt") != 0) {
                cout << "\n\n\n\n" << endl;
                cerr << "\n\n\t\t\tCar not removed ! " << endl;
                system("PAUSE");
                goto udhr;

            }
            system("PAUSE");
            rename("newcars.txt", "Cars.txt");
            goto udhr;

    }
    else if (x == '3') {
        cout << "\n\n\n\n" << endl;
        cout << "\t\t\t\t\tList Of Cars Coming Soon  " << endl;
        cout << "\n\t\t\t\t--------------------------------------\n" << endl;
        ifstream display;
        string names;
        int i = 1;
        display.open("Cars.txt");
        while (display.eof() == 0) {
            getline(display, names);
            if (display.eof() != 0)
                break;
            cout << setw(46) << i << ") " << names << endl;
            i++;
        }
        display.close();
        cout << endl;
        system("PAUSE");
    }
    else if (x == '4') {
        start_up_options();
    }
    else {
        cout << "\n\n\n\n" << endl;
        cerr << "\n\t\t\t\t\tWrong input !" << endl;
        system("PAUSE");
        goto udhr;
    }
    
}


void Administrator::employee() {
    int C;
here1:
    system("cls");
    cout << "\n\n\n\n" << endl;
    cout << "\n\t\t\tPress 1 to add an employee" << endl;
    cout << "\n\t\t\tPress 2 find an employee" << endl;
    cout << "\n\t\t\tPress 3 delete an employee" << endl;
    cout << "\n\t\t\tPress 4 to show all employees" << endl;
    cout << "\n\t\t\tPress 5 to pay all employees" << endl;
    cout << "\n\t\t\tPress 6 to exit" << endl;
    cout << "\n\t\t\tPlease enter your choice : "; cin >> C;
    system("cls");
    switch (C)
    {
    case 1:
    {

        string empName, empCode;
        system("cls");
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\tPlease enter Employee Name : "; cin >> empName;
        cin.ignore();
        cout << "\n\n\t\t\tPlease enter Employee Code : "; cin >> empCode;

        ofstream  empreg;
        empreg.open("Employee.txt", ios::app);
        empreg << empName;
        empreg << endl;
        empreg << empCode;
        empreg << endl;
        cout << "\n\n\t\t\tEmployee has been registered" << endl;
        cin.ignore();
        empreg.close();
        cin.get();
        goto here1;
    }
    break;
    case 2:
    {
        int ex = 0;
        ifstream searchE("Employee.txt");
        string empName1, empCode1, searchCode;
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\n\t\t\tPlease enter Employee Code : "; cin >> searchCode;
        while (!(searchE.eof()))
        {
            searchE >> empName1;
            searchE >> empCode1;
            if (searchCode == empCode1)
            {
                ex = 1;
                break;
            }
        }
        searchE.close();
        if (ex == 1)
        {
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\n\t\t\tThe Employee name is : " << empName1;
            cin.get();
            system("PAUSE");
        }
        else
        {
            cout << "\n\n\n\n" << endl;
            cerr << "\n\n\n\t\t\tEmployee not found ! Wrong employee code entered !" << endl;
            cin.get();
            system("PAUSE");
            goto here1;
        }
        cin.get();
        goto here1;
    }
    break;
    case 3:
    {
        string n, a, b;
        int exi = 0;
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\n\t\t\tEnter the name of the employee to delete the record : "; cin >> n;
        ifstream d;
        d.open("Employee.txt");
        ofstream e;
        e.open("new.txt");
        d >> a;
        d >> b;



        while (!d.eof())
        {
            if (a != n)
            {
                e << a;
                e << endl;
                e << b;
                e << endl;
            }
            else
            {
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\n\t\t\tRecord Deleted" << endl;
                cin.get();
            }
            d >> a;
            d >> b;
        }
        e.close();
        d.close();

        if (remove("Employee.txt") != 0)
        {
            cout << "\n\n" << endl;
            cout << "\n\n\n\t\t\tEmployee not removed" << endl;
            cin.get();
        }
        else
        {
            cout << "\n\n" << endl;
            cout << "\n\n\n\t\t\tEmployee removed" << endl;
            cin.get();
        }

        rename("new.txt", "Employee.txt");

        goto here1;

    }
    break;
    case 4:
    {
        string id, name;
        cout << "\n\n" << endl;
        cout << "\n\t\t\t\t\t  EMPLOYEE LIST" << endl;
        cout << "\n\t\t\t\t-------------------------------" << endl;
        cout << "\n\t\t\t\t\tNAME\t\tID" << endl;
        cout << "\n\t\t\t\t-------------------------------" << endl;
        ifstream show;
        show.open("Employee.txt");
        while (show.eof() == 0) {
            getline(show, name);
            getline(show, id);
            if (show.eof() != 0)
                break;
            cout << "\n\t\t\t\t\t" << name << "\t\t" << id << endl;
        }
        show.close();
    }
    break;
    case 5:
    {
        char c;
        int emp = 20;
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\t\t\tPay of each employee : 10,000 PKR" << endl;
        cout << "\n\n\t\t\t\t\tPay wages of all employees ? (Y/y) : "; cin >> c;
        system("cls");
        if (c == 'y' || c == 'Y') {
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\t\t\tEmployees paid" << endl << "\n\n\t\t\t\t\tCost : " << emp * 10000 << " PKR" << endl;
        }
        else {
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\t\t\tEmployees not paid " << endl;
            cout << "\n\n\t\t\t\t\tReturning to menu !" << endl;

        }
    }
    break;
    case 6:
    {
        start_up_options();
    }
    break;
    default:
    {
        cerr << "\n\n\n\t\t\tSorry you entered a wrong choice" << endl;
        cin.get();
        goto here1;

    }
    }

    system("PAUSE");
}



void Administrator::maintainence() {
    char c;
    int cost = 15000;
    cout << "\n\n\n\n" << endl;
    cout << "\n\n\t\t\t\t\t\tCheck all vehicles ? (Y/y) : "; cin >> c;
    system("cls");
    if (c == 'y' || c == 'Y') {
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\t\t\t\tAll vehicles checked and charges paid for maintainence\n\t\t\t\t\t\tCost : " << cost << " PKR" << endl;
    }
    else {
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\t\t\t\tVehicles not checked " << endl;
        cout << "\n\n\t\t\t\t\t\tReturning to menu !" << endl;
    }
    system("PAUSE");
}

class Vitz {
public:
    virtual void displaySpecs() {
        cout << "\n\n\n\n" << endl;
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2002" << endl;
        cout << "\n\t\tEngine Capacity  : 1000 cc" << endl;
        cout << "\n\t\tBody Type        : Two Door Hatchback" << endl;
        cout << "\n\t\tExterior Color   : Blue" << endl;
        cout << "\n\t\tSeating Capacity : 4" << endl;
        cout << "\n\t\tAssembly         : Imported" << endl;
        cout << "\n\t\tMileage          : 100,000 KM" << endl;
        cout << "\n\t\tTransmission     : Automatic" << endl;
        cout << "\n\t******************************************" << endl;
    }
};
class Swift {
public:
    virtual void displaySpecs() {
       
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2016" << endl;
        cout << "\n\t\tEngine Capacity  : 1300 cc" << endl;
        cout << "\n\t\tBody Type        : Hatchback" << endl;
        cout << "\n\t\tExterior Color   : White" << endl;
        cout << "\n\t\tSeating Capacity : 4" << endl;
        cout << "\n\t\tAssembly         : Local" << endl;
        cout << "\n\t\tMileage          : 50,000 KM" << endl;
        cout << "\n\tTransmission     : Automatic" << endl;
        cout << "\n\t******************************************" << endl;
    }

};
class March {
public:
    virtual void displaySpecs() {
       
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2007" << endl;
        cout << "\n\t\tEngine Capacity  : 1300 cc" << endl;
        cout << "\n\t\tBody Type        : Hatchback" << endl;
        cout << "\n\t\tExterior Color   : Yelllow" << endl;
        cout << "\n\t\tSeating Capacity : 4" << endl;
        cout << "\n\t\tAssembly         : Imported" << endl;
        cout << "\n\t\tMileage          : 75,000 KM" << endl;
        cout << "\n\t\tTransmission     : Automatic" << endl;
        cout << "\n\t******************************************" << endl;
    }
};
class Corolla {
public:
    virtual void displaySpecs() {
        
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2015" << endl;
        cout << "\n\t\tEngine Capacity  : 1300 cc" << endl;
        cout << "\n\t\tBody Type        : Sedan" << endl;
        cout << "\n\t\tExterior Color   : Grey" << endl;
        cout << "\n\t\tSeating Capacity : 4" << endl;
        cout << "\n\t\tAssembly         : Local" << endl;
        cout << "\n\t\tMileage          : 51,240 KM" << endl;
        cout << "\n\t\tTransmission     : Manual" << endl;
        cout << "\n\t******************************************" << endl;
    }
};
class Civic {
public:
    virtual void displaySpecs() {
       
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2020" << endl;
        cout << "\n\t\tEngine Capacity  : 1800 cc" << endl;
        cout << "\n\t\tBody Type        : Sedan" << endl;
        cout << "\n\t\tExterior Color   : Black" << endl;
        cout << "\n\t\tSeating Capacity : 4" << endl;
        cout << "\n\t\tAssembly         : Local" << endl;
        cout << "\n\t\tMileage          : 15,550 KM" << endl;
        cout << "\n\t\tTransmission     : Automatic" << endl;
        cout << "\n\t******************************************" << endl;
    }
};
class Elantra {
public:
    virtual void displaySpecs() {
        
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2020" << endl;
        cout << "\n\t\tEngine Capacity  : 2000 cc" << endl;
        cout << "\n\t\tBody Type        : Sedan" << endl;
        cout << "\n\t\tExterior Color   : Silver" << endl;
        cout << "\n\t\tSeating Capacity : 4" << endl;
        cout << "\n\t\tAssembly         : local" << endl;
        cout << "\n\t\tMileage          : 500 KM" << endl;
        cout << "\n\t\tTransmission     : Manual" << endl;
        cout << "\n\t******************************************" << endl;
    }
};
class MG {
public:
    virtual void displaySpecs() {
       
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2021" << endl;
        cout << "\n\t\tEngine Capacity  : 1500 cc(Turbo)" << endl;
        cout << "\n\t\tBody Type        : SUV" << endl;
        cout << "\n\t\tExterior Color   : Black" << endl;
        cout << "\n\t\tSeating Capacity : 5" << endl;
        cout << "\n\t\tAssembly         : Imported" << endl;
        cout << "\n\t\tMileage          : 10,050 KM" << endl;
        cout << "\n\t\tTransmission     : Automatic" << endl;
        cout << "\n\t******************************************" << endl;
    }
};

class Tucson {
public:
    virtual void displaySpecs() {
        
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2002" << endl;
        cout << "\n\t\tEngine Capacity  : 1000 cc" << endl;
        cout << "\n\t\tBody Type        : Two Door Hatchback" << endl;
        cout << "\n\t\tExterior Color   : Blue" << endl;
        cout << "\n\t\tSeating Capacity : 4" << endl;
        cout << "\n\t\tAssembly         : Imported" << endl;
        cout << "\n\t\tMileage          : 100,000 KM" << endl;
        cout << "\n\t\tTransmission     : Automatic" << endl;
        cout << "\n\t******************************************" << endl;
    }
};

class Sportage {
public:
    virtual void displaySpecs() {
        
        cout << "\n\t\tVehicle Information" << endl;
        cout << "\n\t******************************************" << endl;
        cout << "\n\t\tModel            : 2020" << endl;
        cout << "\n\t\tEngine Capacity  : 2000 cc" << endl;
        cout << "\n\t\tBody Type        : SUV" << endl;
        cout << "\n\t\tExterior Color   : Parentha Metal" << endl;
        cout << "\n\t\tSeating Capacity : 5" << endl;
        cout << "\n\t\tAssembly         : Local" << endl;
        cout << "\n\t\tMileage          : 11,050 KM" << endl;
        cout << "\n\t\tTransmission     : Automatic" << endl;
        cout << "\n\t******************************************" << endl;
    }
};

class CarRental :public Administrator,public Vitz, public Swift, public March, public Corolla, public Civic, public Elantra, public MG, public Tucson, public Sportage
{
protected:
    int month_r, year_r,day_t,month_t,year_t;
    int day_r;
    int customer_id;
    int counter;
    double rate_h, change, payment;
    double discount, rate_d, total_rent;
    char cash, car;
    string name;
    string vehicle_rented;
    static string cars1[3];
    static string cars2[3];
    static string cars3[3];
    friend void displayChoices();


public:
    CarRental() :day_t(1), year_t(2021), month_t(1), day_r(1), year_r(2021), month_r(1), cash(' '), car(' '), name(" "), counter(5), rate_h(0), rate_d(0.0), discount(0.0), customer_id(0), vehicle_rented(" "), total_rent(0.0), payment(0), change(0)
    {}
   
    char getChoice(char c) {
        cash = c;
        return cash;
    }
    char budget() {

        return cash;
    }

    char getCar() {
        do {
         
            cout << "\n\n\t\t\t\tSelect from available options (1/2/3) : ";
            car = _getch();
        } while (car != '1' && car != '2' && car != '3');
        return car;
    }


    void sign_up() {
    tab2:
        int choice;
        string user, pass;
        ofstream file;
    tab3:
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\t\t\t\tPress 1 to create new account\n\n\t\t\t\t\t\tPress 2 to Login to an existing account\n\n\t\t\t\t\t\tPress 3 to exit" << endl;
        cout << "\n\n\t\t\t\t\t\tYour choice : "; cin >> choice;
        system("cls");
        if (choice == 3)
        {
            end();
        }
        else if (choice == 1) {
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\t\t\t\tEnter a username : "; cin >> user;
            cout << "\n\n\t\t\t\t\t\tEnter a password : "; cin >> pass;
            name = user;
            file.open(user + ".txt");
            file << user << endl << pass;
            file.close();

            goto tab2;

        }
        else if (choice == 2) {
        tab:
            if (!logInCheck()) {
                system("cls");
                cout << "\n\n\n\n" << endl;
                cerr << "\n\n\t\t\t\t\t\tIncorrect username or password ! " << endl;

                counter--;
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\t\t\t\t\tYou have " << counter << " tries left." << endl;

                if (counter == 0) {
                    system("cls");
                    cout << "\n\n\n\n" << endl;
                    cerr << "\n\n\t\t\t\t\t\tNo more attempts allowed. Please create a new account ! " << endl;
                    goto tab3;
                }
                goto tab;
            }

            else {
                system("cls");
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\t\t\t\tWelcome to your acount " << name << endl;
                cout << "\n\n\t\t\t\t******************************************" << endl;
            }
        }

    }



    bool rent() {
        int c;
        do {
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\t\t\t\t1) Rent rate per hour   \n\n\t\t\t\t\t\t2) Rent rate per day" << endl;
            cout << "\n\n\t\t\t\t\t\t         Your choice : ";
            cin >> c;
        } while (c != 1 && c != 2);
        if (c == 1) {
            return 1;
        }
        else {
            return 0;
        }
    }

   

    double rentPerHour(double* total,int* hours);

    double rentPerDay(double* total,int* days);

    bool logInCheck();

    void get_payment();

    void reciept();

    void categories() {
        if (budget() == 'a') {
            rate_h = 4000;
            discount = 0.10;
            rate_d = (4000 * 24) * discount;
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\t\t\t\tCategory A" << endl;
            cout << "\n\n\t\t\t\t\t-------------------------------" << endl;
            cout << "\n\n\t\t\t\t\t\tCars available : " << endl;
            cout << "\n\n\t\t\t\t\t-------------------------------" << endl;
            for (int i = 0; i < 3; i++) {
                cout << "\n\n\t\t\t\t\t\t" << cars1[i] << endl;;
            }
            getCar();
            system("cls");
            if (car == '1') {
                vehicle_rented = cars1[0];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars1[0] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                Vitz::displaySpecs();
            }
            else if (car == '2') {
                vehicle_rented = cars1[1];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars1[1] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                March::displaySpecs();
            }
            else {
                vehicle_rented = cars1[2];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars1[2] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                Swift::displaySpecs();
            }
        }
        else if (budget() == 'b') {
            rate_h = 8000;
            discount = 0.15;
            rate_d = (8000 * 24)*discount;
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\t\t\t\tCategory B" << endl;
            cout << "\n\n\t\t\t\t\t-------------------------------" << endl;
            cout << "\n\n\t\t\t\t\t\tCars available : " << endl;
            cout << "\n\n\t\t\t\t\t-------------------------------" << endl;
            for (int i = 0; i < 3; i++) {
                cout << "\n\n\t\t\t\t\t\t" << cars2[i] << endl;
            }
            getCar();
            system("cls");
            if (car == '1') {
                vehicle_rented = cars2[0];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars2[0] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                Corolla::displaySpecs();
            }
            else if (car == '2') {
                vehicle_rented = cars2[1];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars2[1] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                Civic::displaySpecs();
            }
            else {
                vehicle_rented = cars2[2];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars2[2] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                Elantra::displaySpecs();
            }
        }
        else {
            rate_h = 10000;
            discount = 0.20;
            rate_d = (10000 * 24) * discount;
            cout << "\n\n\n\n" << endl;
            cout << "\n\n\t\t\t\t\t\tCategory C" << endl;
            cout << "\n\n\t\t\t\t\t-------------------------------" << endl;
            cout << "\n\n\t\t\t\t\t\tCars available : " << endl;
            cout << "\n\n\t\t\t\t\t-------------------------------" << endl;
            for (int i = 0; i < 3; i++) {
                cout << "\n\n\t\t\t\t\t\t" << cars3[i] << endl;
            }
            getCar();
            system("cls");
            if (car == '1') {
                vehicle_rented = cars3[0];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars3[0] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                Sportage::displaySpecs();
            }
            else if (car == '2') {
                vehicle_rented = cars3[1];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars3[1] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                Tucson::displaySpecs();
            }
            else {
                vehicle_rented = cars3[2];
                cout << "\n\n\n\n" << endl;
                cout << "\n\n\t\tYour selection : " << cars3[2] << endl;
                cout << "\n\t  ------------------------------------" << endl;
                MG::displaySpecs();
            }
        }
    }
    //pre
    CarRental operator++() {
        day_r = day_r + 1;
        month_r = month_r;
        year_r = year_r;
        day_t = day_t;
        month_t = month_t;
        year_t = year_t;
        name = name;
        customer_id = customer_id;
        vehicle_rented = vehicle_rented;
        total_rent = total_rent;
        payment = payment;
        change = change;
    }
    //post
    CarRental operator++(int) {
        month_r = month_r + 1;
        day_r = 1;
        year_r = year_r;
        day_t = day_t;
        month_t = month_t;
        year_t = year_t;
        name = name;
        customer_id = customer_id;
        vehicle_rented = vehicle_rented;
        total_rent = total_rent;
        payment = payment;
        change = change;
    }

    ~CarRental() {}

};
string CarRental::cars1[3] = { "Vitz","March","Swift" };
string CarRental::cars2[3] = { "Corolla","Civic","Elantra" };
string CarRental::cars3[3] = { "Sportage","Tucson","MG HS" };

bool CarRental::logInCheck() {
    string user, pass, un, pw;
    cout << "\n\n\n\n" << endl;
    cout << "\n\n\t\t\t\t\t\tEnter username : "; cin >> user;
    cout << "\n\n\t\t\t\t\t\tEnter password : "; cin >> pass;
    name = user;
    ifstream read(user + ".txt");
    getline(read, un);
    getline(read, pw);
    if (un == user && pw == pass)
    {
        return true;
    }
    else {
        return false;
    }

}

void CarRental::get_payment() {
    cout << "\n\n\t\t\t\t\t\t   PAYMENT" << endl;
    cout << "\n\n\t\t\t\t\t\tDue Payment : " << total_rent << " PKR" << endl;
    cout << "\n\n\t\t\t\t\t\tPlease pay the due amount : ";
back: cin >> payment;

    if (payment > total_rent) {
        change = payment - total_rent;
        cout << "\n\n\t\t\t\t\t\tPaid amount : " << payment << " PKR" <<endl;
        cout << "\n\n\t\t\t\t\t\tYour change  : " << change << " PKR" <<endl;
        system("PAUSE");
        system("cls");
    }
    else if (payment == total_rent)
    {
        cout << "\n\n\t\t\t\t\t\tPaid Amount: " << payment << " PKR" <<endl;
        system("PAUSE");
        system("cls");
    }
    else {
        cout << "\n\n\t\t\t\t\t\tInsufficient amount paid ! PLEASE PAY THE FULL AMOUNT : ";
        goto back;
    }

}




void CarRental::reciept() {
    srand(time(0));
    customer_id = 1 + rand() % 1000;
    cout << setw(15) << "\n\t\t\t\tHere is your receipt : " << endl;
    cout << "\n\t\t***********************************************" << endl;
    cout << "\n\t\t\tCustomer Name  : " << name << endl;
    cout << "\n\t\t\tCustomer ID    : " << customer_id << endl;
    cout << "\n\t\t\tVehicle Rented : " << vehicle_rented << endl;
    cout << "\n\t\t\tToday's Date   : " << day_t << "/" << month_t << "/" << year_t << endl;
    cout << "\n\t\t\tReturn Date    : " << day_r << "/" << month_r << "/" << year_r << endl;
    cout << "\n\t\t\tTotal Rent     : " << total_rent << " PKR" << endl;
    cout << "\n\t\t\tPayment        : " << payment << " PKR" << endl;
    cout << "\n\t\t\tChange         : " << change << " PKR" << endl;
    cout << "\n\t\t***********************************************" << endl;
    cout << setw(10) << "\n\t\t\t\tTHANK YOU ! " << endl;
    system("PAUSE");
}

void displayChoices() {
    
    cout << "\n\n\t\t\t\t\t  Select Vehicle Category" << endl;
    cout << "\n\n\t\t\t\t\t\t(a) HATCHBACK\n\n\t\t\t\t\t\t(b) SEDAN\n\n\t\t\t\t\t\t(c) SUV" << endl;
    cout << "\n\t\t\t\t\t\t(a)/(b)/(c) : ";
}

double CarRental::rentPerHour(double* total, int* hours) {
    
    cout << "\n\n\t\t\t\t\t\tEnter the amount of hours you want to rent the car : "; cin >> *hours;
   
    *total = *hours * rate_h;
    total_rent = *total;
    if (*hours > 23) {
        *hours -= 24;
        day_r++;
    }
    return *total;
}
double CarRental::rentPerDay(double* total, int* days) {
   
    cout << "\n\n\t\t\t\t\t\tEnter the number of days you want to rent the car : "; cin >> *days;
  
    *total = *days * (rate_d * discount);
    total_rent = *total;
    
    if (*days > 30) {
        while (*days > 30) {
            month_r++;
            *days -= 30;

            day_r = *days % 30;
        }
    }else {
        while (*days <= 30) {
            --(*days);
            day_r++;
            if (*days == 0) {
                break;
            }
        }
    }
    return *total;
}

int main()
{
    RentedCars rc;
    system("cls");
    int temp1,temp2;
    CarRental* ptr = new CarRental;
    temp2 = ptr->start_up_options();
    if (temp2 == 1)
    {

        temp1 = ptr->admin_options();
        if (temp1 == 1) {
            ptr->employee();
            main();
        }
        else if (temp1 == 2) {
            ptr->vehicles();
            main();
        }
        else if(temp1 == 3){
            ptr->maintainence();
            main();
        }
        else if (temp1 == 4) {
            ptr->RentedCars::showCounter();
            main();
        }
        else {
            main();
        }
    }
    else if (temp2 == 2) {
        ptr->sign_up();
    }
    else
    {
        ptr->end();
    }

    char choice, Choice;
    displayChoices();
    choice = _getch();
    system("cls");

    do {
        Choice = ptr->getChoice(choice);
    } while (Choice != 'a' && Choice != 'b' && Choice != 'c');

    ptr->categories();

    cout << endl;
    system("PAUSE");
    system("cls");

    int days = 0;
    int hours = 0;

    if (ptr->rent()) {
        double rph;
        ptr->rentPerHour(&rph,&hours);
        
        system("cls");
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\t\t\t\tYour total rent for the vehicle : " << rph << " PKR " << endl;
        system("PAUSE");
        system("cls");
    }
    else {
        double rpd;
        ptr->rentPerDay(&rpd,&days);
        system("cls");
        cout << "\n\n\n\n" << endl;
        cout << "\n\n\t\t\t\t\t\tYour total rent for the vehicle : " << rpd << " PKR " << endl;
        system("PAUSE");
        system("cls");
    }

    ptr->get_payment();
                                                    
    ptr->reciept();

    ++rc;

    char again;
    system("cls");
    cout << "\n\n\n\n" << endl;
    cout << "\n\n\t\t\t\t\t\tRent another car ? (Y/y) : "; cin >> again;
    if (again == 'Y' || again == 'y') {
        system("cls");
        main();
    }
    else {
        ptr->end();
    }

    cout << endl;
    system("PAUSE");
    return 0;
}

