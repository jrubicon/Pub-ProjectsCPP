//Justin Drouin
//10/11/2018
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string getInput();
string printBetween(int a, int b, int step = 1);
string nonalnum_removed(string input);
string alphabet_numberified(string input);
int sumDigits(string digitString);
void saveString(string savedStr);


int main(){
char menu, back2b = 'm';
string mainstr = "This is schwiftyy"; //default main string
do {
    cout << mainstr << "\n\n";
    cout << "Select a menu item:\n" << "(a) Store a new string\n";
    cout << "(b) String printBetween\n" << "(c) String nonalnum_removed\n";
    cout << "(d) String alphabet_numberified\n" << "(e) Sum of digits\n";
    cout << "(f) Save String to file\n";
    cin >> menu; //select menu choice

switch (menu){
case 'a':
/* calls getinput function and sets main string to new string
couts new strings */
{
  mainstr = getInput(); //call
  cout << "Your new string is:\n" << mainstr << "\n";
}
break;
case 'b':
/* Enter a value for A and B, call function and set main string
value to all the numbers between a and b */
{
  int a, b, step;
  cout << "Please enter a value for 'A':\n";
  cin >> a;
  cout << "Please enter a value for 'B':\n";
  cin >> b;

  cout << "Your string containing all numbers between a and b:\n";
  mainstr = printBetween(a, b); //call
  cout << mainstr << "\n";
}
break;
case 'c':
/* Prompt to use same or new string, call function and return
string containing only numbers and letters and set main string */
{
  char q;
  cout << "Use current string? (y) (n)\n";
  cin >> q;
  if (q == 'n'){
    string newstr;
    cout << "Please enter your new string:\n";
    cin.ignore();
    getline(cin, newstr);
    mainstr = nonalnum_removed(newstr); //call
    cout << "Your string containing only numbers and letters:\n";
    cout << mainstr << "\n";
  }
  else {
    mainstr = nonalnum_removed(mainstr); //call
    cout << "Your string containing only numbers and letters:\n";
    cout << mainstr << "\n";
  }
}
break;
case 'd':
/* Prompt to use same or new string, call function and return
string containing (only) alphabetic characters converted to
their character codes set main string */
{
  char q;
  cout << "Use current string? (y) (n)\n";
  cin >> q;
  string newstr;

  if (q == 'n'){
    cout << "Please enter your new string:\n";
    cin.ignore();
    getline(cin, newstr);
    mainstr = alphabet_numberified(newstr); //call
    cout << "Your string except with (only) alphabetic characters converted to their character codes:\n";
    cout << mainstr << "\n";
  }
  else {
    mainstr = alphabet_numberified(mainstr); //call
    cout << "Your string except with (only) alphabetic characters converted to their character codes:\n";
    cout << mainstr << "\n";
  }
}
break;
case 'e':
/* Prompt to use same or new string, call function and return
sum of the digits within string, Inclusion of non-digit characters
should result in a notification (via cout) of the character that
could not be summed up */
{
  char q;
  int sum;
  cout << "Use current string? (y) (n)\n";
  cin >> q;
  string newstr;

  if (q == 'n'){
    cout << "Please enter your new string:\n";
    cin.ignore();
    getline(cin, newstr);
    mainstr = newstr;
    sum = sumDigits(newstr); //call
    cout << "Your string sum is:\n";
    cout << sum << "\n";
  }
  else {
    sum = sumDigits(mainstr); //call
    cout << "Your string sum is:\n";
    cout << sum << "\n";
  }
}
break;
case 'f':
/* Call function, prints the current string’s
contents to a file named DrouinJLab4.txt */
{
  saveString(mainstr); //call
}
break;
default: //if invalid switch choice, default
  cout << "please enter a valid option\n";
}
//loop to take back to the main menu
cout << "would you like to return back to the menu or exit?\n";
cout << "(m) Menu\n(e) Exit\n";
cin >> back2b;
if (back2b == 'e')
  cout << "Exiting...\n";

} //end of do
while(back2b == 'm');
}//end of main

//'a' menu function
string getInput(){
    string newstr;
    cout << "Please enter your new string:\n";
    cin.ignore();
    getline(cin, newstr);

    return newstr; //return new string
}

//'b' menu function
string printBetween(int a, int b, int step){
  //pass ints a, b, step
    string betweenstring;
  //prints numbers between a and b, to_string converts to string
  //and stores it in betweenstring. Returns betweenstring.
    if (a < b){
       for (int i = a; i <= b; i+=step)
          betweenstring += to_string(i);
    }
    else if (a > b){
       for (int i = b; i <= a; i+=step)
          betweenstring += to_string(i);
    }
    else {
       for (int i = a; i <= b; i+=step)
          betweenstring += to_string(i);
    }
return betweenstring;
}

//'c' menu function
string nonalnum_removed(string input){
  string removstr = input;
  //removes all characters that are neither digits nor alphabetic
  for(size_t i = 0; i < removstr.size(); ++i)
      while(!isalnum(removstr[i]) && i < removstr.size())
        removstr.erase(i,1);

        input = removstr;
        return input;
}

//'d' menu function
string alphabet_numberified(string input){
  string alphanum = input;
  string newst;
  int b;
//convert alphabetic characters to their character codes within the string
        for (int i = 0; i < alphanum.length(); i++){
           if (isdigit(alphanum[i])){
              newst += alphanum[i];
           }
           //**skeleton for removing spaces or adding to new string**
           /*else if (isspace(alphanum[i])){
             alphanum.erase(i,0); // removes spaces other wise use--
             //newst += " ";
           } */
           else {
             b = int(alphanum[i]);
             //b = stoi(alphanum.substr(i,1)); doesnt work here
             //Used int() instead and fixed the issue
             newst += to_string(b);
           }
        }
        return newst;
}

//'e' menu function
int sumDigits(string digitString){
  string temphold;
  int a, b, sum = 0;
  //sums up digits, if not a digit displays a error message, including spaces
        for (int i = 0; i < digitString.length(); i++){
           if (isdigit(digitString[i])){
              temphold = digitString[i];
              b = stoi(temphold);
              sum = sum + b;
           }

          //**skeleton for removing spaces and converting char to ascii**
          /* else if (isspace(digitString[i])){
             //digitString.erase(i,0); // removes spaces otherwise use--
             //newst += " ";
           }
           else {
             b = int(digitString[i]);
             sum = sum + b;
             cout << "'" << digitString[i] << "'" << " was converted to its ascii value\n";
           } */

           else {
             cout << "'" << digitString[i] << "'" << " is not a digit. It could not be summed up.\n";
           }
        }
        return sum;
}

//'f' menu function
//simple function that saves the main string to a file.
void saveString(string savedStr){
ofstream fout;
fout.open ("DrouinJLab4.txt");
fout << savedStr;
fout.close();
}
