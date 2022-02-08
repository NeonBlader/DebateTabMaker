#include "schoolRoom.hpp"

#include <stdexcept>

#include "../tabMakerUtility.hpp"

SchoolRoom::SchoolRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom):
    Room(std::move(referee), classroom)
{
  if (playersNames.size() < PLAYERS_COUNT) {
    throw std::invalid_argument("Count of available players for school room must be at least 6");
  }
  teams_ = {Team(PROP, TRIPLE), Team(OP, TRIPLE)};
  assignPlayersToTeams(playersNames, teammates, teams_);
}
