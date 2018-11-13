//Author: Justin Drouin
//CPSC 121 Lab 6
//11/11/2018

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Calculator {
	long long LHValue;
	long long * RHValue;
	char lastOperator;
};

void processInput(Calculator *, string, char &);
void removespace(string &);

int main(){
char exit = 'n';
string userInput;
//delcare calc temp var for struct Calculator
Calculator calc;

//set initial values to defaults and set ptr address and value
calc.LHValue = 0;
calc.RHValue = new long long;
*(calc.RHValue) = 0;
calc.lastOperator = '+';
cout << "Welcome to the Super Duper Cal-QUE-late-tor\n";
//do-while loop with exit condition set to input of q or Q
do {
jump: cout << "Enter a full or partial expression\n";
getline(cin,userInput);
//user enters any expression, it is then passed to removespace function by ref
removespace(userInput);
//if nothing is entered, jumps back to input, or if just a single operator is input
if(userInput == "")
	goto jump;
if(userInput == "+" || userInput == "-" || userInput == "*" || userInput == "/" || userInput == "%")
	goto jump;
//calc address is passed and received as ptr, userinput passed and exit by ref
processInput(&calc, userInput, exit);
//cout final value
cout << calc.LHValue << "\n";
} while (exit != 'q');
}


void processInput(Calculator * calc, string userInput, char & exit){
  //initialize temp strings and side default side of string to left
  //a int checker yy set to 1
  //these are used for check statements later
  string temp1, temp2;
  char side = 'l';
  //char chcheck = 'g';
  int yy = 1;

//***SECTION D: checks for exit command
	if(userInput == "q" || userInput == "Q"){
	  exit = 'q';
	  cout << "Exiting.\n";
	  return;
	  }

//***SECTION A: this section checks if there is only a number with no operators or alpha
//Will set the total to the single large number
  if(userInput[0] == '=' || userInput[0] == '+' || userInput[0] == '-' || userInput[0] == '*' || userInput[0] == '%' || userInput[0] == '/'){
    //if initial value (with spaces removed) is equal to =+-%&/
    //yy is set to 0
    yy = 0;
  }
  else if (yy != 0){
    //if yy is not set to 0, loops through and checks if string contains alpha chars
    //if so couts error and returns to main
    for(int i=0; i<userInput.size(); i++){
      if(isalpha(userInput[i])){
          cout << "Input cannot contain any characters that are neither digits,";
          cout << " an operator, or the quit command\n";
          return;
      }
      else if(!isdigit(userInput[i])){
        //if contains any non digits either, yy set to 0
        yy = 0;
      }
    }
  }
    if (yy == 1){
      //if yy still 1 through checks, loop through string and set value to temp4
          string temp4;
          for (int i = 0; i < userInput.size(); i++){
              if(isdigit(userInput[i])){
                temp4 += userInput[i];
              }
          }
          //set long long LHValue to value of temp4 and return
          calc->LHValue = stoll(temp4, 0, 10);
          return;
      }
//end SECTION A

//***SECTION B: checks for '=' sign, as long as no other chars or numbers present
//will preform previous operation’s results with the same operator and
//Right Hand value
if(userInput[0] == '='){
  for(int i=0; i<userInput.size(); i++){
    if(isalpha(userInput[i])){
      //if alpha's present, error and return
        cout << "Input cannot contain any characters that are neither digits,";
        cout << " an operator, or the quit command\n";
        return;
    }
    else if(isdigit(userInput[i])){
      //if digits present, error and return
        cout << "Invalid operation\n";
        return;
    }
    else
    continue;
  }
  //math that takes last used operator and finds the result of previous result
  //stored in LHValue and last RHValue
        if(calc->lastOperator == '+'){
          calc->LHValue = calc->LHValue + (*(calc->RHValue));
          return;
        }
        if(calc->lastOperator == '-'){
          calc->LHValue = calc->LHValue - (*(calc->RHValue));
          return;
        }
        if(calc->lastOperator == '%'){
          calc->LHValue = calc->LHValue % (*(calc->RHValue));
          return;
        }
        if(calc->lastOperator == '*'){
          calc->LHValue = calc->LHValue * (*(calc->RHValue));
          return;
        }
        if(calc->lastOperator == '/'){
          //check for division by 0, error and return
            if(*(calc->RHValue) == 0){
              cout << "cannot divide by zero!\n";
              return;
            }
            else {
            calc->LHValue = calc->LHValue / (*(calc->RHValue));
            return;
            }
        }
}
//end SECTION B

//***SECTION C: checks for an expression (some operator)(x) ie "+20"
if(userInput[0] == '+' || userInput[0] == '-' || userInput[0] == '*' || userInput[0] == '%' || userInput[0] == '/'){
//
string temp3;
//make sure index 1 contains an integer, error and return if not
//since we already checked index 0 and start at 1
//loop through and check for alpha and error if so
//otherwise concat value to temp3
    for(int i=1; i<userInput.size(); i++){
      if(isalpha(userInput[i])){
          cout << "Input cannot contain any characters that are neither digits,";
          cout << " an operator, or the quit command\n";
          return;
      }
      else if(isdigit(userInput[i])){
              temp3 += userInput[i];
      }
      else {
        cout << "Invalid Operation\n";
        return;
      }
    }
//sets lastOperator to operator at 0 index and checks
    calc->lastOperator = userInput[0];
            if (calc->lastOperator == '+' || calc->lastOperator == '-' || calc->lastOperator == '*' || calc->lastOperator == '/' || calc->lastOperator =='%'){
                //RHValue set to temp3 concat with stoll (string to long long)
                *(calc->RHValue) = stoll(temp3, 0, 10);
                    //Math
                    if(calc->lastOperator == '+'){
                      calc->LHValue = calc->LHValue + (*(calc->RHValue));
                      return;
                    }
                    if(calc->lastOperator == '-'){
                      calc->LHValue = calc->LHValue - (*(calc->RHValue));
                      return;
                    }
                    if(calc->lastOperator == '%'){
                      calc->LHValue = calc->LHValue % (*(calc->RHValue));
                      return;
                    }
                    if(calc->lastOperator == '*'){
                      calc->LHValue = calc->LHValue * (*(calc->RHValue));
                      return;
                    }
                    if(calc->lastOperator == '/'){
                        if(*(calc->RHValue) == 0){
                          //divide by 0 error message
                          cout << "cannot divide by zero!\n";
                          return;
                        }
                        else {
                        calc->LHValue = calc->LHValue / (*(calc->RHValue));
                        return;
                        }
                    }
            }
            //default error message incase anything slips through
            else {
                cout << "Input cannot contain any characters that are neither digits,";
                cout << " an operator, or the quit command\n";
                return;
            }

}
//end SECTION C


//***Section F: Calculates full expressions
if(userInput != "q" || userInput != "Q"){
  for(int i=0; i<userInput.size(); i++){
    //check for alpha characters, error and return
    if(isalpha(userInput[i])){
        cout << "Input cannot contain any characters that are neither digits,";
        cout << " an operator, or the quit command\n";
        return;
    }
  }
  if(1){
  for (int i = 0; i < userInput.size(); i++){
    //check for digit and concat onto temp1 with default side of 'l'
      if(isdigit(userInput[i])){
          if(side == 'l'){
            temp1 += userInput[i];
          }
          else if(side == 'r'){
            temp2 += userInput[i];
          }
      }
      else {
        //if not a digit then must be operator and set to lastOperator, set and
        //checks if valid sets next iteration to side r or else error and return
        calc->lastOperator = userInput[i];
          if (calc->lastOperator == '+' || calc->lastOperator == '-' || calc->lastOperator == '*' || calc->lastOperator == '/' || calc->lastOperator =='%'){
            side = 'r';
          }
            else {
              cout << "Input cannot contain any characters that are neither digits,";
              cout << " an operator, or the quit command\n";
              return;
            }
      }
  }
//Math
//set calc struct LHValue and RHValue with stoll function on temps
  calc->LHValue = stoll(temp1, 0, 10);
  *(calc->RHValue) = stoll(temp2, 0, 10);
//check operator and preform math
    if(calc->lastOperator == '+'){
      calc->LHValue = calc->LHValue + (*(calc->RHValue));
    }
    if(calc->lastOperator == '-'){
      calc->LHValue = calc->LHValue - (*(calc->RHValue));
    }
    if(calc->lastOperator == '%'){
      calc->LHValue = calc->LHValue % (*(calc->RHValue));
    }
    if(calc->lastOperator == '*'){
      calc->LHValue = calc->LHValue * (*(calc->RHValue));
    }
    if(calc->lastOperator == '/'){
      if(*(calc->RHValue) == 0){
        //divide by 0 error and return;
        cout << "cannot divide by zero!\n";
        return;
      }
      else
      calc->LHValue = calc->LHValue / (*(calc->RHValue));
    }
  }
  return;
}//end of SECTION F
}//end processInput function

//function to remove spaces
void removespace(string & userInput){
//userInput.erase(remove(userInput.begin(), userInput.end(), ' '));
//remove spaces
  string str1="";
  //loops through and sets each character to temp string unless space
   for(int j=0;j<userInput.size();j++)
   {
       if(isspace(userInput[j]))
        continue;
       else
       str1+=userInput[j];
   }
   userInput = str1;
   return;
}
