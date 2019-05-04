//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"
#include "View.h"
#include "GameAttributes.h"
namespace BattleShip {
class Move;

class HumanPlayer : public Player {
 public:
  HumanPlayer(const GameAttributes& gameAttributes, View& view);
  virtual void getMove(Model& model, View& view) override;
  virtual void placeShips() override;
  virtual void initializeName() override;
  virtual ~HumanPlayer() override;
 protected:
//	static int id;

};
}

#endif //BATTLESHIP_HUMANPLAYER_H
