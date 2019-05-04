#include "MVC/Controller.h"
#include "MVC/GameAttributes.h"
#include "MVC/Board.h"
#include "MVC/HumanPlayer.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int main(int argc, char** argv) {
  BattleShip::Controller controller;

  if(argc == 1){
    controller.setupGame();
  }
  else if(argc == 2){
    controller.setupGame(argv[1]);
  }
  else if(argc == 3){
    controller.setupGame(argv[1],(int)(size_t)argv[2]);
  }

  controller.playGame();

  std::cout << controller.model.getWinner().getName();



  controller.model.players.clear();


  return 0;
}

//FSTREAM TO READ FILES