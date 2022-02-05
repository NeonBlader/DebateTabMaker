#include "britishRoom.hpp"

#include <stdexcept>

#include "tabMakerUtility.hpp"

BritishRoom::BritishRoom(const std::vector<std::string> &playersNames, std::string referee, unsigned int classroom):
    Room(std::move(referee), classroom)
{
  if (playersNames.size() != PLAYERS_COUNT) {
    throw std::invalid_argument("Count of players for british room must be 8");
  }
  teams_ = {Team(PROP1, DUO), Team(OP1, DUO),
            Team(PROP2, DUO), Team(OP2, DUO)};
  assignPlayersToTeams(playersNames, teams_);
}
