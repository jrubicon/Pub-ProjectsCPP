///Author: Justin Drouin
//CPSC 121 Lab 2
//09/11/2018

#include <iostream>
using namespace std;

int main(){
    
    //declare variables
    double score,
    quizzes, quizSum, totalQuiz,
    labwork, labSum, totalLab,
    midterm, midSum, totalMid,
    finalTest, finalSum, totalFinal,
    participation, partSum, totalPart;
    
    //get input for quizzes; average score for quizzes
    cout << "Please enter your average grade (as a % out of 100) for your quizzes. If there is no data for this category, enter -1\n";
    cin >> quizzes;
    
    //check quiz statement and assign values for percent worth; also -1 evaluates to no data
    if (quizzes == -1){
        quizSum = 0;
        quizzes = 0;
    }
    else { quizSum = 0.10; }
    
    totalQuiz = quizzes * quizSum; // forumula; average grade for quizzes * percent worth
    // get input for labwork; average score for labwork
    cout << "Please enter your average grade (as a % out of 100) for your labwork. If there is no data for this category, enter -1\n";
    cin >> labwork;
    //check labwork statement and assign values for percent worth; also -1 evaluates to no data
    if (labwork == -1){
        labSum = 0;
        labwork = 0;
    }
    else { labSum = 0.35; }
    
    totalLab = labwork * labSum; // forumula; average grade for labwork * percent worth
    // get input for midterm; average score for midterm
    cout << "Please enter your average grade (as a % out of 100) for your midterm. If there is no data for this category, enter -1\n";
    cin >> midterm;
    //check midterm statement and assign values for percent worth; also -1 evaluates to no data
    if (midterm == -1){
        midSum = 0;
        midterm = 0;
    }
    else { midSum = 0.15; }
    
    totalMid = midterm * midSum; // formula; average grade for midterm * percent worth
    // get input for final test; average score for final
    cout << "Please enter your average grade (as a % out of 100) for your final. If there is no data for this category, enter -1\n";
    cin >> finalTest;
    //check finaltest statement and assign values for percent worth; also -1 evaluates to no data
    if (finalTest == -1){
        finalSum = 0;
        finalTest = 0;
    }
    else { finalSum = 0.30; }
    
    totalFinal = finalTest * finalSum; //formula; average grade for final * percent worth
    // get input for participation; average grade for participation
    cout << "Please enter your average grade (as a % out of 100) for your participation. If there is no data for this category, enter -1\n";
    cin >> participation;
    //check participation statement and assign values for percent worth; also -1 evaluates to no data
    if (participation == -1){
        partSum = 0;
        participation = 0;
    }
    else { partSum = 0.10; }
    
    totalPart = participation * partSum; // formula; average grade for participation * percent worth
    //final formula for overall current grade in class
    score = ((totalLab + totalMid + totalPart + totalQuiz + totalFinal) / ((partSum + labSum + midSum + quizSum + finalSum) * 100)) * 100;
    
    if (score >= 0){
        cout << "Your grade in the class is a " << score << '\n'; // Your grade in the class is a..
    }
    else {
        cout << "Please enter atleast one value to determine your percent\n";
    }
    //check statement assigning letter grades for value ranges and outputting grade,
    if (score >= 90 && score <= 100){
        cout << "Your grade is a A\n";
    }
    else if (score >= 80 && score <= 89){
        cout << "Your grade is a B\n";
    }
    else if (score >= 70 && score <= 79){
        cout << "Your grade is a C\n";
    }
    else if (score >= 60 && score <= 69){
        cout << "Your grade is a D\n";
    }
    else if (score <= 59 && score >=0){
        cout << "Your grade is a F\n";
    }
    else {
        cout << "Please enter atleast one value to determine your current grade\n";
    }
    return 0;
}
