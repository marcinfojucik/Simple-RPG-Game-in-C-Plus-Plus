#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>

using namespace std;

bool player_death = false;
bool fight;
int command;
string move;
int hp, dmg, fhp, fdmg; // FUNCTIONS RESPONSIBLE FOR PLAYER HEALTH AND DAMAGE POINTS
float xp, nexp=100; // FUNCTIONS RESPONSIBLE FOR PLAYER LEVEL UP
int ehp, edmg, fedmg; // FUNCTIONS RESPONSIBLE FOR ENEMY HEALTH AND DAMAGE POINTS
int lvl=1;
int x = 2, y = 2;
void menu();
void game();
void map();
void stats();
void input();
void logic();
void hero();
void battle();
void enemy();

// MAIN MENU MECHANICS
void menu()
{
system("cls");
cout << "Welcome to the RPG Game" << endl << endl;
cout << "1. Start the Game" << endl;
cout << "2. Exit Game" << endl;
cin >> command;

switch(command)
	{
	case 1:
		{
		hero();
		}break;	
	case 2:
		{
			cout << "The Game Will Be Turned Off"; Sleep(1500);
			exit(0);
		}break;
	default:
		{
			cout << "Option Not Exist" << endl; Sleep(1500);
			menu();
		}break;
	}	
}

// CHOISE CHARACTER MECHANICS
void hero()
{
	system("cls");
	cout << "Choise Character Class" << endl << endl;
	cout << "1. Warrior" << endl;
	cout << "2. Hunter" << endl;
	cout << "3. Wizard" << endl;
	cout << "4. Barbarian" << endl;
	cout << "5. Amazon" << endl;
	cout << "6. Thief" << endl;
	cin >> command;
	
	switch(command)
	{
		case 1:
			{
				hp = 30;
				dmg = 5;
				game();
			}break;
		case 2:
			{
				hp = 25;
				dmg = 8;
				game();
			}
		case 3:
			{
				hp = 10;
				dmg = 10;
				game();
			}break;
		case 4:
			{
				hp = 100;
				dmg = 100;
				game();
			}break;
		case 5: 
			{
				hp = 20;
				dmg = 6;
				game();
			}break;
		case 6:
			{
				hp = 10;
				dmg = 8;
				game();	
			}break;
		default:
			{
				cout << "Class Not  Exist" << endl; Sleep(1500);
				hero();
			}break;
	}
}

// GAME MECHANICS
void game()
{
	system("cls");
	map();
	stats();
	input();
	logic();
}

// WWORLD MAP MECHANICS
void map()
{
	if(x==2 && y==2)
	{
		cout << "New York" << endl;
	}
		if(x==1 && y==1)
	{
		cout << "Miami" << endl;
	}
		if(x==2 && y==1)
	{
		cout << "Washington D.C." << endl;
	}
		if(x==1 && y==2)
	{
		cout << "San Francisco" << endl;
	}
}

// PLAYER INTERFACE MECHANICS
void stats()
{
	cout << "Player Position On The Map: X:" << x << "Y:" << y << endl; 
	cout << "HP: " << hp << "DMG: " << dmg << "LVL: " << lvl << "XP: " << xp << "/" << nexp << endl;
}

// STEERING MECHANICS 
void input()
{
	cin >> move;
	
	if(move=="w")
	{
		y=y+1;
	}
	else if(move=="s")
	{
		y=y-1;
	}
	else if(move=="d")
	{
		x=x+1;
	}
	else if(move=="a")
	{
		x=x-1;
	}
	else if(move=="fight")
	{
		enemy();
		battle();
	}
	else
	{
		cout << "This Command Not Exist" << endl; Sleep(1500);
		game();
	}
}

// LEVEL UP MECHANICS
void logic()
{
	if(xp>=nexp)
	{
	xp=0;
	lvl=lvl+1;
	hp+=3;
	dmg+=2;
	nexp=nexp*1.15;
	}
}

// FIGHT MECHANICS
void battle()
{
	cout << "Start Fighting" << endl; Sleep(1500);
	fhp=hp;
	system("cls");
	while(ehp>=1 && fhp>=1)
	{
		system("cls");
		cout << "PLAYER" <<"HP: " << fhp << "DMG: " << dmg << "LVL: " << lvl << "XP: " << xp << "/" << nexp << endl;
		cout << "ENEMY" << "HP: " << ehp << "DMG: " << edmg << endl << endl;
		
		fdmg = rand() % dmg; 
		cout << "Player Damage: " << fdmg << endl; 
		ehp=ehp-fdmg;
		Sleep(500);
		
		fedmg = rand() % edmg; 
		cout << "Enemy Damage: " << fedmg << endl; 
		hp=hp-fedmg;
		Sleep(500);
	}
	game();
}

// ENEMY MECHANICS
void enemy()
{
	ehp = 15;
	edmg = 2;
}

