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

std::ostream &operator<<(std::ostream &out, const Room &room)
{
  out << "Classroom: " << room.getClassroom() << '\n';
  out << "Referee: " << room.getReferee() << "\n \n";
  for (std::vector<Team> teams = room.getTeams(); auto &team : teams) {
    out << team << '\n';
  }
  return out;
}