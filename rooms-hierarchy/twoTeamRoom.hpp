#ifndef DEBATETABMAKER_TWOTEAMROOM_HPP
#define DEBATETABMAKER_TWOTEAMROOM_HPP

#include <OpenXLSX.hpp>

#include "room.hpp"
#include "../tabMakerUtility.hpp"

class TwoTeamRoom: public Room {
public:
  CellPosition printToExcel(std::string outputExcelFilePath, CellPosition startCellPosition) const override;

  unsigned int getCountOfTeamsInRoom() const override;

protected:
  TwoTeamRoom(std::string referee, unsigned int classroom);
};

#endif //DEBATETABMAKER_TWOTEAMROOM_HPP
