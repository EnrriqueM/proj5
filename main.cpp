//  CSUF CPSC 254, Fall 2017 Assignment 6
//
// Team Members:
// David Williams-Haven
// Dat Nguyen
// Enrique Mendoza
// Walid El Mir
//
// Filename: main.cpp

#include <iostream>
#include <string>
#include <fstream>

#include "fileReader.hpp"
#include "word.hpp"
#include "parse.hpp"

using namespace std;

void output(fileRead);	//Write output

int main(int argc, const char* argu[])
{
    string filename;            //Holds filename
    
    //Check if an argument has been passed
    if (argc < 2)
    {
        cout << "Missing Filename" << endl;
        return 1;
    }
    
    //Check if file opens
    ifstream fin(argu[1]);
    if (!fin)
    {
        cout << "File not found" << endl;
        return 1;
    }
    fin.close();
    
    //Save source file
    filename = argu[1];
    fileRead log1(filename);
    
	output(log1);
	
	freopen("data.txt","w",stdout); // write into data.txt 
	parse p(log1);
	
    
    
    
    
    return 0;
}

void output(fileRead log1)
{
	int words = 0;
    int count = log1.getAddress().size();
    for (int i = 0; i < count; i++)
    {
		cout << i << " Time: " << log1.getRelTime()[i] << endl;
	}
}
