cmake_minimum_required(VERSION 4.0)
project(laba6_2026)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba6_2026 main.cpp
        task1/utils.cpp
        task1/utils.h
        task1/exceptions.cpp
        task1/exceptions.h
        task2/Weapon.cpp
        task2/Weapon.h
        task2/BaseCharacter.cpp
        task2/BaseCharacter.h
        BaseEnemy.cpp
        BaseEnemy.h
        task2/MainHero.cpp
        task2/MainHero.h
        task2/exceptions.cpp
        task2/exceptions.h
)
