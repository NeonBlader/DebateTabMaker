#ifndef DEBATETABMAKER_AMERICANROOMFABRIC_HPP
#define DEBATETABMAKER_AMERICANROOMFABRIC_HPP

#include <vector>
#include <string>
#include <memory>

#include "roomFabric.hpp"
#include "../rooms-hierarchy/room.hpp"

class AmericanRoomFabric: public RoomFabric {
public:
  std::unique_ptr<Room> createRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammatesNames, std::string referee,
      unsigned int classroom) override;

  unsigned int getCountOfDuoTeamSlotsInRoom() override;
};


#endif //DEBATETABMAKER_AMERICANROOMFABRIC_HPP
