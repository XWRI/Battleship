//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"
#include "Board.h"

int BattleShip::Player::num_instances = 0;

BattleShip::Player::Player(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
: id(num_instances), name(), shipHealths(gameAttributes.getShipAttributes()), view(view),
  board(gameAttributes.getNumRows(), gameAttributes.getNumCols()), opponent(){
	num_instances++;
}

const std::string& BattleShip::Player::getName() const{
	return name;
}

void BattleShip::Player::setName(const std::string &name) {
	this->name = name;
}

const BattleShip::Board& BattleShip::Player::getBoard() const {
	return board;
}

BattleShip::Board& BattleShip::Player::getBoard() {
	return board;
}

const int BattleShip::Player::getId() const {
	return id;
}



bool BattleShip::Player::allShipsSunk() const {
	bool shipSunk = true;
	for (int i = 0; i < board.getNumRows(); ++i) {
		for (int j = 0; j < board.getNumCols(); ++j) {
			 if(board.at(i,j).containsShip()){
				 shipSunk = false;
			 }
		}
	}
	return shipSunk;
}

BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col) {
	char target;
	target = board.at(row, col).getContents();

	if(board.at(row, col).getContents() == '*'){
		board.at(row, col).setContents('O');
	}
	else {
		board.at(row, col).setContents('X');
	}
	bool hasDestroyed = true;
	for (int i = 0; i < board.getNumRows(); ++i) {
		for (int j = 0; j < board.getNumCols(); ++j) {
			if(board.at(i,j).getContents() == target){
				hasDestroyed = false;
			}
		}
	}
	AttackResult result((hit(target)), hasDestroyed, board.at(row, col).getContents());
	return result;
}

bool BattleShip::Player::hit(char shipChar) {
    return (shipChar != '*' && shipChar != 'X' && shipChar != 'O');
}

BattleShip::Player& BattleShip::Player::getOpponent() {
	return *opponent;
}

const BattleShip::Player& BattleShip::Player::getOpponent() const {
	return *opponent;
}

void BattleShip::Player::setOpponent(BattleShip::Player &opponent) {
	this->opponent = &opponent;
}
