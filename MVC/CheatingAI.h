//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H
#include "AiPlayer.h"

namespace BattleShip {
class CheatingAI  : public AiPlayer{
 public:
  CheatingAI(const GameAttributes& gameAttributes, View& view);
  std::vector<std::pair<int, int>> getFiringCoordinate(BattleShip::GameAttributes &gameAttributes);
  virtual void getMove(Model& model, View& view) override;
  virtual ~CheatingAI() override;

	std::vector<std::pair<int, int>> firingCoordinates;

};
}

#endif //BATTLESHIP_CHEATINGAI_H
