#include "Map.h"



Map::Map(std:: string startLocationName)
{
  CurrentLocation = new Location(startLocationName, 0, 0);
  std::string hash = "(0,0)";
  _mapLookup[hash] = CurrentLocation;
  _home = startLocationName;
}



void Map::Move(Location * newLocation)
{
  _locationsVisited.push(newLocation);
  CurrentLocation = newLocation;
}

Location * Map::LookupLocationOnMap(int x, int y)
{
  std:: string hash = "(" + std::to_string(x) + "," + std::to_string(y) + ")";
  return _mapLookup[hash];
}

std:: string Map::GetHome()
{
  return _home ;
}

std:: string Map::GetPathBackToHome()
{
  return _direction + " " + GetHome() ;
}

void Map::setPathBackToHome(std::string previous)
{
  _direction = previous + " " + _direction;
}

Map::~Map()
{
  
}
