#include "mixedFormatRoom.hpp"

#include <stdexcept>

MixedFormatRoom::MixedFormatRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom):
    TwoTeamRoom(std::move(referee), classroom)
{
  if ((playersNames.size() + teammates.size() * 2) < PLAYERS_COUNT) {
    throw std::invalid_argument("Count of available players for mixed format room must be at least 5");
  }
  if (duoTeamPosition_ == PROP) {
    teams_ = {Team(PROP, DUO), Team(OP, TRIPLE)};
  } else {
    teams_ = {Team(PROP, TRIPLE), Team(OP, DUO)};
  }
  assignPlayersToTeams(playersNames, teammates, teams_);
}

void MixedFormatRoom::setDuoTeamsPosition(TeamPosition duoTeamPosition) {
  if (duoTeamPosition > OP) {
    throw std::invalid_argument("You can't set duo team position with team types for 4-way rooms");
  }
  duoTeamPosition_ = duoTeamPosition;
}
