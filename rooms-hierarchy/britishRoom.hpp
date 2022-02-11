#ifndef DEBATETABMAKER_BRITISHROOM_HPP
#define DEBATETABMAKER_BRITISHROOM_HPP

#include "fourTeamRoom.hpp"

class BritishRoom: public FourTeamRoom {
public:
  BritishRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammates, std::string referee, unsigned int classroom);

private:
  const unsigned int PLAYERS_COUNT = 8;
};


#endif //DEBATETABMAKER_BRITISHROOM_HPP
