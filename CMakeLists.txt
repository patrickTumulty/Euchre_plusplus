cmake_minimum_required(VERSION 2.8)

Project(Euchre)

# include (gtest.cmake)

# find_package(Threads)

set(CMAKE_CXX_STANDARD 14)

add_executable(euchre 
    src/main.cpp 
    src/carddeck.cpp 
    src/euchredeck.cpp
    src/euchre.cpp 
    src/player.cpp
    src/cardprinter.cpp
    )

# add_executable(euchre-tests 
#     test/test.cpp 
#     src/carddeck.cpp
#     src/euchredeck.cpp
#     src/euchre.cpp 
#     src/player.cpp
#     )

# target_link_libraries(euchre-tests ${CMAKE_THREADS_LIBS_INIT} gtest)