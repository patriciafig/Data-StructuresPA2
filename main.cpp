//
//  main.cpp
//  Homework2
//
//  Patricia Figueroa on 2/05/16.

//
#include <iostream>
#include <cstdlib>
#include "bag1.h"
#include <fstream>
#include <sstream>

//convert the input file in a stream
std::ifstream infile("input.dat");
using namespace std;

// FUNCTION to input the numbers from the input file
void get_set(bag& b1,bag& b2)
{
    int line=0;//count line number
    if (infile.good())
    {
        string str;
        while(getline(infile, str))
        {
            line++;
            istringstream ss(str);
            int num;
            while(ss >> num)
            {
                if(line==1)
                    b1.insert(num);
                if(line==2)
                    b2.insert(num);
            }
        }
    }
}


int main( )
{
    //define 2 bags for union and subtract operations
    bag b1,b2,u,s;
    //input the numbers in bags
    get_set(b1,b2);
    cout<<"\nBAG 1\n";
    b1.printbag();
    cout<<"\nBAG 2\n";
    b2.printbag();
    
    // Perform union operation
    u=b1+b2;
    cout<<"\nUNION BAG\n";
    u.printbag();
    
    //Perform subtract operation
    s=b1-b2;
    cout<<"\nSUBTRACT BAG\n";
    s.printbag();
    
    return EXIT_SUCCESS;
}

