#ifndef DEBATETABMAKER_BRITISHWITHIRONROOMFABRIC_HPP
#define DEBATETABMAKER_BRITISHWITHIRONROOMFABRIC_HPP

#include <vector>
#include <string>
#include <memory>

#include "roomFabric.hpp"
#include "../rooms-hierarchy/room.hpp"

class BritishRoomWithIronFabric: public RoomFabric {
public:
  std::unique_ptr<Room> createRoom(std::vector<std::string> &playersNames,
     std::vector<std::pair<std::string, std::string>> &teammatesNames, std::string referee,
     unsigned int classroom) override;

  unsigned int getCountOfDuoTeamSlotsInRoom() override;
};


#endif //DEBATETABMAKER_BRITISHWITHIRONROOMFABRIC_HPP
