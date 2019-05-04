//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include <iostream>
#include <memory>
#include <sstream>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"
#include "StandardView.h"



BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
:Player(gameAttributes, view){

}

void BattleShip::HumanPlayer::placeShips() {
	for(const auto& ship : shipHealths) {
		BattleShip::StandardView standardView;
		ShipPlacement shipPlacement = standardView.getShipPlacement(*this, ship.first, ship.second);
		this->board.AddShip(ship.first, shipPlacement);
	}
	view.updateShipPlacementView(*this);
}

void BattleShip::HumanPlayer::initializeName() {
	std::stringstream name;
	BattleShip::StandardView standardView;
	name << standardView.getPlayerName(num_instances);
	setName(name.str());
}

void BattleShip::HumanPlayer::getMove(Model& model, View& view) {

	std::cout << model.getAttackingPlayer().getName() << "'s Firing Board"<< std::endl;
	view.showPlacementBoard(model.getDefendingPlayer());
	std::cout << std::endl << std::endl;
	std::cout << model.getAttackingPlayer().getName() << "'s Placement Board"<< std::endl;
	view.showPlayersBoard(model.getAttackingPlayer());

	std::pair<int, int> fireCoordinate;

	std::cout << model.getAttackingPlayer().getName();
	fireCoordinate= view.getFiringCoordinate(model.getAttackingPlayer());

	std::unique_ptr<BattleShip::Attack> attack = std::make_unique<BattleShip::Attack>(*this, fireCoordinate.first, fireCoordinate.second);
	attack->enact(model, view, fireCoordinate.first, fireCoordinate.second);
}

BattleShip::HumanPlayer::~HumanPlayer() {
	delete this;
}