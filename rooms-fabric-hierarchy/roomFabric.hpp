#ifndef DEBATETABMAKER_ROOMFABRIC_HPP
#define DEBATETABMAKER_ROOMFABRIC_HPP

#include <vector>
#include <string>
#include <memory>

#include "../rooms-hierarchy/room.hpp"

class RoomFabric {
public:
  virtual std::unique_ptr<Room> createRoom(std::vector<std::string> &playersNames,
      std::vector<std::pair<std::string, std::string>> &teammatesNames, std::string referee, unsigned int classroom) = 0;
  virtual unsigned int getCountOfDuoTeamSlotsInRoom() = 0;

  inline static unsigned int countOfDuoTeamSlots = 0;
};


#endif //DEBATETABMAKER_ROOMFABRIC_HPP
