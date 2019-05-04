//
// Created by mfbut on 3/11/2019.
//
#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"

BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
:AiPlayer(gameAttributes, view){}


std::vector<std::pair<int, int>> BattleShip::CheatingAI::getFiringCoordinate(GameAttributes &gameAttributes) {
	std::vector<std::pair<int, int>> firingCoordinate;
	for (int i = 0; i < gameAttributes.getNumRows(); ++i) {
		for (int j = 0; j < gameAttributes.getNumCols(); ++j) {
//			if(model.getDefendingPlayer().getBoard().at(i, j).containsShip()) {
				firingCoordinate.insert(firingCoordinate.end(), std::pair<int, int>(i,j));
//			}
		}
	}
	return firingCoordinate;
}

void BattleShip::CheatingAI::getMove(Model& model, View& view) {
	std::unique_ptr<BattleShip::Attack> attack = std::make_unique<BattleShip::Attack>(*this, firingCoordinates.front().first, firingCoordinates.front().second);
    std::cout << "i love you in cheating get move";
	attack->enact(model, view, firingCoordinates.front().first, firingCoordinates.front().second);
	firingCoordinates.erase(firingCoordinates.begin());
}

BattleShip::CheatingAI::~CheatingAI() {
	delete this;
}