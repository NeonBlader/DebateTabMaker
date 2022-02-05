#ifndef DEBATETABMAKER_MIXEDFORMATROOM_HPP
#define DEBATETABMAKER_MIXEDFORMATROOM_HPP

#include <string>
#include <vector>

#include "room.hpp"

class MixedFormatRoom: public Room{
public:
  MixedFormatRoom(const std::vector<std::string> &playersNames, std::string referee, unsigned int classroom,
      TeamPosition duoTeamPosition = OP);

private:
  unsigned int PLAYERS_COUNT = 5;
};


#endif //DEBATETABMAKER_MIXEDFORMATROOM_HPP
