cmake_minimum_required(VERSION 3.21)
project(DebateTabMaker)

set(CMAKE_CXX_STANDARD 20)


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

add_subdirectory(OpenXLSX)

add_executable(DebateTabMaker main.cpp team.hpp team.cpp rooms-hierarchy/room.hpp rooms-hierarchy/britishRoom.cpp rooms-hierarchy/britishRoom.hpp rooms-hierarchy/room.cpp tabMakerUtility.hpp tabMakerUtility.cpp rooms-hierarchy/britishWithIronRoom.cpp rooms-hierarchy/britishWithIronRoom.hpp rooms-hierarchy/americanRoom.cpp rooms-hierarchy/americanRoom.hpp rooms-hierarchy/schoolRoom.cpp rooms-hierarchy/schoolRoom.hpp rooms-hierarchy/mixedFormatRoom.cpp rooms-hierarchy/mixedFormatRoom.hpp rooms-fabric-hierarchy/roomFabric.hpp rooms-fabric-hierarchy/americanRoomFabric.cpp rooms-fabric-hierarchy/americanRoomFabric.hpp rooms-fabric-hierarchy/britishRoomFabric.cpp rooms-fabric-hierarchy/britishRoomFabric.hpp rooms-fabric-hierarchy/britishWithIronRoomFabric.cpp rooms-fabric-hierarchy/britishWithIronRoomFabric.hpp rooms-fabric-hierarchy/mixedFormatRoomFabric.cpp rooms-fabric-hierarchy/mixedFormatRoomFabric.hpp rooms-fabric-hierarchy/schoolRoomFabric.cpp rooms-fabric-hierarchy/schoolRoomFabric.hpp rooms-hierarchy/twoTeamRoom.hpp rooms-hierarchy/twoTeamRoom.cpp rooms-hierarchy/fourTeamRoom.cpp rooms-hierarchy/fourTeamRoom.hpp)

target_link_libraries(DebateTabMaker OpenXLSX::OpenXLSX)