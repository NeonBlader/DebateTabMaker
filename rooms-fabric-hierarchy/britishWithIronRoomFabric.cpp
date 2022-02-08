#include "britishWithIronRoomFabric.hpp"

#include "../rooms-hierarchy/britishWithIronRoom.hpp"
#include "../tabMakerUtility.hpp"

std::unique_ptr<Room>
BritishRoomWithIronFabric::createRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammatesNames, std::string referee, unsigned int classroom) {
  return std::make_unique<BritishWithIronRoom>(playersNames, teammatesNames, referee, classroom);
}

unsigned int BritishRoomWithIronFabric::getCountOfDuoTeamSlotsInRoom() {
  return 3;
}
