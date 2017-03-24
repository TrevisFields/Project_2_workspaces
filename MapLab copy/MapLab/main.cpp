#include "Map.h"
#include <iostream>
using namespace std;

/*
 ERRORS FOUND SO FAR:
 After a while the problem was that the direction i was going was in a loop for each of the directions i wanted to go. i was going north in each of the four directions instead of going to the same location that was originally meant for each path. - - - [UNDER REVIEW]
 
 code breaks when you go in a square path back to the original location. - - - [UNDER REVIEW]
 */
void GoNorth(Map &map);
void GoSouth(Map &map);
void GoEast(Map &map);
void GoWest(Map &map);


int main()
{
  auto map = Map("HOME");
  
  int choice = - 1;
  
  while (choice != 0)
	 {
		system("clear");
		cout << "1) Display current location." << endl;
		cout << "2) Go North." << endl;
		cout << "3) Go South." << endl;
		cout << "4) Go East." << endl;
		cout << "5) Go West." << endl;
		cout << "6) Path To Home." << endl;
		cout << "0) Close Program" << endl;
		
		cin >> choice;
		
		
		switch (choice)
		{
		  case 1:
			 cout << "Current Location: " << map.CurrentLocation -> DisplayLocationInfo();
			 break;
			 
		  case 2:
			 GoNorth(map);
			 break;
			 
		  case 3:
			 GoSouth(map);
			 break;
			
		  case 4:
			 GoEast(map);
			 break;
			 
		  case 5:
			 GoWest(map);
			 break;
			 case 6:
			 
			 cout << "TO GET BACK HOME: " << map.GetPathBackToHome() << endl;
			 break;
			 
			 case 0:
			 break;
			 
			 default:
			 cout << "ENTER A VAILD OPTION\n";
			 break;
		}
		cin.get();
	 }
  
  return 0;
}

void GoNorth(Map &map)
{
  auto newLocation = map.CurrentLocation -> North;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  
  string name = "";
  if(newLocation == nullptr)
	 {
		int newX = currentX;
		int newY = currentY + 1;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		
		if (existing == nullptr)
		{
		  system("cls");
		  system("clear");
		  cout << "YOU HAVEN'T BEEN HERE BEFORE, PLEASE ENTER THE LOCATION NAME: ";
		  
		  cin >> name;
		  newLocation = new Location(name, newX, newY);
		  cout << "THIS PLACE IS NOW CALLED: " + name << endl;
	 }
		else if (existing == map.LookupLocationOnMap(0, 0))
		{
		  cout << "You are HOME.\n";
		}

		
		else
		{
		  
		  cout << " YOU'VE BEEN HERE BEFORE.\n" << existing -> DisplayLocationInfo();
		}

	 }
  
  else
	 {
		cout << "YOU ARE AT:" + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> South = map.CurrentLocation;
  
  map.setPathBackToHome("South");
  map.Move(newLocation);
  return;
}


void GoSouth(Map &map)
{
  auto newLocation = map.CurrentLocation -> South;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  
  string name = "";
  if(newLocation == nullptr)
	 {
		int newX = currentX;
		int newY = currentY - 1;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		if (existing == nullptr)
		{
		system("cls");
		system("clear");
		cout << "YOU HAVEN'T BEEN HERE BEFORE, ENTER A NAME FOR THE LOCATION:";
		
		cin >> name;
		newLocation = new Location(name, newX, newY);
		cout << "THIS PLACE IS CALLED: " + name << endl;
	 }
		else if (existing == map.LookupLocationOnMap(0, 0))
		{
		  cout << "You are HOME.\n";
		}

		
		else
		{
		  
		  cout << " YOU'VE BEEN HERE BEFORE.\n" << existing -> DisplayLocationInfo();
		}
  }
  else
	 {
		cout << "YOU ARE AT: " + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> North = map.CurrentLocation;
  map.setPathBackToHome("North");

  map.Move(newLocation);
  return;
}


void GoWest(Map &map)
{
  auto newLocation = map.CurrentLocation -> West;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  
  string name = "";
  if(newLocation == nullptr)
	 {
		int newX = currentX - 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		
		if (existing == nullptr)
		{
		  system("cls");
		  system("clear");
		  cout << "You haven't been here before, enter a name for this place: ";
		  
		  cin >> name;
		  newLocation = new Location(name, newX, newY);
		  cout << "This place is now called: " + name << endl;
	 }
		else if (existing == map.LookupLocationOnMap(0, 0))
		{
			cout << "You are HOME.\n";
		}
		else
		{
		  
		  cout << " You've been here before.\n" << existing -> DisplayLocationInfo();
		}

	 }
  
  else
	 {
		cout << "You are at: " + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> East = map.CurrentLocation;
  map.setPathBackToHome("East");

  map.Move(newLocation);
  return;
}


void GoEast(Map &map)
{
  auto newLocation = map.CurrentLocation -> East;
  int currentX = map.CurrentLocation -> getX();
  int currentY = map.CurrentLocation -> getY();
  
  string name = "";
  if(newLocation == nullptr)
	 {
		int newX = currentX + 1;
		int newY = currentY;
		auto existing = map.LookupLocationOnMap(newX, newY);
		if (existing == nullptr)
		{
		  system("cls");
		  system("clear");
		  cout << "You haven't been here before, enter a name for this place: ";
		  
		  cin >> name;
		  newLocation = new Location(name, newX, newY);
		  cout << "This place is now called: " + name << endl;
	 }
		else if (existing == map.LookupLocationOnMap(0, 0))
		{
		  cout << "You are HOME.\n";
		}

		
		else
		{
		  
		  cout << " You've been here before.\n" << existing -> DisplayLocationInfo();
		}
	 }
  
  else
	 {
		cout << "You are at: " + newLocation -> DisplayLocationInfo();
	 }
  newLocation -> West = map.CurrentLocation;
  map.setPathBackToHome("West");

  map.Move(newLocation);
  return;
}
