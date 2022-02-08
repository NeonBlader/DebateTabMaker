#ifndef DEBATETABMAKER_BRITISHROOMFABRIC_HPP
#define DEBATETABMAKER_BRITISHROOMFABRIC_HPP

#include <vector>
#include <string>
#include <memory>

#include "roomFabric.hpp"

class BritishRoomFabric: public RoomFabric {
public:
  std::unique_ptr<Room> createRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammatesNames,
      std::string referee, unsigned int classroom) override;

  unsigned int getCountOfDuoTeamSlotsInRoom() override;
};


#endif //DEBATETABMAKER_BRITISHROOMFABRIC_HPP
