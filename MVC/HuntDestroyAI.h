//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_HUNTDESTROYAI_H
#define BATTLESHIP_HUNTDESTROYAI_H
#include <vector>
#include <algorithm>
#include "RandomAI.h"
namespace BattleShip {
class HuntDestroyAI : public RandomAI{
 public:
  HuntDestroyAI(const GameAttributes& gameAttributes, View& view);
  virtual void getMove(Model& model, View& view) override;

 protected:

//ARGUMENT THE CENTER LOCATION OF THE HIT AND RETURN FOUR SURROUNDING POINTS ？
  std::vector<std::pair<int, int>> getSurroundingLocations(const std::pair<int, int>& center, Model& model) const;

//THE SEQUENCE AFTER YOU HIT ONE SPOT
  std::vector<std::pair<int,int>> priorityFiringQueue;
  bool hasBeenHit;

};
}
//INHERIT FROM RAN_AI, USE THE FUNCTION FROM THE RANDOMAI

#endif //BATTLESHIP_HUNTDESTROYAI_H
