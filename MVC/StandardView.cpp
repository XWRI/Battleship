//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include <iostream>
#include "Utility.h"

BattleShip::StandardView::StandardView()
: in(std::cin), out(std::cout){}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration() {
	auto thisGameConfiguration = PlayerConfiguration();
	return thisGameConfiguration;
}

std::string BattleShip::StandardView::getPlayerName(int i) {
	std::string playerName;
	std::cout << "Player " << i << " please enter your name: ";
	std::cin >> playerName;
	return playerName;
}

ShipPlacement BattleShip::StandardView::getShipPlacement(const BattleShip::Player &player, char shipChar, int shipLen) {
	ShipPlacement shipPlacement;
	char inputDirection;

	do{
		updateShipPlacementView(player);
	do{
		std::cout << player.getName() << ", do you want to place " << shipChar << " horizontally or vertically?" << std::endl;
		std::cout << "Enter h for horizontal or v for vertical" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> inputDirection;
	}while(inputDirection != 'h' && inputDirection != 'H' && inputDirection != 'v' && inputDirection != 'V');


		std::cout << player.getName() << ", enter the row and column you want to place " << shipChar
		          << ", which is " << shipLen << " long, at with a space in between row and col: ";
		std::cin >> shipPlacement.rowStart >> shipPlacement.colStart;
	}while(!player.getBoard().canPlaceShipAt(shipPlacement));

	if(inputDirection == 'h'|| inputDirection == 'H'){
		shipPlacement.rowEnd = shipPlacement.rowStart;
		shipPlacement.colEnd = shipPlacement.colStart + shipLen -1;
	}
	if(inputDirection == 'v' || inputDirection == 'V') {
		shipPlacement.rowEnd = shipPlacement.rowStart + shipLen - 1;
		shipPlacement.colEnd = shipPlacement.colStart;
	}
	return shipPlacement;
}

//print after placing ships in the beginning
void BattleShip::StandardView::updateShipPlacementView(const BattleShip::Player &player) {
	printBoardAsVisible(player.getBoard());
}

int BattleShip::StandardView::getAiChoice() {
	int AiChoice;
	std::cout << "What AI do you want?" << std::endl;
	std::cout << "1. Cheating AI" << std::endl;
	std::cout << "2. Random AI" << std::endl;
	std::cout << "3. Hunt Destroy AI" << std::endl;
	std::cout << "Your choice: ";
	std::cin >> AiChoice;
	return AiChoice;
}

std::pair<int, int> BattleShip::StandardView::getFiringCoordinate(const BattleShip::Player &attacker) {
	std::pair<int, int> fireCoordinate;
	std::cout << ", where would you like to fire?" << std::endl;
	std::cout << "Enter your attack coordinate in the form row col: ";
	std::cin >> fireCoordinate.first >> fireCoordinate.second;
	return fireCoordinate;
}

void BattleShip::StandardView::showWinner(const BattleShip::Player &winner) {

}

void BattleShip::StandardView::showResultOfAttack(const BattleShip::Player &defender,
                                                  const BattleShip::AttackResult &attackResult) {
        showPlacementBoard(defender);
}
//print player's own board
void BattleShip::StandardView::showPlayersBoard(const BattleShip::Player &player) {
	printBoardAsVisible(player.getBoard());
}
//print one's firing board
void BattleShip::StandardView::showPlacementBoard(const BattleShip::Player &player) {
	printBoardAsObscured(player.getBoard());
}

void BattleShip::StandardView::printBoard(const std::vector<std::string> &board) {

	for (auto i = 0; i < (int)board.size() + 1; ++i) {
		for (auto it = 0; it < (int)board.front().size() + 1; ++it) {
			if(i == 0 && it == 0){
				std::cout <<" ";
			}
			else if(i == 0 && it != 0){
				if(it != (int)board.front().size()) {
					std::cout <<" "<< it - 1;
				}
				else if(it == (int)board.front().size()){
					std::cout <<" "<< it - 1 << std::endl;
				}
			}
			else if(it == 0){
				std::cout << i - 1;
			}
			else if(it == (int)board.front().size()){
				std::cout <<" "<< board[i - 1][it - 1] << std::endl;
			}
			else {
				std::cout << " " << board[i - 1][it - 1];
			}
		}
	}
}

void BattleShip::StandardView::printBoardAsVisible(const BattleShip::Board &board) {
	std::vector<std::string> printVal = board.getVisibleVersion();
	printBoard(printVal);
}

void BattleShip::StandardView::printBoardAsObscured(const BattleShip::Board &board) {
	std::vector<std::string> printVal = board.getHiddenVersion();
	printBoard(printVal);
}

void BattleShip::StandardView::clearInput() {
	do{

		if(in.get() != '\n' ){
			if(in.get() != ' '){
				continue;
			}
			else {
				remove(" ");
			}
		}
		else{
			remove("\n");
		}
	}while(!EOF);

}
