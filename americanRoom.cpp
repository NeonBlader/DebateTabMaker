#include "americanRoom.hpp"

#include <stdexcept>

#include "tabMakerUtility.hpp"

AmericanRoom::AmericanRoom(const std::vector<std::string> &playersNames, std::string referee, unsigned int classroom):
    Room(std::move(referee), classroom)
{
  if (playersNames.size() != PLAYERS_COUNT) {
    throw std::invalid_argument("Count of players for american room must be 4");
  }
  teams_ = {Team(PROP, DUO), Team(OP, DUO)};
  assignPlayersToTeams(playersNames, teams_);
}
