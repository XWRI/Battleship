//
// Created by mfbut on 3/10/2019.
//
#include <string>
#include <vector>
#include <iostream>
#include "ShipPlacement.h"
#include "Cell.h"
#include "Board.h"

BattleShip::Board::Board(int numRows, int numCols, char blankChar)
:boardState(numRows, std::vector<Cell>(numCols, blankChar)),  blankChar(blankChar) {}

BattleShip::Board::Board(int numRows, int numCols)
:boardState(numRows, std::vector<Cell>(numCols, '*')), blankChar('*') {}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement &shipPlacement) const {
	return ((shipPlacement.rowStart < getNumRows() && shipPlacement.rowEnd <= getNumRows()) &&
		   (shipPlacement.colStart < getNumCols() && shipPlacement.colEnd <= getNumCols()));
}

int BattleShip::Board::getNumRows() const {
	int numRows = (int)boardState.size();
	return numRows;
}

int BattleShip::Board::getNumCols() const {
	int numCols = (int)boardState.front().size();
	return numCols;
}

std::vector<std::string> BattleShip::Board::getHiddenVersion() const {
	std::vector<std::string> hiddenBoard(getNumRows());
	for (int i = 0; i < getNumRows(); ++i) {
		for (int j = 0; j < getNumCols(); ++j) {
			hiddenBoard[i] += boardState[i][j].getContentsIfHidden();
		}
	}
	return hiddenBoard;
}

std::vector<std::string> BattleShip::Board::getVisibleVersion() const {
	std::vector<std::string> visibleBoard(getNumRows());
	for (int i = 0; i < getNumRows(); ++i) {
		for (int j = 0; j < getNumCols(); ++j) {
			visibleBoard[i] += boardState[i][j].getContentsIfVisible();
		}
	}
	return visibleBoard;
}

void BattleShip::Board::AddShip(char shipChar, const ShipPlacement &shipPlacement) {
	if(shipPlacement.rowStart == shipPlacement.rowEnd) {
		for (int i = shipPlacement.colStart; i < shipPlacement.colEnd + 1; ++i) {
			boardState[shipPlacement.rowStart][i].setContents(shipChar);
		}
	}
	else if(shipPlacement.colStart == shipPlacement.colEnd){
		for (int i = shipPlacement.rowStart; i < shipPlacement.rowEnd + 1; ++i) {
			boardState[i][shipPlacement.colStart].setContents(shipChar);
		}
	}
}

bool BattleShip::Board::inBounds(int row, int col) const {
	return (getNumRows() <= row && getNumCols() <= col);
}

BattleShip::Cell& BattleShip::Board::at(int i, int j) {
	return boardState[i][j];
}

const BattleShip::Cell& BattleShip::Board::at(int i, int j) const {
	return boardState[i][j];
}

bool BattleShip::Board::inBounds(const ShipPlacement &shipPlacement) const {
	return ((shipPlacement.rowStart < getNumRows() && shipPlacement.rowEnd <= getNumRows()) &&
	        (shipPlacement.colStart < getNumCols() && shipPlacement.colEnd <= getNumCols()));
}

bool BattleShip::Board::between(int value, int low, int high) const {
	return (value <= high && value >= low);
}

/*bool BattleShip::Board::spacesAreEmpty(const ShipPlacement &shipPlacement) const {
	if(shipPlacement.rowStart == shipPlacement.rowEnd) {
		for (int i = shipPlacement.colStart; i < shipPlacement.colEnd + 1; ++i) {
			return !(boardState[shipPlacement.rowStart][i].containsShip());
		}
	}
	else {
		for (int i = shipPlacement.rowStart; i < shipPlacement.rowEnd + 1; ++i) {
			return !(boardState[i][shipPlacement.colStart].containsShip());
		}
	}
}*/