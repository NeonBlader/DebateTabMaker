#ifndef DEBATETABMAKER_SCHOOLROOM_HPP
#define DEBATETABMAKER_SCHOOLROOM_HPP

#include <string>
#include <vector>

#include "twoTeamRoom.hpp"

class SchoolRoom: public TwoTeamRoom {
public:
  SchoolRoom(std::vector<std::string> &playersNames,
     std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom);

public:
  unsigned int PLAYERS_COUNT = 6;
};


#endif //DEBATETABMAKER_SCHOOLROOM_HPP
