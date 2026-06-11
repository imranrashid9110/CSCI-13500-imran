#include <iostream>
using namespace std;
int main() {
   double num1, num2; //double lets use have decimal numbers
   char op; // gets the character
   
   cout << "Enter first number:"; // outputting the string
   cin >> num1; // getting the users first number input

   cout << "Enter second number:"; // outputting string 
   cin >> num2; // getting the users second number input

   cout << "Choose your calculation operation (+, -, /, *, %): ";
   cin >> op; // getting the users operator input

   if (op == '+') { // if the user inputted +
      cout << "Answer:" << num1 + num2 << endl; // it will output the calculation with their numbers
      }
   else if (op == '-') { 
      cout << "Answer:" << num1 - num2 << endl;
   }
   else if (op == '/') {
      cout << "Answer:" << num1 - num2 << endl;
   }
   else if (op == '%') {
      int number1 = num1;
      int number2 = num2; 
      cout << "Answer:" << number1 % number2 << endl;
   }
   else {
      cout << "Invalid operator input" << endl; // if the user inputted somthing else besides the listed operators, it will print invalid
   }
   return 0; 



   


}

 


