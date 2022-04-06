#include "americanRoom.hpp"

#include <stdexcept>

#include <OpenXLSX.hpp>

AmericanRoom::AmericanRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom):
    TwoTeamRoom(std::move(referee), classroom)
{
  if ((playersNames.size() + teammates.size() * 2) < PLAYERS_COUNT) {
    throw std::invalid_argument("Count of available players for american room must be at least 4");
  }
  teams_ = {Team(TeamPosition::PROP, TeamType::DUO), Team(TeamPosition::OP, TeamType::DUO)};
  assignPlayersToTeams(playersNames, teammates, teams_);
}
