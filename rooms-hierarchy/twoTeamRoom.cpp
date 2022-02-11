#include "twoTeamRoom.hpp"

CellPosition TwoTeamRoom::printToExcel(std::string outputExcelFilePath, CellPosition startCellPosition) const {
  OpenXLSX::XLDocument outputDoc;
  outputDoc.open(outputExcelFilePath);
  auto outputWKS = outputDoc.workbook().worksheet(*(outputDoc.workbook().worksheetNames().begin()));
  startCellPosition = printClassroomAndRefereeToExcel(outputWKS, startCellPosition);
  startCellPosition.first++;
  outputWKS.cell(startCellPosition.first, startCellPosition.second).value() = "ПР:";
  outputWKS.cell(startCellPosition.first++, startCellPosition.second + 2).value() = "ОП:";
  for (const auto &team: teams_) {
    unsigned int startRow = startCellPosition.first;
    for (auto playersNames = team.getPlayersNames(); const auto &name: playersNames) {
      outputWKS.cell(startCellPosition.first++, startCellPosition.second).value() = name;
    }
    startCellPosition.first = startRow;
    startCellPosition.second += 2;
  }
  outputDoc.save();
  return startCellPosition;
}

TwoTeamRoom::TwoTeamRoom(std::string referee, unsigned int classroom) : Room(std::move(referee), classroom)
{}

unsigned int TwoTeamRoom::getCountOfTeamsInRoom() const {
  return 2;
}
