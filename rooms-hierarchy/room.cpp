#include "room.hpp"

#include <iostream>

Room::Room(std::string referee, unsigned int classroom):
    referee_(std::move(referee)),
    classroom_(classroom)
{}

std::vector<Team> Room::getTeams() const {
  return teams_;
}

std::string Room::getReferee() const {
  return referee_;
}

unsigned int Room::getClassroom() const {
  return classroom_;
}

CellPosition Room::printClassroomAndRefereeToExcel(OpenXLSX::XLWorksheet &outputWKS,
    CellPosition startCellPosition) const {
  outputWKS.cell(startCellPosition.first, startCellPosition.second).value() = "Аудитория:";
  outputWKS.cell(startCellPosition.first, startCellPosition.second + 1).value() = classroom_;
  outputWKS.cell(startCellPosition.first + 1, startCellPosition.second).value() = "Судья: ";
  outputWKS.cell(startCellPosition.first + 1, startCellPosition.second + 1).value() = referee_;
  return {startCellPosition.first + 2, startCellPosition.second};
}

std::ostream &operator<<(std::ostream &out, const Room &room)
{
  out << "Classroom: " << room.getClassroom() << '\n';
  out << "Referee: " << room.getReferee() << "\n \n";
  for (std::vector<Team> teams = room.getTeams(); auto &team : teams) {
    out << team << '\n';
  }
  return out;
}