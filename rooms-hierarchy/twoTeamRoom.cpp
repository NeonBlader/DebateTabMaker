#include "twoTeamRoom.hpp"

CellPosition TwoTeamRoom::printToExcel(std::string outputExcelFilePath, CellPosition startCellPosition) const {
  OpenXLSX::XLDocument outputDoc;
  outputDoc.open(outputExcelFilePath);
  auto outputWKS = outputDoc.workbook().worksheet(*(outputDoc.workbook().worksheetNames().begin()));
  startCellPosition = printClassroomAndRefereeToExcel(outputWKS, startCellPosition);
  startCellPosition.first++;
  outputWKS.cell(startCellPosition.first, startCellPosition.second).value() = "ПР:";
  outputWKS.cell(startCellPosition.first++, startCellPosition.second + 2).value() = "ОП:";
  for (auto i = 0; i < teams_.size(); ++i) {
    unsigned int startRow = startCellPosition.first;
    for (auto playersNames = teams_[i].getPlayersNames(); const auto &name: playersNames) {
      outputWKS.cell(startCellPosition.first++, startCellPosition.second).value() = name;
    }
    startCellPosition.first = startRow;
    if (i != 1) {
      startCellPosition.second += 2;
    }
  }
  outputDoc.save();
  return startCellPosition;
}

TwoTeamRoom::TwoTeamRoom(std::string referee, unsigned int classroom) : Room(std::move(referee), classroom)
{}

unsigned int TwoTeamRoom::getCountOfTeamsInRoom() const {
  return 2;
}
