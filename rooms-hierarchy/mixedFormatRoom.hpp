#ifndef DEBATETABMAKER_MIXEDFORMATROOM_HPP
#define DEBATETABMAKER_MIXEDFORMATROOM_HPP

#include <string>
#include <vector>

#include "twoTeamRoom.hpp"
#include "../tabMakerUtility.hpp"

class MixedFormatRoom: public TwoTeamRoom{
public:
  MixedFormatRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom);
  static void setDuoTeamsPosition(TeamPosition duoTeamPosition);

private:
  static constexpr uint8_t PLAYERS_COUNT = 5;
  inline static TeamPosition duoTeamPosition_ = TeamPosition::OP;
};


#endif //DEBATETABMAKER_MIXEDFORMATROOM_HPP
