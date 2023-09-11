#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void rules ();
int
main ()
{
  string playerName;
  int balance;
  int bettingAmount;
  int guess;
  int dice;			// 
  char choice;
  char again;
  int borrowed;
  srand (time (0));
  cout << "\n\t\t========WELCOME TO ROYAL CASINO =======\n\n";
  cout << "\n\nWhat's your Name :";
  getline (cin, playerName);
  cout << "\n\nEnter the starting balance to play game: Rs";
  cin >> balance;
  do
    {
      system ("clear");
      rules ();
      cout << "\n\nYour current balance is Rs " << balance << "\n";
// Get player's betting balance
      do
	{
	  cout << "Hey, " << playerName << ", enter amount to bet : Rs";
	  cin >> bettingAmount;
	  if (bettingAmount > balance)
	    cout << "Betting balance can't be more than current balance!\n"
	      << "\nRe-enter balance\n ";
	}
      while (bettingAmount > balance);
// Get player's numbers
      do
	{
	  cout << "Guess any betting number between 1 & 10 :";
	  cin >> guess;
	  if (guess <= 0 || guess > 10)
	    cout << "\nNumber should be between 1 to 10\n"
	      << "Re-enter number:\n ";
	}
      while (guess <= 0 || guess > 10);
      dice = rand () % 10 + 1;
      if (dice == guess)
	{
	  cout << "\n\nYou are in luck...!! You have won Rs" << bettingAmount
	    * 10;
	  balance = balance + bettingAmount * 10;
	}
      else
	{
	  cout << "Oops, better luck next time p. You lost Rs " <<
	    bettingAmount << "\n";
	  balance = balance - bettingAmount;
	}
      cout << "\nThe winning number was: " << dice << "\n";
      cout << "\n" << playerName << ", You have balance of Rs " << balance <<
	"\n";
      if (balance == 0)
	{
	  cout << "You have no money to play\nDo you want to borrow some money y/n ";
	  cin>>choice;
	  if(choice=='y'||choice=='Y'){
	      cout<<"How much amount you want to borrow ?"<<endl;
	      cin>>borrowed;
	      balance+=borrowed;
	      cout<<"Your new balance is :"<<balance;
	  }
      else
      break;
	}
	else if(balance!=0){
      cout << "\n\n-->Do you want to play again\t(y/n)? ";
      cin >> choice;
    }
    }
  while (choice == 'Y' || choice == 'y');
  cout << "\n\n\n";
  cout << "\n\nThanks for playing the game. Your balance is Rs " << balance <<"\n\n";
  return 0;
}
void
rules ()
{
  system ("clear");
  cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
  cout << "\t1. Choose a number between 1 to 10\n";
  cout << "\t2. Winner gets 10 times of the money bet\n";
  cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}


