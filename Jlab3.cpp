//Justin D
//CPSC 121 Lab 3
//09/24/2018


#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
using namespace std;

//proto functions
void rectangle();
void triangle();

int main()
{
  //user will choose between a rectangle or a triangle
  //and be taken to appropriate function.
char choice;
cout << "Choose between a rectangle (r) or a triangle (t): \n";
cin >> choice;

		switch (choice){
			case 'r' : rectangle(); //call rectangle function
				break;
			case 't' : triangle(); //call triangle function
				break;
			default: {
			    cout << "Invalid choice. Please enter a valid choice.\n";
        }
		}
return 0;
}


void rectangle(){ //rectangle function
string choiceTwo, word;
int width, height;
char printchoice;
	cout << "Choose between a word (w) or a width (g): \n";
  //user chooses word or width depending on choice enters word and height or width and height
	cin >> choiceTwo;
			if (choiceTwo == "w"){
				cout << "Please enter a word: \n";
				cin >> word;
				cout << "Please enter a height: \n";
				cin >> height;
					}
			else if (choiceTwo == "g"){
				cout << "Please enter a width: \n";
				cin >> width;
				cout << "Please enter a height: \n";
				cin >> height;
					}
			else {
        // else statement for invalid option
				cout << "Invalid. Please enter a valid option (case sensitive)\n";
					}
cout << "Do you want to print to a file (p), or to the console (c)?\n";
//stores users choice for if they want to print file into printchoice
cin >> printchoice;
//segment for printing rectangle to file
ofstream outputFile;
switch (printchoice){
case 'p' :
{
	//if choiceTwo was word, will create a myshape.txt file and print to it
	if (choiceTwo == "w"){
	outputFile.open ("myshape.txt");
		for (int i=0; i <= height; i++){
		outputFile << word << "\n"; // printing rectangle shape to file
		}
		outputFile.close();

	}

	else if (choiceTwo == "g"){
        // else if choiceTwo was width will print asterix in desired specifications
	outputFile.open ("myshape.txt");
		for (int i=0; i <= height; i++){
			for(int j = 1; j <= width; j++){
            		outputFile << "* ";
        		}
			outputFile << "\n"; // printing rectangle shape to file
			}
			outputFile.close();

		}
              char backtobegin; //return user to step 1
              cout << "Print complete. Would you like to exit (e) or return to step 1 (r)?\n";
              cin >> backtobegin;
              if (backtobegin == 'r'){
              main();
              }
              else if (backtobegin == 'e'){
                cout << "Exiting...";
              }
              else {
                cout << "Invalid. That is not a valid entry. Exiting...";
                //exit program
              }
		} //end case p
break;
case 'c' : //segment to print to console
{
if (choiceTwo == "w"){
//choiceTwo is equal to word then it will print the word to the console in height specs
	for (int i=0; i <= height; i++){
	cout << word << "\n"; // printing rectangle shape to file
	}
}
else if (choiceTwo == "g"){
//ChoiceTwo is equal to width then it will print asterix to the console in width & height
	for (int i=0; i <= height; i++){
		for(int j = 1; j <= width; j++){
		cout << "* ";
		}
	cout << "\n"; // printing rectangle shape to file
	}
}

              char backtobegin; //return user to step 1
              cout << "Print complete. Would you like to exit (e) or return to step 1 (r)?\n";
              cin >> backtobegin;
              if (backtobegin == 'r'){
              main();
              }
              else if (backtobegin == 'e'){
                cout << "Exiting...";
              }
              else {
                cout << "Invalid. That is not a valid entry. Exiting...";
                //exit program
              }
}
break;
default:
cout << "Invalid. Invalid choice or case sensitive option.\n";
}
}


// triangle function
void triangle(){

string choiceTwo, word, direction;
int width;
char printchoice;
//user chooses between a word or a width for how to display the triangle. Then direction
cout << "Choose between a word (w) or a width (g): \n";
cin >> choiceTwo;
		if (choiceTwo == "w"){
			cout << "Please enter a word: \n";
			cin >> word;
			cout << "Does the triangle point up (u) or down (d)? \n";
			cin >> direction;

				}
		else if (choiceTwo == "g"){
			cout << "Please enter a width: \n";
			cin >> width;
			cout << "Does the triangle point up (u) or down (d)? \n";
			cin >> direction;

				}
		else {
			cout << "Invalid. Please enter a valid option\n";
				}
//ask user if you want to print to file or console
cout << "Do you want to print to a file (p), or to the console (c)? \n";
cin >> printchoice;
ofstream outputFile;
switch (printchoice) {
case 'p':
{
if (choiceTwo == "w"){
outputFile.open ("myshape.txt");
	if (direction == "d"){
        //prints word in a down direction in shape of triangle
        	for (int i= 0; i < word.length(); i++){
                	for (int j = i; j<=word.length(); j++){
                         outputFile << word[j]; // printing triangle to console
                         }
                outputFile << "\n";
                }
        outputFile.close();
	}

	//Prints word in a up direction in shape of a triangle
	else if (direction == "u"){
        	int start = word.length();
        	start--;  // <--- equals word length - 1.
        		for (int i= 0; i < word.length(); ++i, start--){
                		for (int j = start; j < word.length(); ++j){
                                outputFile << word[j]; // printing triangle to file
                                }
                        outputFile << "\n";
                        }
       outputFile.close();
	}
}
else if (choiceTwo == "g"){
	outputFile.open ("myshape.txt");
	if (direction == "u"){
        //prints a triangle shape to file in shape of a asterix pointing up
	for (int i = 0; i <= width; ++i){
		for(int j = 0; j <= i; ++j){
		outputFile << "* "; //print triangle to file
		}
	outputFile << "\n";
	}
outputFile.close();
}
}

else if (direction == "d"){
//prints a triangle shape to file in shape of a asterix down up
	for (int i = width; i >= 0; --i){
		for(int j = i; j >= 0; --j){
		outputFile << "* "; //print triangle to file
		}
	outputFile << "\n";
	}
outputFile.close();
}
                char backtobegin; //return user to step 1
                cout << "Print complete. Would you like to exit (e) or return to step 1 (r)?\n";
                cin >> backtobegin;
                if (backtobegin == 'r'){
                main();
                }
                else if (backtobegin == 'e'){
                  cout << "Exiting...";
                }
                else {
                  cout << "Invalid. That is not a valid entry. Exiting...";
                  //exit program
                }
} //end of case P
break;
case 'c': //print to console
{
if (choiceTwo == "w"){ //word section for console
	if (direction == "d"){ //print triangle down direction in words
                    for (int i= 0; i < word.length(); i++){
                          for (int j = i; j<=word.length(); j++){
                            cout << word[j]; // printing triangle to console
                          }
                     cout << "\n";
                     }
	}

	else if (direction == "u"){ //print triangle up direction in words
        int start = word.length();
        start--;  // <--- equals word length - 1.
		for (int i= 0; i < word.length(); ++i, start--){
			for (int j = start; j < word.length(); ++j){
			cout << word[j]; // printing triangle to console
			}
		cout << "\n";
		}

	}
}
else if (choiceTwo == "g"){ //width section for console
	if (direction == "u"){ //print triangle to console with asterix up dir.
		for (int i = 0; i <= width; ++i){
			for(int j = 0; j <= i; ++j){
			cout << "* ";
			}
		cout << "\n";
		}
	}
	else if (direction == "d"){ //print triangle to console with asterix down dir.
		for (int i = width; i >= 0; --i){
			for(int j = i; j >= 0; --j){
			cout << "* ";
			}
		cout << "\n";
		}
	}
}
    char backtobegin; //return user to step 1
    cout << "Print complete. Would you like to exit (e) or return to step 1 (r)?\n";
    cin >> backtobegin;
    if (backtobegin == 'r'){
        main();
    }
    else if (backtobegin == 'e'){
        cout << "Exiting...";
    }
    else {
        cout << "Invalid. That is not a valid entry. Exiting...";
        //exit program
    }
} //end bracket for case c
break;
default:
cout << "Invalid choice or case sensitive option.";
} //end of switch
} //end function of triangle
