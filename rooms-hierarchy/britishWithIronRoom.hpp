#ifndef DEBATETABMAKER_BRITISHWITHIRONROOM_HPP
#define DEBATETABMAKER_BRITISHWITHIRONROOM_HPP

#include <string>
#include <vector>

#include "fourTeamRoom.hpp"
#include "../tabMakerUtility.hpp"

class BritishWithIronRoom: public FourTeamRoom {
public:
  BritishWithIronRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom);
  static void setIronPosition(TeamPosition ironPosition);

private:
  static constexpr uint8_t PLAYERS_COUNT = 7;
  inline static TeamPosition ironPosition_ = PROP2;
};


#endif //DEBATETABMAKER_BRITISHWITHIRONROOM_HPP
