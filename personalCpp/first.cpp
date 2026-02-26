//Write a program to print Hello, World on the standard output.
#include <iostream>

int main(){
    
    int sum,input;
    sum = input = 0;

    std::cout << "Enter your number: " << std::endl;

    while(std::cin >> input){
        sum+= input;
    }
    
    std::cout << "The sum is: " << sum << std::endl;
    return 10;
}