
/*
    Course Name: CSC-330 Data structures

    Professor: Anna Salvati

    Assignment: LargeInt 

    Client file: main.cpp
    
    Created by Sanou W. Laurent

    on 03/23/2016

    The purpose of this assignment is to implement an integer class 
    for users (clients) to be able to perform operations on large integers. 

  */


#include <cstdlib>
#include "LargeInt.hpp"
using namespace std;


int main() {
   
    LargeInt  x, y, z;
    
    cout << "Enter an integer of your choice : ";
    cin >> x;
    
    
    cout << "Enter an integer of your choice : ";
    cin >> y;
    
  //  if ( x == y )
   //     cout<<"\n\nThe two numbers entered are equal";
  //  else
  //      cout<<"\n\nThe two numbers entered are different";
    
    z = x + y;
    cout<<z<<endl;
    
    //cout<<"\n\nThe sum of  "<<x<<" and "<<y<<" is : "<<z;
    
    return 0;
}

