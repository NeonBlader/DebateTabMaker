#ifndef DEBATETABMAKER_MIXEDFORMATROOM_HPP
#define DEBATETABMAKER_MIXEDFORMATROOM_HPP

#include <string>
#include <vector>

#include "room.hpp"
#include "../tabMakerUtility.hpp"

class MixedFormatRoom: public Room{
public:
  MixedFormatRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom);
  static void setDuoTeamsPosition(TeamPosition duoTeamPosition);

private:
  unsigned int PLAYERS_COUNT = 5;
  inline static TeamPosition duoTeamPosition_ = OP;
};


#endif //DEBATETABMAKER_MIXEDFORMATROOM_HPP
