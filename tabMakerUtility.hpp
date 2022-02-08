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

const unsigned int MINIMAL_PLAYERS_COUNT = 4;
const unsigned int BRITISH_ROOM_PLAYERS_COUNT = 8;
const unsigned int BRITISH_ROOM_WITH_IRON_PLAYERS_COUNT = 7;
const unsigned int AMERICAN_ROOM_PLAYERS_COUNT = 4;
const unsigned int SCHOOL_ROOM_PLAYERS_COUNT = 6;
const unsigned int MIXED_FORMAT_ROOM_PLAYERS_COUNT = 5;

const std::string REFEREE_DESIGNATION = "Судья";
const std::string PLAYER_DESIGNATION = "Игрок";
const std::string IN_TEAM_DESIGNATION = "Да";
const std::string NOT_IN_TEAM_DESIGNATION = "Нет";

enum TeamPosition {
  PROP,
  OP,
  PROP1,
  OP1,
  PROP2,
  OP2
};

enum TeamType {
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
