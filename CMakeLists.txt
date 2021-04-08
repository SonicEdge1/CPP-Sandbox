cmake_minimum_required(VERSION 3.0)

project(sowhat)

# Match some important cpp-cal compiler options.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

message(status " g++ flags ${CMAKE_CXX_FLAGS}")

#Add all files into the project to be compiled.
set(SRCS
        # ${CMAKE_CURRENT_DIR}cardDriver.cpp
        ${CMAKE_CURRENT_DIR}card_game_war.cpp
        ${CMAKE_CURRENT_DIR}card.cpp
        ${CMAKE_CURRENT_DIR}card_deck.cpp
        ${CMAKE_CURRENT_DIR}card_hand.cpp
        ${CMAKE_CURRENT_DIR}card_player.cpp

        )

# Our target is an executable
add_executable(${PROJECT_NAME} ${SRCS})

target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
        ${CMAKE_CURRENT_DIR}
        )

# Link with the libcal and dependent libraries.
# SET(PROJ_LIBS
#         ${CPP-CAL_LIBRARY}
#         ${ACTIVEMQ-CPP_LIBRARY}
#         ${YAML-CPP_LIBRARY}
#         ${HBL_LIBRARY}
#         xerces-c
#         uuid
#         dl
#         )

# IF (ENABLE_LOGGER)
#     SET(PROJ_LIBS ${PROJ_LIBS} spdlog::spdlog)
# endif ()


target_link_libraries(${PROJECT_NAME})

# Install targets to runtime components.
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_CURRENT_DIR} ${CMAKE_INSTALL_PREFIX}/lib)