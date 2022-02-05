#ifndef DEBATETABMAKER_SCHOOLROOM_HPP
#define DEBATETABMAKER_SCHOOLROOM_HPP

#include <string>
#include <vector>

#include "room.hpp"

class SchoolRoom: public Room {
public:
  SchoolRoom(const std::vector<std::string> &playersNames, std::string referee, unsigned int classroom);

public:
  unsigned int PLAYERS_COUNT = 6;
};


#endif //DEBATETABMAKER_SCHOOLROOM_HPP
