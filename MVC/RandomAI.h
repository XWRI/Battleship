//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H
#include <vector>
#include <algorithm>
#include "AiPlayer.h"

namespace BattleShip {
class RandomAI  : public AiPlayer{
 public:
  RandomAI(const GameAttributes& gameAttributes, View& view);
  virtual void getMove(Model& model, View& view);
 protected:
  std::vector<std::pair<int, int>> firingLocations;
};
}

#endif //BATTLESHIP_RANDOMAI_H

//THE RANDOM GENERATOR RETURNS AN ITERATOR, DEREFERENCE THE ITERATOR TO GET THE VALUE OF THE PAIR AND USE VECTOR. ERASE TO RE MOVE THAT COORDINATE FORM THE LIST