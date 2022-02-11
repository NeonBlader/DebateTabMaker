#ifndef DEBATETABMAKER_ROOM_HPP
#define DEBATETABMAKER_ROOM_HPP

#include <string>
#include <vector>

#include "../team.hpp"
#include "../tabMakerUtility.hpp"

class Room {
public:
  virtual unsigned int getCountOfTeamsInRoom() const = 0;
  virtual CellPosition printToExcel(std::string outputExcelFilePath, CellPosition startCell) const = 0;

  std::vector<Team> getTeams() const;
  std::string getReferee() const;
  unsigned int getClassroom() const;

protected:
  Room(std::string referee, unsigned int classroom);

  CellPosition printClassroomAndRefereeToExcel(OpenXLSX::XLWorksheet &outputWKS, CellPosition startCell) const;

  std::vector<Team> teams_;
  std::string referee_;
  unsigned int classroom_;
};

std::ostream &operator<<(std::ostream &out, const Room &room);

#endif //DEBATETABMAKER_ROOM_HPP
