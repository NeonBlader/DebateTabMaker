#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "team.hpp"
#include "rooms-hierarchy/britishRoom.hpp"
#include "rooms-hierarchy/britishWithIronRoom.hpp"
#include "rooms-hierarchy/americanRoom.hpp"
#include "rooms-hierarchy/schoolRoom.hpp"
#include "rooms-hierarchy/mixedFormatRoom.hpp"
#include "tabMakerUtility.hpp"

#include "rooms-fabric-hierarchy/roomFabric.hpp"
#include "rooms-fabric-hierarchy/britishRoomFabric.hpp"
#include "rooms-fabric-hierarchy/britishWithIronRoomFabric.hpp"
#include "rooms-fabric-hierarchy/americanRoomFabric.hpp"
#include "rooms-fabric-hierarchy/schoolRoomFabric.hpp"
#include "rooms-fabric-hierarchy/mixedFormatRoomFabric.hpp"

#include <OpenXLSX.hpp>

int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cerr << "You can't run program without path to source XLSX file!";
    return 1;
  }
  try {
    if (argc > 2) {
      std::vector<unsigned int> classrooms;
      for (std::size_t i = 2; i < argc; ++i) {
        for (std::size_t j = 0; argv[i][j] != '\0'; j++) {
          if (!isdigit(argv[i][j])) {
            std::cerr << "Invalid classroom number";
            return 1;
          }
        }
        classrooms.push_back(std::stoi(argv[i]));
      }
      createTab(argv[1], "FormedTab.xlsx", classrooms);
    } else {
      createTab(argv[1], "FormedTab.xlsx");
    }
  } catch (const std::exception &exception) {
    std::cerr << exception.what();
    return 2;
  }
  return 0;
}
