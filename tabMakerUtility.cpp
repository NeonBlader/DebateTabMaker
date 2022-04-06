#include "tabMakerUtility.hpp"

#include "team.hpp"
#include "rooms-fabric-hierarchy/roomFabric.hpp"
#include "rooms-fabric-hierarchy/britishRoomFabric.hpp"
#include "rooms-fabric-hierarchy/britishWithIronRoomFabric.hpp"
#include "rooms-fabric-hierarchy/americanRoomFabric.hpp"
#include "rooms-fabric-hierarchy/schoolRoomFabric.hpp"
#include "rooms-fabric-hierarchy/mixedFormatRoomFabric.hpp"
#include <fstream>

void assignPlayersToTeams(std::vector<std::string> &playersNames,
    std::vector<std::pair<std::string, std::string>> &teammates, std::vector<Team> &teams) {
  unsigned int playersCount = 0;
  for (auto &iter: teams) {
    playersCount += static_cast<uint8_t>(iter.getTeamType());
  }
  if (playersNames.size() + (teammates.size() * 2) < playersCount) {
    throw std::invalid_argument("Available players names count must be at least equal to count of places in teams");
  }
  if (RoomFabric::countOfDuoTeamSlots < teammates.size()) {
    throw std::logic_error("All teammates can't play with each other with current count of players");
  }
  for (auto &team: teams) {
    if (team.getTeamType() != TeamType::DUO) {
      for (auto &name: team.playersNames_) {
        name = getRandomElementWithErase(playersNames);
      }
    } else {
      if (RoomFabric::countOfDuoTeamSlots == teammates.size()) {
        auto randomTeammates = getRandomElementWithErase(teammates);
        team.playersNames_[0] = randomTeammates.first;
        team.playersNames_[1] = randomTeammates.second;
        RoomFabric::countOfDuoTeamSlots--;
      } else {
        std::random_device rd;
        std::mt19937 mt(rd());
        if (((mt() % 2) == 0) || (teammates.empty())) {
          for (auto &name: team.playersNames_) {
            name = getRandomElementWithErase(playersNames);
          }
          RoomFabric::countOfDuoTeamSlots--;
        } else {
          auto randomTeammates = getRandomElementWithErase(teammates);
          team.playersNames_[0] = randomTeammates.first;
          team.playersNames_[1] = randomTeammates.second;
          RoomFabric::countOfDuoTeamSlots--;
        }
      }
    }
  }
}

std::vector<std::string> getNamesFromXLSX(const std::string &filePath, unsigned int startRow, unsigned int startColumn)
{
  OpenXLSX::XLDocument namesDoc;
  namesDoc.open(filePath);
  auto namesWKS = namesDoc.workbook().worksheet(*namesDoc.workbook().worksheetNames().begin());
  std::vector<std::string> playersNames;
  while (!namesWKS.cell(startRow, startColumn).value().get<std::string>().empty()) {
    playersNames.push_back(namesWKS.cell(startRow, startColumn).value());
    startRow++;
  }
  return playersNames;
}

std::vector<std::unique_ptr<RoomFabric>> createRoomFabrics(std::size_t playersCount)
{
  if (playersCount < MINIMAL_PLAYERS_COUNT) {
    throw std::invalid_argument("Players count can't be less than 4");
  }
  std::vector<std::unique_ptr<RoomFabric>> roomFabrics;
  while (playersCount > 8) {
    if (playersCount - BRITISH_ROOM_PLAYERS_COUNT >= AMERICAN_ROOM_PLAYERS_COUNT) {
      roomFabrics.push_back(std::make_unique<BritishRoomFabric>());
      playersCount -= BRITISH_ROOM_PLAYERS_COUNT;
    } else if (playersCount - BRITISH_ROOM_PLAYERS_COUNT == AMERICAN_ROOM_PLAYERS_COUNT - 1) {
      roomFabrics.push_back(std::make_unique<BritishRoomWithIronFabric>());
      playersCount -= BRITISH_ROOM_WITH_IRON_PLAYERS_COUNT;
      roomFabrics.push_back(std::make_unique<AmericanRoomFabric>());
      playersCount -=AMERICAN_ROOM_PLAYERS_COUNT;
    } else if (playersCount - BRITISH_ROOM_PLAYERS_COUNT == AMERICAN_ROOM_PLAYERS_COUNT - 2) {
      roomFabrics.push_back(std::make_unique<AmericanRoomFabric>());
      playersCount -= AMERICAN_ROOM_PLAYERS_COUNT;
      roomFabrics.push_back(std::make_unique<SchoolRoomFabric>());
      playersCount -= SCHOOL_ROOM_PLAYERS_COUNT;
    } else if (playersCount - BRITISH_ROOM_PLAYERS_COUNT == AMERICAN_ROOM_PLAYERS_COUNT - 3) {
      roomFabrics.push_back(std::make_unique<AmericanRoomFabric>());
      playersCount -= AMERICAN_ROOM_PLAYERS_COUNT;
      roomFabrics.push_back(std::make_unique<MixedFormatRoomFabric>());
      playersCount -= MIXED_FORMAT_ROOM_PLAYERS_COUNT;
    }
  }
  switch (playersCount) {
    case BRITISH_ROOM_PLAYERS_COUNT:
      roomFabrics.push_back(std::make_unique<BritishRoomFabric>());
      break;
    case BRITISH_ROOM_WITH_IRON_PLAYERS_COUNT:
      roomFabrics.push_back(std::make_unique<BritishRoomWithIronFabric>());
      break;
    case AMERICAN_ROOM_PLAYERS_COUNT:
      roomFabrics.push_back(std::make_unique<AmericanRoomFabric>());
      break;
    case SCHOOL_ROOM_PLAYERS_COUNT:
      roomFabrics.push_back(std::make_unique<SchoolRoomFabric>());
      break;
    case MIXED_FORMAT_ROOM_PLAYERS_COUNT:
      roomFabrics.push_back(std::make_unique<MixedFormatRoomFabric>());
      break;
  }
  return roomFabrics;
}

std::vector<std::unique_ptr<Room>> createRooms(std::vector<std::string> playersNames,
    std::vector<std::pair<std::string, std::string>> teammatesNames, std::vector<std::string> referees,
    std::vector<unsigned int> classrooms)
{
  auto roomFabrics = createRoomFabrics(playersNames.size() + (teammatesNames.size() * 2));
  if (classrooms.empty()) {
    classrooms = std::vector<unsigned int>(roomFabrics.size());
  }
  if ((referees.size() < roomFabrics.size()) || (classrooms.size() < roomFabrics.size())) {
    throw std::invalid_argument("You don't have enough rooms or referees");
  }
  std::vector<std::unique_ptr<Room>> rooms;
  for (const auto &fabric: roomFabrics) {
    RoomFabric::countOfDuoTeamSlots += fabric->getCountOfDuoTeamSlotsInRoom();
  }
  for (const auto &fabric: roomFabrics) {
    rooms.push_back(fabric->createRoom(playersNames, teammatesNames, getRandomElementWithErase(referees),
        getRandomElementWithErase(classrooms)));
  }
  return rooms;
}

void parseNamesFromXLSX(const std::string &filePath, std::vector<std::string> &parsedPlayersNames,
    std::vector<std::pair<std::string, std::string>> &parsedTeammatesNames, std::vector<std::string> &parsedRefereeNames,
    unsigned int startRow, unsigned int startColumn)
{
  OpenXLSX::XLDocument namesDoc;
  namesDoc.open(filePath);
  auto namesWKS = namesDoc.workbook().worksheet(*(namesDoc.workbook().worksheetNames().begin()));
  while (!namesWKS.cell(startRow, startColumn).value().get<std::string>().empty()) {
    if (namesWKS.cell(startRow, startColumn).value() == REFEREE_DESIGNATION) {
      parsedRefereeNames.push_back(namesWKS.cell(startRow, startColumn + 2).value());
    } else if (namesWKS.cell(startRow, startColumn).value() == PLAYER_DESIGNATION) {
      if (namesWKS.cell(startRow, startColumn + 1).value() == NOT_IN_TEAM_DESIGNATION) {
        parsedPlayersNames.push_back(namesWKS.cell(startRow, startColumn + 5).value());
      } else if (namesWKS.cell(startRow, startColumn + 1).value() == IN_TEAM_DESIGNATION) {
        parsedTeammatesNames.emplace_back(namesWKS.cell(startRow, startColumn + 3).value(),
            namesWKS.cell(startRow, startColumn + 4).value());
      } else {
        throw std::invalid_argument("Wrong designation of the presence of a teammate");
      }
    } else {
      throw std::invalid_argument("Wrong designation of participant role");
    }
    startRow++;
  }
}

CellPosition printRoomsToExcel(const std::string &filePath, const std::vector<std::unique_ptr<Room>> &rooms,
    CellPosition startCellPosition)
{
  OpenXLSX::XLDocument doc;
  doc.create(filePath);
  doc.close();
  for (std::size_t i = 0; i < rooms.size(); ++i) {
    if (i == 0) {
      startCellPosition = rooms[i]->printToExcel(filePath, startCellPosition);
    } else if (i % COUNT_OF_ROOMS_PRINTED_IN_LINE != 0) {
      if (rooms[i - 1]->getCountOfTeamsInRoom() == 4) {
        startCellPosition.first -=11;
      } else {
        startCellPosition.first -= 4;
      }
      startCellPosition.second += 2;
      startCellPosition = rooms[i]->printToExcel(filePath, startCellPosition);
    } else {
      startCellPosition.first += 3;
      startCellPosition.second -= 6;
      startCellPosition = rooms[i]->printToExcel(filePath, startCellPosition);
    }
  }
  return startCellPosition;
}

void createTab(const std::string &namesFilePath, const std::string &outputFilePath,
    const std::vector<unsigned int> &classrooms)
{
  std::vector<std::string> playersNames;
  std::vector<std::pair<std::string, std::string>> teammatesNames;
  std::vector<std::string> refereeNames;
  parseNamesFromXLSX(namesFilePath, playersNames, teammatesNames, refereeNames);
  std::ifstream in("config.txt");
  std::string refereeMode;
  in >> refereeMode;
  if (refereeMode == "NO") {
    refereeNames.resize(100);
    std::for_each(refereeNames.begin(), refereeNames.end(), [](auto &current){current = "TBA";});
  }
  auto rooms = createRooms(playersNames, teammatesNames, refereeNames, classrooms);
  printRoomsToExcel(outputFilePath, rooms);
}