#include "schoolRoom.hpp"

#include <stdexcept>

#include "tabMakerUtility.hpp"

SchoolRoom::SchoolRoom(const std::vector<std::string> &playersNames, std::string referee, unsigned int classroom):
    Room(std::move(referee), classroom)
{
  if (playersNames.size() != PLAYERS_COUNT) {
    throw std::invalid_argument("Count of players for school room must be 6");
  }
  teams_ = {Team(PROP, TRIPLE), Team(OP, TRIPLE)};
  assignPlayersToTeams(playersNames, teams_);
}
