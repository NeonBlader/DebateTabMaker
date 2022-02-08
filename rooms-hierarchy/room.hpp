#ifndef DEBATETABMAKER_ROOM_HPP
#define DEBATETABMAKER_ROOM_HPP

#include <string>
#include <vector>

#include "../team.hpp"

class Room {
public:
  std::vector<Team> getTeams() const;
  std::string getReferee() const;
  unsigned int getClassroom() const;

protected:
  Room(std::string referee, unsigned int classroom);

  std::vector<Team> teams_;
  std::string referee_;
  unsigned int classroom_;
};

std::ostream &operator<<(std::ostream &out, const Room &room);

#endif //DEBATETABMAKER_ROOM_HPP
