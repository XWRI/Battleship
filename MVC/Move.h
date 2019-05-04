//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_MOVE_H
#define BATTLESHIP_MOVE_H
#include "Player.h"
#include "Model.h"
#include "View.h"

namespace BattleShip {
class Player;
class AiPlayer;
class HumanPlayer;
class Model;
class View;

class Move {
 public:
  Move(Player& moveMaker);
  virtual void enact(Model& model, View& view, int i, int j) = 0;
  virtual bool isValid() const = 0;
  virtual ~Move() = default;


  Player& moveMaker;
};
}

#endif //BATTLESHIP_MOVE_H
