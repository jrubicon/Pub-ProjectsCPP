//Author: Justin Drouin
//CPSC 121 Lab 2
//<MM/DD/YY> (Current Date)

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

//get input for quizzes
  cout << "Please enter your average grade (as a % out of 100) for your quizzes. If there is no data for this category, enter -1\n";
  cin >> quizzes;

  if (quizzes == -1){
    quizSum = 0;
    quizzes = 0;
  }
    else { quizSum = 0.10; }

totalQuiz = quizzes * quizSum;

  cout << "Please enter your average grade (as a % out of 100) for your labwork. If there is no data for this category, enter -1\n";
  cin >> labwork;

  if (labwork == -1){
    labSum = 0;
    labwork = 0;
  }
    else { labSum = 0.35; }

totalLab = labwork * labSum;

  cout << "Please enter your average grade (as a % out of 100) for your midterm. If there is no data for this category, enter -1\n";
  cin >> midterm;

  if (midterm == -1){
    midSum = 0;
    midterm = 0;
  }
    else { midSum = 0.15; }

totalMid = midterm * midSum;

  cout << "Please enter your average grade (as a % out of 100) for your final. If there is no data for this category, enter -1\n";
  cin >> finalTest;

  if (finalTest == -1){
    finalSum = 0;
    finalTest = 0;
  }
    else { finalSum = 0.30; }

totalFinal = finalTest * finalSum;

  cout << "Please enter your average grade (as a % out of 100) for your participation. If there is no data for this category, enter -1\n";
  cin >> participation;

  if (participation == -1){
    partSum = 0;
    participation = 0;
  }
    else { partSum = 0.10; }

totalPart = participation * partSum;

score = ((totalLab + totalMid + totalPart + totalQuiz + totalFinal) / ((partSum + labSum + midSum + quizSum + finalSum) * 100)) * 100;

cout << "Your grade in the class is a " << score << '\n';

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
else if (score <= 59 ){
  cout << "Your grade is a F\n";
}

return 0;
}


/*  if (quizzes = -1){
    quizsum = 0;
    quizzes = 0;
  }
    else { quizsum = 0.10; }

  if (labwork = -1){
    labsum = 0;
    labwork = 0;
  }
    else { labsum = 35; }

  if (midterm = -1){
    midsum = 0;
    midterm = 0;
  }
    else { midsum = 15 }

  if (finaltest = -1){
    finalsum = 0;
    finaltest = 0;
  }
    else { finalsum = 30 }

  if (participation = -1){
    partsum = 0;
    participation = 0;
  }
    else { partsum = 10 }



  // breaktest
  else if (score >= 80 && score <= 89){
    cout << "Your grade is a B\n";
  }
  else if (score >= 70 && score <= 79){
    cout << "Your grade is a C\n";
  }
  else if (score >= 60 && score <= 69){
    cout << "Your grade is a D\n";
  }
  else if (score <= 59 ){
    cout << "Your grade is a F\n";
  }

//seperate

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
  else if (score <= 59 ){
    cout << "Your grade is a F\n";
  }
  return 0;
}
* */
