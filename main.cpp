#include <iostream>
#include <vector>
#include <string>

#include "tabMakerUtility.hpp"

int main(int argc, char *argv[])
{
  if (argc < 2) {
    std::cerr << "You can't run program without path to source XLSX file!";
    return 1;
  }
  try {
    if (argc > 2) {
      std::vector<unsigned int> classrooms;
      for (std::size_t i = 2; i < argc; ++i) {
        for (std::size_t j = 0; argv[i][j] != '\0'; j++) {
          if (!isdigit(argv[i][j])) {
            std::cerr << "Invalid classroom number";
            return 1;
          }
        }
        classrooms.push_back(std::stoi(argv[i]));
      }
      createTab(argv[1], "FormedTab.xlsx", classrooms);
    } else {
      createTab(argv[1], "FormedTab.xlsx");
    }
  } catch (const std::exception &exception) {
    std::cerr << exception.what();
    return 2;
  }
  return 0;
}
