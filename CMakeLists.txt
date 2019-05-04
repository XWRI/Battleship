cmake_minimum_required(VERSION 3.13)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

include_directories(MVC, GameConfigurations)

add_executable(BattleShip
        GameConfigurations/3_3lenShips.txt
        GameConfigurations/DefaultConfiguration.txt
        GameConfigurations/SingleShip.txt
        MVC/AiPlayer.cpp
        MVC/AiPlayer.h
        MVC/Attack.cpp
        MVC/Attack.h
        MVC/AttackResult.cpp
        MVC/AttackResult.h
        MVC/Board.cpp
        MVC/Board.h
        MVC/Cell.cpp
        MVC/Cell.h
        MVC/CheatingAI.cpp
        MVC/CheatingAI.h
        MVC/CMakeLists.txt
        MVC/Controller.cpp
        MVC/Controller.h
        MVC/EndGame.cpp
        MVC/EndGame.h
        MVC/GameAttributes.cpp
        MVC/GameAttributes.h
        MVC/HumanPlayer.cpp
        MVC/HumanPlayer.h
        MVC/HuntDestroyAI.cpp
        MVC/HuntDestroyAI.h
        MVC/Model.cpp
        MVC/Model.h
        MVC/Move.cpp
        MVC/Move.h
        MVC/Player.cpp
        MVC/Player.h
        MVC/PlayerConfiguration.cpp
        MVC/PlayerConfiguration.h
        MVC/RandomAI.cpp
        MVC/RandomAI.h
        MVC/ShipPlacement.cpp
        MVC/ShipPlacement.h
        MVC/StandardView.cpp
        MVC/StandardView.h
        MVC/Utility.cpp
        MVC/Utility.h
        MVC/View.cpp
        MVC/View.h
        CMakeLists.txt
        main.cpp
        setup.sh)
