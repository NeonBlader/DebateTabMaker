#ifndef DEBATETABMAKER_BRITISHWITHIRONROOM_HPP
#define DEBATETABMAKER_BRITISHWITHIRONROOM_HPP

#include <string>
#include <vector>

#include "room.hpp"
#include "../tabMakerUtility.hpp"

class BritishWithIronRoom: public Room {
public:
  BritishWithIronRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom);
  static void setIronPosition(TeamPosition ironPosition);

private:
  const unsigned int PLAYERS_COUNT = 7;
  inline static TeamPosition ironPosition_ = PROP2;
};


#endif //DEBATETABMAKER_BRITISHWITHIRONROOM_HPP
