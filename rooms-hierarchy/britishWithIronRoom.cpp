#include "britishWithIronRoom.hpp"

#include <stdexcept>

BritishWithIronRoom::BritishWithIronRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom):
    FourTeamRoom(std::move(referee), classroom)
{
  if ((playersNames.size() + teammates.size() * 2) < PLAYERS_COUNT) {
    throw std::invalid_argument("Count of available players for british room with ironman must be at least 7");
  }
  teams_ = {Team(TeamPosition::PROP1, TeamType::DUO), Team(TeamPosition::OP1, TeamType::DUO),
            Team(TeamPosition::PROP2, TeamType::DUO), Team(TeamPosition::OP2, TeamType::DUO)};
  teams_[static_cast<uint8_t>(ironPosition_) - 2] = Team(ironPosition_, TeamType::IRON_MAN);
  assignPlayersToTeams(playersNames, teammates, teams_);;
}

void BritishWithIronRoom::setIronPosition(TeamPosition ironPosition) {
  if (ironPosition_ < TeamPosition::PROP1) {
    throw std::invalid_argument("You can't set ironman position with team type for team types of two teams rooms");
  }
  ironPosition_ = ironPosition;
}
