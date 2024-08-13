#ifndef timer
#define timer
#include<iostream>
using namespace std;
void time_delay(int a)
{
    int add;
    int time;
    
    time=a*10000000;
    for(int i=0;i<time;i++)
    {
        add*=i;
        add++;
        add++;
    }
}
#endif