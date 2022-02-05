#include "team.hpp"

#include <iostream>

std::vector<std::string> Team::getPlayersNames() const {
  return playersNames_;
}

TeamPosition Team::getTeamPosition() const {
  return teamPosition_;
}

TeamType Team::getTeamType() const {
  return teamType_;
}

Team::Team(TeamPosition teamPosition, TeamType teamType):
  teamPosition_(teamPosition),
  teamType_(teamType)
{
  for (int i = 0; i < teamType_; ++i) {
    playersNames_.emplace_back("not_defined");
  }
}

std::ostream &operator<<(std::ostream &out, const Team &team)
{
  out << positionStrings[team.getTeamPosition()] << ":\n";
  for (auto names = team.getPlayersNames(); const auto &iter: names) {
    out << iter << '\n';
  }
  return out;
}