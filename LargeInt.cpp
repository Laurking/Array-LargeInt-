
/*
    Course Name: CSC-330 Data structures

    Professor: Anna Salvati

    Assignment: LargeInt 

    Header file: LargeInt.hpp
    
    Created by Sanou W. Laurent

    on 03/23/2016

    The purpose of this assignment is to implement an integer class 
    for users (clients) to be able to perform operations on large integers. 

  */


#include "LargeInt.hpp"

/*  Default constructor   */

LargeInt::LargeInt() {
    max=0;
    array=new int[max];
}

/*   constructor  takes a string value and stores its digits in the pointer array  */

LargeInt::LargeInt(string value){
    if (isValid(value)) {
        max=value.length();
        array=new int[max];
        for(long i=max-1, x=0;i>-1;i--,x++){
            array[x]=value.at(i)-'0';
        }
    }
    
    else{
        max=0;
        cout<<"You have entered an invalid value"<<endl;
        usleep(2000000);
        exit(0);
    }
    
}


/*  copy constructor   */

LargeInt::LargeInt(const LargeInt& orig) {
    if (this!=&orig) {
        max=orig.max;
        array=orig.array;
    }
}

/*   destructor   */
LargeInt::~LargeInt() {
    delete []array;
}

//
void LargeInt::operator=(const LargeInt& orig){
    if (this != &orig){
        delete [] array;
        array=NULL;
        max = orig.max;
        array = new int[max];
        for ( int i = 0; i < max; i++ ){
            array[i] = orig.array[i];
        }
    }
}



/*  overloaded extraction operator   */
ostream& operator<<(ostream& os,const LargeInt& integer){
    if (integer.max==0) {
        os<<"";
    }
    else{
        for(long i=integer.max-1;i>-1;i--){
            os<<integer.array[i];
        }
    }
    return os;
}

/*  overloaded insertion operator   */

istream& operator>>(istream& is,LargeInt& integer){
    string value;
    bool running=true;
    is>>value;
    while (running) {
        if (integer.isValid(value)) {
            running=false;
        }
        else{
            cout<<"Invalid LargeInt "<<endl;
            cout<<"Please enter a LargeInt "<<endl;
            is>>value;
        }
    }
    integer.max=value.length();
    integer.array=new int[integer.max];
    for(long i=integer.max-1,x=0;i>-1;i--,x++){
        integer.array[x]=value.at(i)-'0';
    }
    return is;
}

/*  overloaded + operator   */
LargeInt LargeInt::operator+(const LargeInt& orig){
    
    LargeInt temp;
    int temp1=0;
    int temp2=0;
    if (max > orig.max){
        temp.max = max;
    }
    else{
        temp.max = orig.max;
    }
    const int carry = 1;
    
    for (int i = 0; i < temp.max; i++)
    {
        if (i<=max) {
            temp1=array[i];
        }
        if (i<=orig.max) {
            temp2=orig.array[i];
        }
        
        
        temp.array[i]=temp1+temp2;
        
        if (temp.array[i] > 9)
        {
            temp.array[i] -= 10;
            temp.array[i + 1] += carry;
        }
    }
    if (temp.array[temp.max] == 1)
        temp.max++;
    
    return temp;
}

/*  overloaded == relational operator   */

bool LargeInt::operator==(const LargeInt& orig){
    bool verified=false;
    if (max!=orig.max) {
        verified=false;
    }
    else{
        for (int x=0; x<max; x++) {
            if (array[x]!=orig.array[x]) {
                verified=false;
                break;
            }
            else{
                verified=true;
            }
        }
    }
    return verified;
}


///////////////////////////////////////
//      Helper function             //

/*  function validates digits from a stirng input   */
bool LargeInt::isValid(const string& value){
    bool boolean=true;
    for (int i=0;i<value.length();i++){
        if (!isdigit(value.at(i))) {
            boolean=false;
        }
    }
    return boolean;
}


