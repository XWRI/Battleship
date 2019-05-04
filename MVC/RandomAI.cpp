//
// Created by mfbut on 3/11/2019.
//

#include "RandomAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
: AiPlayer(gameAttributes, view){}

void BattleShip::RandomAI::getMove(Model& model, View& view) {
	//need to change to vector storing all the locations and then erase
	firingLocations.front().first = getRandInt(0, model.gameAttributes.getNumRows(), randomNumberGenerator);
	firingLocations.front().second = getRandInt(0, model.gameAttributes.getNumCols(), randomNumberGenerator);

	std::unique_ptr<BattleShip::Attack> attack;
	attack->enact(model, view, firingLocations.front().first, firingLocations.front().second);


}