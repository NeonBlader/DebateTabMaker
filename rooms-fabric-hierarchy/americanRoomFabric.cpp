#include "americanRoomFabric.hpp"

#include <stdexcept>

#include "../rooms-hierarchy/americanRoom.hpp"
#include "../tabMakerUtility.hpp"

std::unique_ptr<Room> AmericanRoomFabric::createRoom(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammatesNames, std::string referee, unsigned int classroom) {
  return std::make_unique<AmericanRoom>(playersNames, teammatesNames, referee, classroom);
}

unsigned int AmericanRoomFabric::getCountOfDuoTeamSlotsInRoom() {
  return 2;
}
