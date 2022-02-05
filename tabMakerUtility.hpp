#ifndef DEBATETABMAKER_TABMAKERUTILITY_HPP
#define DEBATETABMAKER_TABMAKERUTILITY_HPP

#include <string>
#include <vector>
#include <OpenXLSX.hpp>

class XLDocument;

class Team;

enum TeamPosition {
  PROP,
  OP,
  PROP1,
  OP1,
  PROP2,
  OP2
};

enum TeamType {
  IRON_MAN = 1,
  DUO,
  TRIPLE
};

const std::vector<std::string> positionStrings = {{"Proposition"}, {"Opposition"},
                                                  {"First Proposition"}, {"First Opposition"},
                                                  {"Second Proposition"}, {"Second Opposition"}};

void assignPlayersToTeams(std::vector<std::string> playersNames, std::vector<Team> &teams);
std::vector<std::string> getNamesFromXLSX(const std::string &filePath, unsigned int startRow = 2,
    unsigned int startColumn = 2);

#endif //DEBATETABMAKER_TABMAKERUTILITY_HPP
