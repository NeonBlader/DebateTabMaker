#include "tabMakerUtility.hpp"

#include <stdexcept>
#include <random>

#include "team.hpp"

void assignPlayersToTeams(std::vector<std::string> playersNames, std::vector<Team> &teams) {
  unsigned int playersCount = 0;
  for (auto &iter: teams) {
    playersCount += iter.getTeamType();
  }
  if (playersCount != playersNames.size()) {
    throw std::invalid_argument("Players names count must be equal to count of places in teams");
  }

  std::random_device rd;
  std::mt19937 mt(rd());

  for (auto& outIter: teams) {
    for (auto& innerIter: outIter.playersNames_) {
      std::size_t randomizedIndex = mt() % playersNames.size();
      innerIter = playersNames[randomizedIndex];

      auto iter = playersNames.begin();
      std::advance(iter, randomizedIndex);
      playersNames.erase(iter);
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