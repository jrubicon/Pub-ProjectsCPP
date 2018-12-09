//Author: Justin Drouin
//CPSC 121 Lab 8
//12/08/2018

#include "Gladiator.h"
#include "Gladiator.cpp"
#include <vector>
using namespace std;

int main(){
srand(time(0));
char menu;
char exit = 'n';
cout << "\tWelcome to the gladiator games!\n";
vector<Gladiator> redteam;
vector<Gladiator> bluteam;

do{
	if (redteam.empty()){
		cout << "Red team: EMPTY\n";
	}
	if (bluteam.empty()){
		cout << "Blue team: EMPTY\n";
	}
cout << "Enter (a) to take a turn.\n";
cout << "Enter (b) to add fighters.\n";
cout << "Enter (c) to exit.\n";
cout << "Enter (d) to display fighters healths.\n";
cout << "Enter (e) to reset both teams.\n";
cin >> menu;

switch(menu){
	case 'a':{
		if (redteam.empty()){
			break;
		}
		if (bluteam.empty()){
			break;
		}
		int deathcheck = 0;
		int coin = rand() % 2;
		if (coin == 1){ //red team first
			for(int i = 0; i < redteam.size(); i++){
				int target = rand() % bluteam.size();
				int dmgAmt = redteam[i].rollDamage();
				cout << "RED " << redteam[i].name << " strikes BLUE " << bluteam[target].name;
				cout << " for " << dmgAmt << ".\n";
				bluteam[target].takeDamage(dmgAmt);
					if(bluteam[target].getCurHealth() <= deathcheck){
						cout << bluteam[target].name << " HAS DIED.\n";
						bluteam.erase(bluteam.begin() + target);
								if (bluteam.empty()){
									cout << "\t**RED TEAM WINS**\n";
									break;
								}
					}
					else {
						bluteam[target].display();
					}
			}
			for(int i = 0; i < bluteam.size(); i++){
				int target = rand() % redteam.size();
				int dmgAmt = bluteam[i].rollDamage();
				cout << "BLUE " << bluteam[i].name << " strikes RED " << redteam[target].name;
				cout << " for " << dmgAmt << ".\n";
				redteam[target].takeDamage(dmgAmt);
				if(redteam[target].getCurHealth() <= deathcheck){
					cout << redteam[target].name << " HAS DIED.\n";
					redteam.erase(redteam.begin() + target);
							if (redteam.empty()){
								cout << "\t**BLUE TEAM WINS**\n";
								break;
							}
				}
				else {
					redteam[target].display();
				}
			}
		}
		else { //blue team first
			for(int i = 0; i < bluteam.size(); i++){
				int target = rand() % redteam.size();
				int dmgAmt = bluteam[i].rollDamage();
				cout << "BLUE " << bluteam[i].name << " strikes RED " << redteam[target].name;
				cout << " for " << dmgAmt << ".\n";
				redteam[target].takeDamage(dmgAmt);
				if(redteam[target].getCurHealth() <= deathcheck){
					cout << redteam[target].name << " HAS DIED.\n";
					redteam.erase(redteam.begin() + target);
							if (redteam.empty()){
								cout << "\t**BLUE TEAM WINS**\n";
								break;
							}
				}
				else {
					redteam[target].display();
				}
			}
			for(int i = 0; i < redteam.size(); i++){
				int target = rand() % bluteam.size();
				int dmgAmt = redteam[i].rollDamage();
				cout << "RED " << redteam[i].name << " strikes BLUE " << bluteam[target].name;
				cout << " for " << dmgAmt << ".\n";
				bluteam[target].takeDamage(dmgAmt);
				if(bluteam[target].getCurHealth() <= deathcheck){
					cout << bluteam[target].name << " HAS DIED.\n";
					bluteam.erase(bluteam.begin() + target);
							if (bluteam.empty()){
								cout << "\t**RED TEAM WINS**\n";
								break;
							}
				}
				else {
					bluteam[target].display();
				}
			}
		}
	}
		break;

	case 'b':{
		bluteam.push_back(Gladiator());
		redteam.push_back(Gladiator());
		cout << "RED TEAM: \n";
				for(int i = 0; i < redteam.size(); i++){
					redteam[i].display();
				}
				cout << "BLUE TEAM: \n";
				for(int i = 0; i < bluteam.size(); i++){
					bluteam[i].display();
				}
		}
		break;

	case 'c':
		exit = 'y';
		break;

	case 'd':
		cout << "RED TEAM: \n";
			for(int i = 0; i < redteam.size(); i++){
				redteam[i].display();
			}
		cout << "BLUE TEAM: \n";
			for(int i = 0; i < bluteam.size(); i++){
				bluteam[i].display();
			}
		break;

	case 'e':
		for (int i = 0; i < bluteam.size(); i++){
				bluteam.erase(bluteam.begin(), bluteam.end());
			}
		for (int i = 0; i < redteam.size(); i++){
				redteam.erase(redteam.begin(), redteam.end());
			}
		break;

	default:
		cout << "please enter a valid choice\n";

}
} while (exit == 'n');
return 0;
}
