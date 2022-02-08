#include "americanRoom.hpp"

#include <stdexcept>

#include "../tabMakerUtility.hpp"

AmericanRoom::AmericanRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom):
    Room(std::move(referee), classroom)
{
  if (playersNames.size() < PLAYERS_COUNT) {
    throw std::invalid_argument("Count of available players for american room must be at least 4");
  }
  teams_ = {Team(PROP, DUO), Team(OP, DUO)};
  assignPlayersToTeams(playersNames, teammates, teams_);
}
