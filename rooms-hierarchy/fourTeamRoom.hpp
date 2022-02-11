#ifndef DEBATETABMAKER_FOURTEAMROOM_HPP
#define DEBATETABMAKER_FOURTEAMROOM_HPP

#include "room.hpp"
#include "../tabMakerUtility.hpp"

class FourTeamRoom: public Room{
public:
  unsigned int getCountOfTeamsInRoom() const override;

  CellPosition printToExcel(std::string outputExcelFilePath, CellPosition startCell) const override;

protected:
  FourTeamRoom(std::string referee, unsigned int classroom);
};


#endif //DEBATETABMAKER_FOURTEAMROOM_HPP
