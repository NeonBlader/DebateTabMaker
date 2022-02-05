#ifndef DEBATETABMAKER_BRITISHROOM_HPP
#define DEBATETABMAKER_BRITISHROOM_HPP

#include "room.hpp"

class BritishRoom: public Room {
public:
  BritishRoom(const std::vector<std::string> &playersNames, std::string referee, unsigned int classroom);

private:
  const unsigned int PLAYERS_COUNT = 8;
};


#endif //DEBATETABMAKER_BRITISHROOM_HPP
