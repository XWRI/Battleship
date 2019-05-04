//
// Created by mfbut on 3/9/2019.
//

#include <fstream>
#include <istream>
#include <algorithm>
#include "GameAttributes.h"
#include "Model.h"

BattleShip::Model::Model()
:gameAttributes(), playerTurn(0), forcedGameOver(){}

BattleShip::Player& BattleShip::Model::getAttackingPlayer() {
	return *players[playerTurn].get();
}

const BattleShip::Player& BattleShip::Model::getAttackingPlayer() const {
	return *players[playerTurn].get();
}

BattleShip::Player& BattleShip::Model::getDefendingPlayer() {
	if(playerTurn == 0) {
		return *players[playerTurn + 1].get();
	}
	else{
		return *players[playerTurn - 1].get();
	}
}

const BattleShip::Player& BattleShip::Model::getDefendingPlayer() const {
	if(playerTurn == 0) {
		return *players[playerTurn + 1].get();
	}
	else {
		return *players[playerTurn - 1].get();
	}
}

bool BattleShip::Model::isGameOver() const {
	return getDefendingPlayer().allShipsSunk();
}

void BattleShip::Model::changeTurn() {
    if(playerTurn == 1){
    	playerTurn = 0;
    }
    else {
    	playerTurn = 1;
    }
}

void BattleShip::Model::loadGameConfigurationFromFile(const std::string &gameConfigurationFile) {
	std::ifstream myFile;
	myFile.open(gameConfigurationFile);
	if(myFile.is_open()) {
		this->gameAttributes = GameAttributes(myFile);
	}
	else{
		throw std::logic_error("Failed to read as stream is no longer good.");
	}
	myFile.close();
}

void BattleShip::Model::endGame() {

}

std::unique_ptr<BattleShip::Move> BattleShip::Model::getNextMove() {
	std::unique_ptr<BattleShip::Move> shipMove;

	return shipMove;
}

BattleShip::Player& BattleShip::Model::getWinner() {
	if(players[0]->allShipsSunk()){
		return *players[1];
	}
	else{
		return *players[0];
	}
}

void BattleShip::Model::SetOpponents() {
    players.front()->setOpponent(*(players.back().get()));
}