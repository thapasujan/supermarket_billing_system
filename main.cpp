#include "windows_screen.hpp"
#include "customer.hpp"
#include "delay.hpp"
#include <iostream>
using namespace std;
int main()
{
  window w;
  shopping s;
  w.window_display();
  cout << "\n\n\n\n\n\n";
  system("cls");
  s.menu();
  return 0;
}