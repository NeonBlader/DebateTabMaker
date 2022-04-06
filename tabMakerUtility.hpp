#ifndef DEBATETABMAKER_TABMAKERUTILITY_HPP
#define DEBATETABMAKER_TABMAKERUTILITY_HPP

#include <string>
#include <vector>
#include <memory>
#include <random>
#include <stdexcept>

#include <OpenXLSX.hpp>

class Room;
class Team;
class RoomFabric;

using CellPosition = std::pair<unsigned int, unsigned int>;

constexpr uint8_t MINIMAL_PLAYERS_COUNT = 4;
constexpr uint8_t BRITISH_ROOM_PLAYERS_COUNT = 8;
constexpr uint8_t BRITISH_ROOM_WITH_IRON_PLAYERS_COUNT = 7;
constexpr uint8_t AMERICAN_ROOM_PLAYERS_COUNT = 4;
constexpr uint8_t SCHOOL_ROOM_PLAYERS_COUNT = 6;
constexpr uint8_t MIXED_FORMAT_ROOM_PLAYERS_COUNT = 5;
constexpr uint8_t BRITISH_ROOM_TEAMS_COUNT = 4;

constexpr uint8_t COUNT_OF_ROOMS_PRINTED_IN_LINE = 2;

const std::string REFEREE_DESIGNATION = "Судья";
const std::string PLAYER_DESIGNATION = "Игрок";
const std::string IN_TEAM_DESIGNATION = "Да";
const std::string NOT_IN_TEAM_DESIGNATION = "Нет";

enum class TeamPosition: uint8_t {
  PROP = 0,
  OP,
  PROP1,
  OP1,
  PROP2,
  OP2
};

enum class TeamType: uint8_t {
  IRON_MAN = 1,
  DUO,
  TRIPLE
};

const std::vector<std::string> positionStrings = {{"Proposition"}, {"Opposition"},
                                                  {"First Proposition"}, {"First Opposition"},
                                                  {"Second Proposition"}, {"Second Opposition"}};

void assignPlayersToTeams(std::vector<std::string> &playersNames, std::vector<Team> &teams);
std::vector<std::string> getNamesFromXLSX(const std::string &filePath, unsigned int startRow = 2,
    unsigned int startColumn = 2);
void parseNamesFromXLSX(const std::string &filePath, std::vector<std::string> &parsedPlayersNames,
    std::vector<std::pair<std::string, std::string>> &parsedTeammatesNames, std::vector<std::string> &parsedRefereeNames,
    unsigned int startRow = 2, unsigned int startColumn = 2);
std::vector<std::unique_ptr<RoomFabric>> createRoomFabrics(std::size_t playersCount);
std::vector<std::unique_ptr<Room>> createRooms(std::vector<std::string> playersNames,
    std::vector<std::pair<std::string, std::string>> teammatesNames, std::vector<std::string> referees = {},
    std::vector<unsigned int> classrooms = {});
CellPosition printRoomsToExcel(const std::string &filePath, const std::vector<std::unique_ptr<Room>> &rooms,
    CellPosition startCellPosition = {1, 1});
void createTab(const std::string &namesFilePath, const std::string &outputFilePath,
    const std::vector<unsigned int> &classrooms = {});

template<typename T>
T getRandomElementWithErase(std::vector<T> &elements)
{
  if (elements.empty()) {
    throw std::invalid_argument("Can't get random element from empty vector!");
  }
  std::random_device rd;
  std::mt19937 mt(rd());
  std::size_t randomizedIndex = mt() % elements.size();
  T randomElement = elements[randomizedIndex];
  auto iter = elements.begin();
  std::advance(iter, randomizedIndex);
  elements.erase(iter);
  return randomElement;
}

#endif //DEBATETABMAKER_TABMAKERUTILITY_HPP
