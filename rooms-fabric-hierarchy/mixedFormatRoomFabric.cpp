#include "mixedFormatRoomFabric.hpp"

#include "../rooms-hierarchy/mixedFormatRoom.hpp"
#include "../tabMakerUtility.hpp"

std::unique_ptr<Room> MixedFormatRoomFabric::createRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammatesNames, std::string referee, unsigned int classroom) {
  return std::make_unique<MixedFormatRoom>(playersNames, teammatesNames, referee, classroom);
}

unsigned int MixedFormatRoomFabric::getCountOfDuoTeamSlotsInRoom() {
  return 1;
}
