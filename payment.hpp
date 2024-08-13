#ifndef pay
#define pay
#include "delay.hpp"
#include <iostream>
#include <conio.h>
using namespace std;
class paid_cash
{
public:
void payment_method()
{
    int r;
    cout << "\n\n\n\n\n\t\tYour Payment method !!!";
    cout << "\n\n\n\n\t\t1. Online payment (fone_Pay payment)";
    cout << "\n\n\n\n\t\t2. Direct payment(cash payment) \n\n";
     cout << "please select your payment method... : ";
    cin >> r;
    switch(r)
    {
        case 1:
        fone_pay();
        break;
    case 2:
        cash_pay();
        break;
    
    default:
        cout << "select only these two option.";
        break;
    }
}
    void fone_pay()
    {
system("cls");
        cout << "\n\n\t\t\t\t-----[Fone]^pay-----" << endl;
        cout << "\t\t\t\t____________________" << endl;
        cout << "\t\t\t\t|  ])) . _--- =() _ |" << endl;
        cout << "\t\t\t\t| 5 + . ''' 7777 !!!|" << endl;
        cout << "\t\t\t\t|  ._  ''  .[_+]    |" << endl;
        cout << "\t\t\t\t| -_ }++_---}]+..// |" << endl;
        cout << "\t\t\t\t| [--+]  |  __ .0   |" << endl;
        cout << "\t\t\t\t| --=++...(((   ))) |" << endl;
        cout << "\t\t\t\t| ][0]   [)--=== | +|" << endl;
        cout << "\t\t\t\t|------) {}...  + /+|" << endl;
        cout << "\t\t\t\t|___________________|" << endl;
        cout << "\n\t\t\tplease scan it and pay your payment !!!\n\n";
        time_delay(20);
        cout << "\t\t\t\tThank you for online payment!!!!" << endl;
        time_delay(5);
        cout<<"enter any key to print bill...";
        getch();
        
    }

    void cash_pay()
    {
        float amount;
        cout << "\n\n\n\t\tEnter your total amount : ";
        cin >> amount;
        cout << "\n\n\n\n\t\tthank you for your cash payment....";
        cout <<"Rs."<<amount << "\trececived.\n\n";
        time_delay(5);
        cout<<"Enter any key to print the bill...\n\n";
        getch();
    }
};
#endif