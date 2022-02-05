#ifndef DEBATETABMAKER_BRITISHWITHIRONROOM_HPP
#define DEBATETABMAKER_BRITISHWITHIRONROOM_HPP

#include <string>
#include <vector>

#include "room.hpp"

class BritishWithIronRoom: public Room {
public:
  BritishWithIronRoom(const std::vector<std::string> &playersNames, std::string referee, unsigned int classroom,
      TeamPosition ironPosition = PROP2);

private:
  const unsigned int PLAYERS_COUNT = 7;
};


#endif //DEBATETABMAKER_BRITISHWITHIRONROOM_HPP
