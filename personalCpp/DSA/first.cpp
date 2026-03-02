#include <iostream>
#include <string>
#include <vector>
#include "Structures.h"


using std::cout,std::cin,std::endl,std::string,std::vector,std::toupper;

int dispMenu();
int inputNumber(string str);

int main(){
    
    vector<int> myVector;
    for(int i = 0; i < 10; i++){
        myVector.push_back(i);
    }
    
    for(auto it = myVector.begin(); it != myVector.end() ; it++){
        *(it) *= 2;
    }
        
    cout << endl;

    for(auto it = myVector.begin(); it != myVector.end() ; it++)
        cout << "[" << *(it) << "]";
    cout << endl;


    return 0;
}

int dispMenu(){
    int option = 0;
    cout << "[1] to enter new element" << endl;
    cout << "[2] print current elements" << endl;
    cout << "[3] exit program" << endl;
    cout << "Choose your option: ";
    cin >> option;
    return option;
}

int inputNumber(string str){
    int option = 0;
    cout << str << endl;
    cin >> option;
    return option;
}

/*
Exercise 3.16: Write a program to print the size and contents of the vectors from
exercise 3.13. Check whether your answers to that exercise were correct. If not, restudy
§ 3.3.1 (p. 97) until you understand why you were wrong.

Exercise 3.17: Read a sequence of words from cin and store the values a vector. Af-
ter you’ve read all the words, process the vector and change each word to uppercase.

Print the transformed elements, eight words to a line.
Exercise 3.18: Is the following program legal? If not, how might you fix it?
vector<int> ivec;
ivec[0] = 42;
Exercise 3.19: List three ways to define a vector and give it ten elements, each with
the value 42. Indicate whether there is a preferred way to do so and why.
Exercise 3.20: Read a set of integers into a vector. Print the sum of each pair of
adjacent elements. Change your program so that it prints the sum of the first and last
elements, followed by the sum of the second and second-to-last, and so on.
*/