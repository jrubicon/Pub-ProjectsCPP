//Author: Justin Drouin
//CPSC 121 Lab 5
//10/17/2018

#include <iostream>
#include <string>

using namespace std;
const int ASIZE = 5;

//function prototypes
void edit(int marr[]);
void Sum(int array[], int & result);
void display(int marr[]);
void sequencing(int marr[]);
bool search(int marr[], int &positionIn);
//function prototypes for bogosort
void bogosort(int marr[], int ab);
void shuffle(int marr[], int ab);
bool sorted(int marr[], int ab);


int main(){

char menu;
int marr[ASIZE];
int result;
double mean;

edit(marr); //call and set default array of five integers

do {
  cout << "Array = { "<< marr[0] << ", " << marr[1] << ", ";
  cout << marr[2] << ", " << marr[3] << ", " << marr[4] << "}\n\n";
  cout << "Please Select An Option: \n";
  cout << "(a) Sum\n" << "(b) Mean\n";
  cout << "(c) Display\n" << "(d) Sequencing\n";
  cout << "(e) Search\n" << "(f) Sort\n";
  cout << "(g) Edit\n" << "(h) Exit\n";
  cin >> menu;

//menu
  switch(menu){
    case 'a':{
      //calls sum and displays result that is passed by ref
      Sum(marr, result);
      cout << "Your sum is: " << result << '\n';
    }
    break;
    case 'b':{
      Sum(marr, result); //calls sum again incase, take result/2 and set to mean, display
      mean = result / 2.00;
      cout << "Your mean is: " << mean << '\n';
    }
    break;
    case 'c': display(marr); // display the contents of array again
    break;
    case 'd': sequencing(marr); //call sequencing function and display
    break;
    case 'e':{
      //search function
      int positionIn;
      //will return a true(1) or false(2) and print corresponding cout
      bool torf = search(marr, positionIn);
      if(torf == 1)
        cout << "True. Your value is contained in the array at index " << positionIn << "\n";
      else if(torf == 0)
        cout << "False. Your value could not be found \n";
    }
    break;
    case 'f':{
      //bogosort function
      int ab = sizeof marr / sizeof marr[0];
      bogosort(marr, ab);
    }
    break;
    case 'g': edit(marr); //call edit function again
    break;
    case 'h': //exits
    break;
    default: cout << "Invalid Option\n";
  }
} while (menu!='h');
return 0;
}

//sets default array of integers
void edit(int marr[]){
  cout << "Please enter five integers into your array:\n";
    for (int i = 0; i < ASIZE; i++){
      cout << "Integer " << i+1 <<":\n";
      cin >> marr[i];
    }
}

//sum function that sets result that is passed by ref to sum
void Sum(int array[], int & result){
  int sum = 0;
  int total = 0;
  for (int i = 0; i < ASIZE; i++){
    sum = array[i];
    total += sum;
  }
  result = total;
}

//unnecessary function just for practice
// display the contents of array again
void display(int marr[]){
  cout << "Array = { ";
  for (int i = 0; i < ASIZE; i++){
    cout << marr[i] << ", ";
  }
  cout << "}\n";
}

//sequencing function that simply displays value between each indexed value
void sequencing(int marr[]){
  int temp1 = marr[0];
  for (int i = 1; i < ASIZE; i++){
    cout << marr[i] - temp1 << " ";
    temp1 = marr[i];
  }
  cout << "\n";
}

//search function, positionIn passed by ref, simple linear search
bool search(int marr[], int &positionIn){
  int search;
  cout << "Enter a value to search for: \n";
  cin >> search;
  for (int i = 0; i < ASIZE; i++){
    //search index by index for value and return true if found, else false
    if (marr[i] == search){
      positionIn = i;
      return true;
    }
  }
    return false;
}

//Bogosort functions

//compare indexes and check if sorted and returns true or false
bool sorted(int marr[], int ab){
    while ( --ab > 0 )
        //if ab is less than the index before it, returns false
        if (marr[ab] < marr[ab-1])
            return false;
    return true;
}
void shuffle(int marr[], int ab){
    for (int i=0; i < ab; i++){
        swap(marr[i], marr[rand()%ab]);
      }
}
void bogosort(int marr[], int ab){
  int shuffleC = 0;
    while ( !sorted(marr, ab) ){
    //while not true, calls shuffle and shuffles array index values
        shuffle(marr, ab);
        shuffleC+=1; //shuffle counter
      }
      cout << shuffleC << " shuffles completed\n";
}
