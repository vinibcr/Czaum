#include <stdio.h>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;
void welcome();
float decision(string);
float sides(float &, float &, float &, float &, float &);
int main(int argc, char *argv[])
{
welcome();
 
  return 0;
}
void welcome(){
int menu;
float valuea;
float valueb;
float valuec;
float valueao;
float valuebo;
float valueco;
cout << "Trig Calculator" << endl << endl;
cout << "Select problem type\n1. Right angle triangle" << endl;
cin >> menu;
switch(menu){
case 1:
 
 cout << "If you do not know the value use 0.\n\n";
 valuea = decision("Do you know side A?\n");
 valueb = decision("Do you know side B?\n");
 valuec = decision("Do you know side C?\n");
 valueao = decision("Do you know angle A?\n");
 valuebo = decision("Do you know angle B?\n");
 sides(valuea, valueb, valuec, valueao, valuebo);
 cout << "\n\nTriangle calculated:\n\n";
 cout << "Side A: " << valuea << endl;
 cout << "Side B: " << valueb << endl;
 cout << "Side C: " << valuec << endl;
 cout << "Angle A: " << valueao << endl;
 cout << "Angle B: " << valuebo << endl << endl;
 welcome();
 }
 
}
float decision(string question){
float value;
float radian = 3.1415/180;
cout << question;
cin >> value;
return value;
}
float sides(float &a, float &b, float &c, float &ao, float &bo){
float radian = 3.1415/180;
if(a !=0 && b!=0 && c==0){
c = sqrt(a * a + b * b);
}
if(a !=0 && c!=0 && b==0){
b = sqrt(c * c - a * a);
}
if(a ==0 && c!=0 && b!=0){
a = sqrt(c * c - b * b);
}
//TAN with side A
if(a!= 0 && b==0 && c==0){
if(ao !=0){
b = a/tan(ao*radian);
if(bo == 0){
bo = 90-ao;
}
}
if(bo !=0){
b = a*tan(bo*radian);
if(ao == 0){
ao = 90-bo;
}
}
c = sqrt((a*a)+(b*b));
}
//tan with sideB
if(a == 0 && b!=0 && c==0){
if(ao !=0){
a = b*tan(bo*radian);
if(bo == 0){
bo = 90-ao;
}
}
if(bo !=0){
a = b/tan(bo*radian);
if(ao == 0){
ao = 90-bo;
}
}
c = sqrt((a*a)+(b*b));
}
//sin with sideC
if(a == 0 && b==0 && c!=0){
if(ao !=0){
a = c*sin(ao*radian);
if(bo == 0){
bo = 90-ao;
}
}
if(bo !=0){
a = c*cos(bo*radian);
if(ao == 0){
ao = 90-bo;
}
}
b = sqrt((c*c)+(a*a));
}
if(ao == 0 && bo ==0){
ao = atan(a/b)*180/3.141592654;
bo = 90 - ao;
}
}
