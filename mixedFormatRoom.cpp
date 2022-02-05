#include "mixedFormatRoom.hpp"

#include <stdexcept>

#include "tabMakerUtility.hpp"

MixedFormatRoom::MixedFormatRoom(const std::vector<std::string> &playersNames, std::string referee,
    unsigned int classroom, TeamPosition duoTeamPosition): Room(std::move(referee), classroom)
{
  if (playersNames.size() != PLAYERS_COUNT) {
    throw std::invalid_argument("Count of players for mixed format room must be 5");
  }
  if (duoTeamPosition == PROP) {
    teams_ = {Team(PROP, DUO), Team(OP, TRIPLE)};
  } else {
    teams_ = {Team(PROP, TRIPLE), Team(OP, DUO)};
  }
  assignPlayersToTeams(playersNames, teams_);
}
