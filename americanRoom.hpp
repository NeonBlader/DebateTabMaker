#ifndef DEBATETABMAKER_AMERICANROOM_HPP
#define DEBATETABMAKER_AMERICANROOM_HPP

#include <vector>
#include <string>

#include "room.hpp"

class AmericanRoom: public Room {
public:
  AmericanRoom(const std::vector<std::string> &playersNames, std::string referee, unsigned int classroom);

private:
  unsigned int PLAYERS_COUNT = 4;
};


#endif //DEBATETABMAKER_AMERICANROOM_HPP
