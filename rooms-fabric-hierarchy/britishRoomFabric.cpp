#include "britishRoomFabric.hpp"

#include "../rooms-hierarchy/britishRoom.hpp"
#include "../tabMakerUtility.hpp"

std::unique_ptr<Room> BritishRoomFabric::createRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammatesNames, std::string referee, unsigned int classroom) {
  return std::make_unique<BritishRoom>(playersNames, teammatesNames, referee, classroom);
}

unsigned int BritishRoomFabric::getCountOfDuoTeamSlotsInRoom() {
  return 4;
}
