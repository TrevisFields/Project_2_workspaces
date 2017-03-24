#pragma once
#include <stack>
#include "Location.h"
#include <unordered_map>

class Map
{
private:
  std:: stack<Location *> _locationsVisited;
  std:: unordered_map <std:: string, Location *> _mapLookup;
  
  std::string _home;
  std::string _direction;
public:
  Map(std:: string startLocationName);
  ~Map();
  
  Location * CurrentLocation = nullptr;
  std:: string GetPathBackToHome();
  std:: string GetHome();
  void Move(Location * newLocation);
  Location * LookupLocationOnMap(int x, int y);
  void setPathBackToHome(std::string previous);
};
