//Justin D
//CPSC 121 Lab 1
//9/01/2017
#include <iostream>
using namespace std;

int main()
{
  //declare variables
  int cents;
  int quarters;
  int dimes;
  int nickels;
  int pennies;
  //ask the user to input a number of cents
  cout << "Please input the number of cents\n";
  cin >> cents;

  //calculate quarters
  quarters = cents / 25;
  cout << cents << " cents would be " << cents / 25 << " quarters.\n";

  cents = cents % 25;

  //calculate dimes
  dimes = cents / 10;
  cout << cents / 10 <<" dimes.\n";

  cents = cents % 10;

  //calculate nickels
  nickels = cents / 5;
  cout << cents / 5 << " nickels.\n";

  cents = cents % 5;

  //calculate pennies
  pennies = cents / 1;
  cout << cents / 1 << " pennies.\n";

  //calculate total number of coins and output total
  cout << "A total of: " << quarters + dimes + nickels + pennies << " coins\n";

  return 0;
}
