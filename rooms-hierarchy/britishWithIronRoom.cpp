#include "britishWithIronRoom.hpp"

#include <stdexcept>

BritishWithIronRoom::BritishWithIronRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom):
    FourTeamRoom(std::move(referee), classroom)
{
  if ((playersNames.size() + teammates.size() * 2) < PLAYERS_COUNT) {
    throw std::invalid_argument("Count of available players for british room with ironman must be at least 7");
  }
  teams_ = {Team(PROP1, DUO), Team(OP1, DUO),
            Team(PROP2, DUO), Team(OP2, DUO)};
  teams_[ironPosition_ - 2] = Team(ironPosition_, IRON_MAN);
  assignPlayersToTeams(playersNames, teammates, teams_);;
}

void BritishWithIronRoom::setIronPosition(TeamPosition ironPosition) {
  if (ironPosition_ < PROP1) {
    throw std::invalid_argument("You can't set ironman position with team type for team types of two teams rooms");
  }
  ironPosition_ = ironPosition;
}
