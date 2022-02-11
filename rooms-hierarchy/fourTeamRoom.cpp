#include "fourTeamRoom.hpp"

#include <OpenXLSX.hpp>

CellPosition FourTeamRoom::printToExcel(std::string outputExcelFilePath, CellPosition startCell) const {
  OpenXLSX::XLDocument outputDoc;
  outputDoc.open(outputExcelFilePath);
  auto outputWKS = outputDoc.workbook().worksheet(*(outputDoc.workbook().worksheetNames().begin()));
  startCell = printClassroomAndRefereeToExcel(outputWKS, startCell);
  startCell.first++;
  for (std::size_t i = 0; i < BRITISH_ROOM_TEAMS_COUNT; ++i) {
    unsigned int oldRow = startCell.first;
    switch (i) {
      case 0:
        outputWKS.cell(startCell.first++, startCell.second).value() = "1ПР:";
        break;
      case 1:
        outputWKS.cell(startCell.first++, startCell.second).value() = "1ОП:";
        break;
      case 2:
        outputWKS.cell(startCell.first++, startCell.second).value() = "2ПР:";
        break;
      case 3:
        outputWKS.cell(startCell.first++, startCell.second).value() = "2ОП:";
        break;
    }
    for (auto names = teams_[i].getPlayersNames(); const auto &name: names) {
      outputWKS.cell(startCell.first++, startCell.second).value() = name;
    }
    switch (i) {
      case 0:
      case 2:
        startCell = {oldRow, startCell.second + 2};
        break;
      case 1:
        startCell = {startCell.first + 2, startCell.second - 2};
        break;
    }
  }
  outputDoc.save();
  return startCell;
}

FourTeamRoom::FourTeamRoom(std::string referee, unsigned int classroom) : Room(std::move(referee), classroom)
{}

unsigned int FourTeamRoom::getCountOfTeamsInRoom() const {
  return 4;
}
