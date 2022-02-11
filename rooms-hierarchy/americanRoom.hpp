#ifndef DEBATETABMAKER_AMERICANROOM_HPP
#define DEBATETABMAKER_AMERICANROOM_HPP

#include <vector>
#include <string>

#include "twoTeamRoom.hpp"

class AmericanRoom: public TwoTeamRoom {
public:
  AmericanRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom);

private:
  unsigned int PLAYERS_COUNT = 4;
};


#endif //DEBATETABMAKER_AMERICANROOM_HPP
