//Author: Justin Drouin
//CPSC 121 Lab 7
//11/15/1991

#include <string>
#include <iostream>
//#include <time>
using namespace std;

//Fighter in the ring
class Gladiator {
private:
	int dmgMin,//The lowest amount of damage a gladiator can inflict with a successful attack
		dmgRange,//The most damage ABOVE Minimum Damage that the gladiator can inflict with a single, non-critical hit
		evasion, //The % chance (0-100) that the gladiator will completely avoid incoming damage when defending
		critical,//The % chance (0-100) that the gladiator will inflict twice (2x) the rolled damage when attacking the opponent (known as a crit)
		maxHealth,//The amount of HP a gladiator will start each fight with
		curHealth;//The amount of HP a gladiator has left before they have died and lost the fight
public:
	//How the gladiator is referenced to the user, provided somehow in the constructor
	string name;
	//string colChamp;
	//Called upon creation; prevent any uninitialized values from being available
	Gladiator();//Constructor
				//Use this to obtain all information on our gladiators, including their name.
				//Confirmation of the created gladiator is permitted but NOT required.

	//Accessor for health
	int getCurHealth();
	//int getCurHealthChamp();
	//int getmaxHealth();

	//Calculates a damage roll based on dmgMin, dmgRange, and crit
	//This would be a good place to display a crit notification
	int rollDamage();

	//Displays gladiator's stats, in one or two lines so it's pleasing in a list
	void display();//you're responsible for defining this function

	void setname();
	void setChamp();
	//Hint: Evasion should be calculated here
	//bool takeDamage(int dmgAmt);//Returns whether the gladiator was killed by the damage or not
	bool giveDamage(int dmgAmt);
};

//Displays all the stats for our gladiators
void Gladiator::display(){
	cout << name << '\n';
	cout << "Max Health: " << maxHealth <<'\n';
	cout << "Min. Damage: " << dmgMin << '\n';
	cout << "Damage Range: " << dmgRange << '\n';
	cout << "Max Damage: " << dmgMin + dmgRange << '\n';
	cout << "Evasion Chance: " << evasion << '\n';
	cout << "Crit Chance: " << critical << '\n';
}
//rolls for strike damage and critical hit chance
//returns strike or times strike by 2 if crit and returns
int Gladiator::rollDamage(){
	int strike = rand() % dmgRange + dmgMin;
	int vt = rand() % 101;
			if( vt <= critical){
				strike *= 2;
				cout << "CRITICAL STRIKE!" << "\n";
				return strike;
			}
			else {
				return strike;
			}
}
//default constructor for gladiator class
//had the getline for the gladiator names in function
//but wanted to setup and current champion that sets the name
//of the winner to the new opponent
Gladiator::Gladiator(){
	//cout << "What is your name gladiator?\n";
	//getline(cin, name);
	name = "";
	//colChamp = "ATILLA༆";
	dmgMin = 8 + rand() % 7; //8-14
	dmgRange = 16 + rand() % 7; //16-22
	evasion = 5 + rand() % 3 * 5; //percents 5, 10, or 15
	critical = 5 + rand() % 3 * 5; //percents 5, 10, or 15
	maxHealth = 150 + rand() % 3 * 50; //150, 200, or 250
	curHealth = maxHealth;
}
//takes in dmgAmt and minuses from health if evasion rolls true
//will cout evades and health check before returning
bool Gladiator::giveDamage(int dmgAmt){
	int evade = rand() % 101;
		if(evade <= evasion){
			cout << name << " evaded.\n\n";
				if(curHealth > 0)
					return false;
				else if(curHealth <= 0)
					return true;
		}
		else {
			curHealth -= dmgAmt; //subtr dmgAmt from current health
			cout << name << " striked for " << dmgAmt << "\n";
			//display remaining heath
			cout << "Remaining Health: " << curHealth << "\n\n";
			if(curHealth > 0)
				return false;
			else if(curHealth <= 0)
				return true;
		}
		return true; // added to remove warning, should never reach
}

//sets the name of your gladiator
void Gladiator::setname(){
	cout << "What is your name gladiator?\n";
	getline(cin,name);
}
//used to set the default champion
void Gladiator::setChamp(){
	name = "ATILLA༆";
}
//returns current health
int Gladiator::getCurHealth(){
	return curHealth;
}

int main(){
	char playagain = 'n'; //default for play again
	char attackcmd = 'n'; //default for attack cmd
	string winner; //current winner string
	srand(time(0));

do{ //do-while for play loop set here
Gladiator chall; //challenger object
Gladiator champ; //champion object
chall.setname(); //call to set name of challenger(you)
	if(playagain== 'n'){
		champ.setChamp(); //default champion set
	}
	if(playagain== 'y'){
		champ.name = winner; //sets the winner of last play to new champion
		//will see last name entered as the new champion next play
	}
			cout << "Welcome to the Colosseum " << chall.name << "!\n";
			cout << "You will fight and die for the entertainment of the crowd!\n";
			cout << "The Colosseum champion " << champ.name <<" approaches!\n\n";
			//display our fighters stats
			chall.display();
			cout << "\n\t\tVS.\n";
			champ.display();
			cout << "\n" << "Can he defeat the champion??\n";
			cout << "May the odds be in your favor! Prepare for glory!\n";
			cout << "Strike first? (y) or (n)\n";
			//attack first or second? Alternatively could setup to roll who goes first
			cin >> attackcmd;

	if (attackcmd == 'y'){
		bool deathchal = 0; //check for death of chall
		bool deathchamp = 0; //check for death of champ
//'y' challenger strikes first
		do {
			cout << chall.name << " strikes.\n";
			//roll for dmgAmt
			int dmgAmt = chall.rollDamage();
			//pass dmgAmt and check for death
			deathchal = champ.giveDamage(dmgAmt);
			//check if champ health is zero, display Victory and set winner & break
			if (champ.getCurHealth() <= 0){
				cout<< "Victory! " << chall.name << " wins!\n";
					winner = chall.name;
					break;
				} //champions turn
			else {
				cout << champ.name << " strikes.\n";
				dmgAmt = champ.rollDamage();
				deathchamp = chall.giveDamage(dmgAmt);
						if (chall.getCurHealth() <= 0){ //if chall died, display, break
							cout<< "You have died... " << champ.name << " defeated you!\n\n";
							break;
							}
						}
		} while (deathchal == 0 && deathchamp == 0);
	} //Alt champion attacks 1st if attackcmd is 'n' or anything other than 'y'
	else { // same functions and math as above, just reversed who goes first
		bool deathchal = 0;
		bool deathchamp = 0;

		do {
			cout << champ.name << " strikes.\n";
			int dmgAmt = champ.rollDamage();
			deathchamp = chall.giveDamage(dmgAmt);
					if (chall.getCurHealth() <= 0){
						cout<< "You have died... " << champ.name << " defeated you!\n\n";
						break;
						}
					else {
						cout << chall.name << " strikes.\n";
						int dmgAmt = chall.rollDamage();
						//cout << dmgAmt << "\n";
						deathchal = champ.giveDamage(dmgAmt);
						if (champ.getCurHealth() <= 0){
							cout<< "Victory! " << chall.name << " wins!\n";
							winner = chall.name;
							break;
							}
					}
		} while (deathchal == 0 && deathchamp == 0);
	}
//ask user if you want to play again, exits if anything other than 'y'
		cout << "Play again? (y) or (n)\n";
		cin >> playagain;
		cin.ignore(1000,'\n'); //clear our cin to avoid errors capturing again
	} while(playagain == 'y');

return 0;
}
