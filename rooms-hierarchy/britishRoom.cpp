#include "britishRoom.hpp"

#include <stdexcept>

#include "../tabMakerUtility.hpp"

BritishRoom::BritishRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom):
    FourTeamRoom(std::move(referee), classroom)
{
  if (playersNames.size() + (teammates.size() * 2) < PLAYERS_COUNT) {
    throw std::invalid_argument("Count of available players for british room must be at least 8");
  }
  teams_ = {Team(TeamPosition::PROP1, TeamType::DUO), Team(TeamPosition::OP1, TeamType::DUO),
            Team(TeamPosition::PROP2, TeamType::DUO), Team(TeamPosition::OP2, TeamType::DUO)};
  assignPlayersToTeams(playersNames, teammates, teams_);
}
