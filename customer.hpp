#ifndef cus_details
#define cus_details
#include "delay.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "payment.hpp"
using namespace std;

class shopping : public paid_cash
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
    // administer login function
    void login();
    void registration();
    void forgot();
    void mainmenu();
    // buyer login function
    void mainmenu1();
    void login1();
    void registration1();
    void forgot1();
};
/********************************************************************************************login system for buyer************************************************************/
void shopping::mainmenu1()
{
    int c;
    cout << "\n\t\t\t_______________________________________________________________________\n\n\n";
    cout << "\t\t\t                   Welcome to the login page of buyer                          \n\n\n";
    cout << "\t\t\t____________________________MENU______________________________________\n\n\n";
    cout << "                                                                             \n";
    cout << "\t\t\t| Press 1 to LOGIN                                            |" << endl;
    cout << "\t\t\t| Press 2 to REGISTRATION  for buyer                          |" << endl;
    cout << "\t\t\t| Press 3 to IF YOU FORGOT PASSWORD                           |" << endl;
    cout << "\t\t\t| Press 4 to EXIT                                             |" << endl;
    cout << "\n\n\t\t\t Please enter your choice :";
    cin >> c;
    cout << endl;
    switch (c)
    {
    case 1:
        login1();
        break;
    case 2:
        registration1();
        break;
    case 3:
        forgot1();
        break;
    case 4:
        system("cls");
        menu();
    default:
        system("cls");
        cout << "\t\t\t Please select from option!!!";
        mainmenu1();
    }
}

/*****************************************************************FOR LOGIN *************************************************************************************/

void shopping::login1()
{
    int count = 0, i = 0;
    char c;
    // char password[20], userId[20], id[20], pass[20];
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password :" << endl;
    cout << "\t\t\t   USERNAME\t";
    cin >> userId;
    cout << "\t\t\t PASSWORD\t";

    do
    {
        c = getch();
        switch (c)
        {
        case 0:
            getch();
            break;
        case 13:
            cout << endl;
            break;
        case 8:
            if (password.length() > 0)
            {
                password.erase(password.end() - 1);
                cout << c << ' ' << c;
            }
            break;
        default:
            password += c;
            cout << '*';
            break;
        }
    } while (c != 13);

    ifstream input("recorder.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
        }
    }

    input.close();
    if (count == 1)
    {
        cout << userId << "\n Your LOGIN is successfull \n Thanks for logging in !\n";
        time_delay(10);
        system("cls");
        buyer();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your user name and password\n";
        mainmenu1();
    }
}

/*****************************************************************FOR LOGIN REGISTRATION*************************************************************************************/

void shopping::registration1()
{
    string rpassword, cpasswrod, rid, rpass;
    int c = 0;
    char ruserId[20];
    int valid = 0;
    system("cls");
    cout << endl
         << endl
         << endl;
    cout << "\t\t\t***********************************Registration********************************";
    cout << endl
         << endl;
X:
    cout << "\t\t\t\t\t Enter the User_name : ";
    cin >> ruserId;
    for (int b = 0; b < strlen(ruserId); b++)
    {
        if (isalpha(ruserId[b]))
        {
            valid = 1;
        }
        else
        {
            valid = 0;
            break;
        }
    }
    if (!valid)
    {
        cout << "entered name contains invalid character, please enter name only with alphabets:" << endl;
        goto X;
    }
T:
    cout << "\t\t\t\t\t Enter the Password : ";
    cin >> rpassword;
    cout << "\t\t\t\t\t Confirm password: ";
    cin >> cpasswrod;
    if (rpassword == cpasswrod)
    {
        cout << endl;
        cout << "\t\t\t\t\tpasswrod matched." << endl;
        time_delay(20);
        ofstream f1("recorder.txt", ios::app);
        f1 << ruserId << ' ' << rpassword << endl;
    }
    else
    {
        cout << "your passwrod don't match, please enter again:" << endl
             << endl;
        goto T;
    }

    system("cls");
    time_delay(5);
    cout << "\n\t\t\t\t\tRegistration is Successful......\n";
    time_delay(30);
    system("cls");
    mainmenu1();
}

/*****************************************************************FOR LOGIN FORGOT*************************************************************************************/

void shopping::forgot1()
{
    int option;
    system("cls");
    cout << "\n\t\t\t You forgot the password? don't worries \n";
    cout << "Preass 1 to search your id by username " << endl;
    cout << "press 2 to go back to main menu" << endl;
    cout << "\t\t\t Enter your choice :" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t\t Enter the username which you remembered :" << endl;
        cin >> suserId;
        ifstream f2("recorder.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found!\n";
            cout << "\n\n Your password is :" << spass;
            time_delay(100);
            system("cls");
            mainmenu();
        }
        else
        {
            cout << "\n\t\t Sorry! your account is not found!\n";
            mainmenu();
        }
        break;
    }
    case 2:
    {
        mainmenu1();
    }
    default:
        cout << "\t\t\t Wrong choice ! Please try again ..." << endl;
        mainmenu1();
    }
}

/*****************************************************************FOR LOGIN PAGE for adminstrator*************************************************************************************/
void shopping::mainmenu()
{
    int c;
    cout << "\n\t\t\t_______________________________________________________________________\n\n\n";
    cout << "\t\t\t                   Welcome to the login page of admin                     \n\n\n";
    cout << "\t\t\t____________________________MENU______________________________________\n\n\n";
    cout << "                                                                             \n";
    cout << "\t\t\t| Press 1 to LOGIN                                            |" << endl;
    cout << "\t\t\t| Press 2 to REGISTRATION for admin                           |" << endl;
    cout << "\t\t\t| Press 3 to IF YOU FORGOT PASSWORD                           |" << endl;
    cout << "\t\t\t| Press 4 to EXIT                                             |" << endl;
    cout << "\n\n\t\t\t Please enter your choice :";
    cin >> c;
    cout << endl;
    switch (c)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        system("cls");
        menu();
    default:
        system("cls");
        cout << "\t\t\t Please select from option!!!";
        mainmenu();
    }
}

/*****************************************************************FOR LOGIN *************************************************************************************/

void shopping::login()
{
    int count = 0, i = 0;
    char c = 0;
    // char password[20], userId[20], id[20], pass[20];
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password :" << endl;
    cout << "\t\t\t   USERNAME\t";
    cin >> userId;
    cout << "\t\t\t PASSWORD\t";

    do
    {
        c = getch();
        switch (c)
        {
        case 0:
            getch();
            break;
        case 13:
            cout << endl;
            break;
        case 8:
            if (password.length() > 0)
            {
                password.erase(password.end() - 1);
                cout << c << ' ' << c;
            }
            break;
        default:
            password += c;
            cout << '*';
            break;
        }
    } while (c != 13);

    ifstream input("records.txt");

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
        }
    }

    input.close();
    if (count == 1)
    {
        cout << userId << "\n Your LOGIN is successfull \n Thanks for logging in !\n";
        time_delay(10);
        system("cls");
        administrator();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your user name and password\n";
        mainmenu();
    }
}

/*****************************************************************FOR LOGIN REGISTRATION*************************************************************************************/

void shopping::registration()
{
    string rpassword, cpasswrod;
    char ruserId[20];
    int c;
    int valid = 0;
    system("cls");
    cout << endl
         << endl
         << endl;
    cout << "\t\t\t***********************************Registration********************************";
    cout << endl
         << endl;
Z:
    cout << "\t\t\t\t\t Enter the User_name : ";
    cin >> ruserId;
    for (int b = 0; b < strlen(ruserId); b++)
    {
        if (isalpha(ruserId[b]))
        {
            valid = 1;
        }
        else
        {
            valid = 0;
            break;
        }
    }
    if (!valid)
    {
        cout << "entered name contains invalid character, please enter name with alphabets only:";
        cout << endl;
        goto Z;
    }
P:
    cout << "\t\t\t\t\t Enter the Password : ";
    cin >> rpassword;
    cout << "\t\t\t\t\t Confirm passwrod: ";
    cin >> cpasswrod;
    if (rpassword == cpasswrod)
    {
        cout << "\t\t\t\t\tpassword matched." << endl;
        time_delay(20);
        ofstream f1("records.txt", ios::app);
        f1 << ruserId << ' ' << rpassword << endl;
    }
    else
    {
        cout << "password don't matched, please enter again." << endl;
        goto P;
    }

    system("cls");
    time_delay(5);
    cout << "\n\t\t\t\t\tRegistration is Successful......\n";
    time_delay(30);
    system("cls");
    mainmenu();
}

/*****************************************************************FOR LOGIN FORGOT*************************************************************************************/

void shopping::forgot()
{
    int option;
    system("cls");
    cout << "\n\t\t\t You forgot the password? don't worries \n";
    cout << "Preass 1 to search your id by username " << endl;
    cout << "press 2 to go back to main menu" << endl;
    cout << "\t\t\t Enter your choice :" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t\t Enter the username which you remembered :" << endl;
        cin >> suserId;
        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found!\n";
            cout << "\n\n Your password is :" << spass;
            time_delay(100);
            system("cls");
            mainmenu();
        }
        else
        {
            cout << "\n\t\t Sorry! your account is not found!\n";
            mainmenu();
        }
        break;
    }
    case 2:
    {
        mainmenu();
    }

    default:
        cout << "\t\t\t Wrong choice ! Please try again ..." << endl;
        mainmenu();
    }
}

/*****************************************************************MAIN MENU FOR SUPERMARKET*************************************************************************************/
void shopping::menu()
{
m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t\t...........................................\n";
    cout << "\t\t\t\t\t                                           \n";
    cout << "\t\t\t\t\t           Supermaret Main Menu               \n";
    cout << "\t\t\t\t\t                                            \n";
    cout << "\t\t\t\t\t...........................................\n";
    cout << "\t\t\t\t\t|           1) Administrator           |\n";
    cout << "\t\t\t\t\t                                        \n";
    cout << "\t\t\t\t\t|           2) Buyer                   |\n";
    cout << "\t\t\t\t\t                                        \n";
    cout << "\t\t\t\t\t|           3) Exit                    |\n";
    cout << "\t\t\t\t\t                                        \n";
    cout << "\n\n\t\t\t\t                Please select.........!\t";
    cin >> choice;
    switch (choice)
    {
    case 1:

        time_delay(5);
        system("cls");
        mainmenu();

        break;

    case 2:
    {

        time_delay(5);
        system("cls");
        mainmenu1();
    }
    case 3:
    {

        time_delay(5);
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t<<<<<<<<Thanks for Visiting Our SuperMarket>>>>>>>>\n\n\n\n\n\n\n\n\n";
        exit(0);
    }

    default:
    {
        cout << "Please select from the given option";
    }
    }
    goto m;
}

/*****************************************************************FOR ADMINSTRATOR*************************************************************************************/

void shopping::administrator()
{
m:

    int choice;

    cout << "\n\n\n\t\t\t\t\t******** Adminstrator Menu *********";
    cout << "\n\t\t\t\t\t|_______1) Add the product_________|";
    cout << "\n\t\t\t\t\t|                                  |";
    cout << "\n\t\t\t\t\t|_______2) Modify the product______|";
    cout << "\n\t\t\t\t\t|                                  |";
    cout << "\n\t\t\t\t\t|_______3) list of product_________|";
    cout << "\n\t\t\t\t\t|                                  |";
    cout << "\n\t\t\t\t\t|_______4) Delete the product______|";
    cout << "\n\t\t\t\t\t|                                  |";
    cout << "\n\t\t\t\t\t|_______5) Back to main menu_______|";

    cout << "\n\n\t Please enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        time_delay(5);
        system("cls");
        break;
    case 2:
        edit();

        break;
    case 3:
        list();
        time_delay(5);
        cout << "Enter any key to continue...\n";
        getch();
        system("cls");
        break;
    case 4:
        rem();
        break;
    case 5:
        system("cls");
        menu();
    default:
        cout << "Invalid choice";
    }

    goto m;
}

/*****************************************************************FOR BUYER*************************************************************************************/

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t    Buyer  \n";
    cout << "\t\t\t__________________\n";
    cout << "                        \n";
    cout << "\t\t\t 1) Buy product  \n";
    cout << "                       \n";
    cout << "\t\t\t 2) Go back  \n";

    cout << "\t\t\t \n\nEnter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        time_delay(5);
        system("cls");
        receipt();
        break;
    case 2:
        system("cls");
        menu();

    default:
        cout << "Invalid choice";
    }
    goto m;
}

/***************************************************************** FOR ADD THE PRODUCT *************************************************************************************/

void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t Add new  Product : ";
    cout << "\n\n\t Product code of the product : ";
    cin >> pcode;
    cout << "\n\n\t Name of the Product : ";
    cin >> pname;
    cout << "\n\n\t Price of the Product per quantity :Rs.  ";
    cin >> price;
    cout << "\n\n\t Dicount on Product : Rs. ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            time_delay(5);
            system("cls");
            cout << "\n\n\n\n\t\tproduct code is matched,add again..\n\n\n";
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    time_delay(5);
    cout << "\n\n\n\t\t\t\t Record inserted  !";
}

/*****************************************************************FOR EDIT THE PRODUCT*************************************************************************************/

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t Modify the record";
    cout << "\n\n\t\t Product code :";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File doesnot exit ";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code  :";
                cin >> c;
                cout << "\n\t\t Name of the product  :";
                cin >> n;
                cout << "\n\t\t Price  :";
                cin >> p;
                cout << "\n\t\t Discount  :";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n Record not found sorry!";
        }
    }
}

/*****************************************************************FOR DELETING THE PRODUCT*************************************************************************************/
void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesnt exist";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {

                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

/***************************************************************** FOR LISTING THE PRODUCT *************************************************************************************/
void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n___________________________________________________________\n";
    cout << "ProNO\t\tName\t\tPrice\n";
    cout << "\n\n___________________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

/*****************************************************************FOR RECEIPT FOR BUYER*************************************************************************************/

void shopping::receipt()
{

    fstream data;
    int arrc[1000];
    int arrq[1000];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "\n\n\t\t\tList of Products            ";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database !!!!!!";
    }
    else
    {
        data.close();
        list();
        cout << "\n___________________________________________________________\n";
        cout << "\n___________________________________________________________\n";
        cout << "\n                   Please place the order                  \n";
        cout << "\n___________________________________________________________\n";
        cout << "\n___________________________________________________________\n";
        do
        {
        m:
            cout << "Enter Product code :";
            cin >> arrc[c];
            cout << "\n\n Enter the product quantity : ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code. Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? if yes then press y else no : \t\t\n\n";
            cin >> choice;
        } while (choice == 'y');
        /*****************************************************************FOR RECEIPT FOR BUYER*************************************************************************************/

        time_delay(5);
        system("cls");
        cout << "\n\n_________________________________________RECEIPT___________________________________________\n";
        cout << "\nProduct No \t Product Name\t product quantity\tprice\t\tAmount\t\tAmount with discount\n";
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;

                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
    }
    cout << "\n\n____________________________________________________________________________________________";
    cout << "\n                                Total Amount :" << total << endl;
    cout << "\n\n";
paid_cash:
    payment_method(); // payment method calling function

    time_delay(5);
    system("cls");
    /*********************************************************bill printing************************************/
    string name;
    cout << "enter your name:";
    cin >> name;
    cout << "\n\n\n\n\n\n\t\t\t\tPlease wait bill is printing....." << endl;
    time_delay(20);
    system("cls");
    cout << "\t\t\t\t\tBill of: " << name << endl;
    cout << "\n\n==========================================Bill RECEIPT =======================================================\n";
    cout << "\n|| Product No \t|| Product Name\t|| product_quantity\t|| price\t|| Amount\t||Amount_with_discount\t||\n";
    for (int i = 0; i < c; i++)
    {
        data.open("database.txt", ios::in);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == arrc[i])
            {
                amount = price * arrq[i];
                dis = amount - (amount * dis / 100);
                total = total + dis;
                cout << "\n||\t" << pcode << "\t||\t" << pname << "\t||\t" << arrq[i] << "\t\t||\t" << price << "\t||\t" << amount << "\t||\t\t" << dis << "\t||";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }

    cout << "\n==============================================================================================================";
    cout << "\n                                                                                        Total Amount :" << total << endl;

    cout << "\n\n                           THANK YOU FOR CHOOSING US !!!                       " << endl;
    cout << "\n\n";
    cout << "\n\n";
    time_delay(50);
    system("cls");
    buyer();
}
#endif
