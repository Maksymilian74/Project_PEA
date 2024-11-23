cmake_minimum_required(VERSION 3.27)
project(Projekt_PEA_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projekt_PEA_2
        Algorithms/Algorithms.cpp
        Algorithms/Algorithms.h
        Main/Menu.cpp
        Main/Menu.h
        Main/Main.cpp
        Structures/Matrix.cpp
        Structures/Matrix.h
        Utils/ReadFile.cpp
        Utils/ReadFile.h
        Utils/GenerateMatrix.cpp
        Utils/GenerateMatrix.h
        Structures/Node.cpp
        Structures/Node.h
        Structures/Stack.cpp
        Structures/Stack.h
        Structures/Queue.cpp
        Structures/Queue.h
        Structures/PriorityQueue.cpp
        Structures/PriorityQueue.h
        Structures/SymmetricMatrix.cpp
        Structures/SymmetricMatrix.h)

set(CMAKE_EXE_LINKER_FLAGS "-static")
