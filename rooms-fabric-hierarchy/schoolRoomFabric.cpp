#include "schoolRoomFabric.hpp"

#include "../rooms-hierarchy/schoolRoom.hpp"
#include "../tabMakerUtility.hpp"

std::unique_ptr<Room> SchoolRoomFabric::createRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammatesNames, std::string referee, unsigned int classroom) {
  return std::make_unique<SchoolRoom>(playersNames, teammatesNames, referee, classroom);
}

unsigned int SchoolRoomFabric::getCountOfDuoTeamSlotsInRoom() {
  return 0;
}
