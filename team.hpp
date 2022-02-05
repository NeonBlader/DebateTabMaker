#ifndef DEBATETABMAKER_TEAM_HPP
#define DEBATETABMAKER_TEAM_HPP

#include <utility>
#include <vector>
#include <string>
#include <iosfwd>

#include "tabMakerUtility.hpp"

class Team {
public:
  Team(std::vector<std::string> playerNames, TeamPosition teamPosition, TeamType teamType):
      playersNames_(std::move(playerNames)),
      teamPosition_(teamPosition),
      teamType_(teamType)
  {}

  Team(TeamPosition teamPosition, TeamType teamType);

  std::vector<std::string> getPlayersNames() const;
  TeamPosition getTeamPosition() const;
  TeamType getTeamType() const;

private:
  std::vector<std::string> playersNames_;
  TeamPosition teamPosition_;
  TeamType teamType_;

  friend void assignPlayersToTeams(std::vector<std::string> playersNames, std::vector<Team> &teams);
};

std::ostream &operator<<(std::ostream &out, const Team &team);

#endif //DEBATETABMAKER_TEAM_HPP
