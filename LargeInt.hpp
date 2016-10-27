
/*
    Course Name: CSC-330 Data structures

    Professor: Anna Salvati

    Assignment: LargeInt 

    Implementation file: LargeInt.cpp
    
    Created by Sanou W. Laurent

    on 03/23/2016

    The purpose of this assignment is to implement an integer class 
    for users (clients) to be able to perform operations on large integers. 

  */


#ifndef LARGEINT_H
#define LARGEINT_H
#include <string>
#include <iostream>
using namespace std;
class LargeInt {
    
    friend ostream& operator<<(ostream& os, const LargeInt&);
    friend istream& operator>>(istream& is, LargeInt&);
    
private:
    
    long max;  // private  members
    int *array;
    
public:
    
    /* prototype of the default constructor */
    LargeInt();
    
    /* prototype of the constructor */
    LargeInt(string value);
    
    /* prototype of the copy constructor */
    LargeInt(const LargeInt& orig);
    
    /* prototype of the destructor */
    ~LargeInt();
    
     /* prototype of the asignment operator */
    void operator=(const LargeInt& orig);
    
    //////////////////////////////////
    //prototype of helper function //

    /* validate string input */
    bool isValid(const string&);
    
    /* prototypes of arithmetic operators */
    LargeInt operator+(const LargeInt&);
    
    bool operator==(const LargeInt& orig);
   
};
#endif /* LARGEINT_H */
