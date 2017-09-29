#include <iostream>
#include "SLList.h"
using namespace std;

int main()
{
 SLList Alst;
 Alst.pop_front();// Should print an error and return
 cout << "Alst="; Alst.print(0);
 for (int i = 0; i < 5; i++) {
     Alst.push_back(i);
 }
 for (int i = 0; i < 5; i++) {
     cout << Alst.front() << endl;
     Alst.pop_front();
 }
 for (int i = 10; i < 15; i++) {
     Alst.push_back(i);
 }
 SLList Blst(Alst);//calls the copy constructor
 cout << "Alst="; Alst.print(0);
 cout << "Blst(3)=";
 Blst.print(3);
 int sum = 0;
 int size = Blst.size();
 cout << "Size of Blst is " << size << endl;
 while ( !Blst.empty()){
   sum += Blst.front();
   Blst.pop_front();
 }
 cout << "Emptied Blst to obtain sum=" << sum << endl;
 SLList Clst(Alst),Dlst;// checks copy constructor and default constructor.
 Dlst.print(0);
 for (int i = 1; i < 20; i++) {
   Dlst.push_back(i*2);
 }
 cout << Dlst << endl;
 Dlst.push_front(100);
 cout << Clst << endl;
 Alst = Dlst;// Assign D to A
 cout << Alst << endl;
 cout << "Done" << endl;
}
