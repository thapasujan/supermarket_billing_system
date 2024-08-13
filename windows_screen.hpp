#ifndef windowscreen
#define windowscreen
#include <iostream>
#include<conio.h>
using namespace std;
class window
{
public:
    void window_display()
    {
        cout << "\t\t\t\t\t#######################################################\t\t\t\t\t " << endl;
        cout << "                                                             \n";
        cout << "\t\t\t\t\t-----------------------Welcome To----------------------" << endl;
        cout << "                                                             \n";
        cout << "\t\t\t\t\t--------------SuperMarket Billing System---------------" << endl;
        cout << "                                                             \n";
        cout << "\t\t\t\t\t----COLLEGE OF INFORMATION TECHNOLOGY & ENGINEERING----" << endl;
        cout << "                                                             \n";
        cout << "\t\t\t\t\t#######################################################\t\t\t\t\t " << endl;
        cout << "\t\t\t\t\t__________________________BIT-II________________________" << endl;
        cout << "\t\t\t\t\t________________________Project-II______________________" << endl;
        cout << "\t\t\t\t\t_______________________Prepared by:_____________________" << endl;
        cout << "\t\t\t\t\t      |Sujan Thapa| |Raman Chaudhary| |Anish Chaudhary| " << endl;
        cout<<"\n\n\n\n\t\t\t";
        cout<<"Press any key to continue......";
        getch();
    }
};
#endif