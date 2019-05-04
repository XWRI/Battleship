//
// Created by mfbut on 3/10/2019.
//

#include "Attack.h"
#include <iostream>

BattleShip::Attack::Attack(BattleShip::Player &attacker, int row, int col)
:Move(attacker), row(row), col(col){}

void BattleShip::Attack::enact(BattleShip::Model &model, BattleShip::View &view, int i, int j) {

	Cell ship = model.getDefendingPlayer().getBoard().at(i, j);
	ship.firedAt = true;
	AttackResult attackResult = model.getDefendingPlayer().fireAt(i, j);

	std::cout << model.getAttackingPlayer().getName() << "'s Firing Board"<< std::endl << std::endl;
	view.showResultOfAttack(model.getDefendingPlayer(), attackResult);
	std::cout << model.getAttackingPlayer().getName() << "'s Placement Board"<< std::endl;
	view.showPlayersBoard(model.getAttackingPlayer());
	if(attackResult.hit == true) {
		if (attackResult.destroyed == true) {
		std::cout << model.getAttackingPlayer().getName() << " hit " << model.getDefendingPlayer().getName()
		          << "'s " << ship.getContents() << "!" << std::endl;
		std::cout << model.getAttackingPlayer().getName() << " destroyed " << model.getDefendingPlayer().getName()
		          << "'s " << ship.getContents() << "!" << std::endl;
	    }
		else{
			std::cout << model.getAttackingPlayer().getName() << " hit " << model.getDefendingPlayer().getName()
			          << "'s " << ship.getContents() << "!" << std::endl;
		}
	}
	else{
		std::cout << "Missed."<< std::endl;
	}

}

bool BattleShip::Attack::isValid() const {
	return (row <= moveMaker.getBoard().getNumRows() && col <= moveMaker.getBoard().getNumCols());
}

const int BattleShip::Attack::getCol() const {
	return col;
}

const int BattleShip::Attack::getRow() const {
	return row;
}


