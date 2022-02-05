#include "britishWithIronRoom.hpp"

#include <stdexcept>

#include "tabMakerUtility.hpp"

BritishWithIronRoom::BritishWithIronRoom(const std::vector<std::string> &playersNames, std::string referee,
    unsigned int classroom, TeamPosition ironPosition): Room(std::move(referee), classroom)
{
  if (playersNames.size() != PLAYERS_COUNT) {
    throw std::invalid_argument("Count of players for british room with ironman must be 7");
  }
  teams_ = {Team(PROP1, DUO), Team(OP1, DUO),
            Team(PROP2, DUO), Team(OP2, DUO)};
  teams_[ironPosition - 2] = Team(ironPosition, IRON_MAN);
  assignPlayersToTeams(playersNames, teams_);
}
