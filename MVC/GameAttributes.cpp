//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include <map>
#include <istream>
#include <iterator>
#include "Utility.h"
#include "GameAttributes.h"

BattleShip::GameAttributes::GameAttributes()
: numRows(), numCols(){}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols)
:numRows(numRows), numCols(numCols) {}

BattleShip::GameAttributes::GameAttributes(std::istream &in) {
	int numOfShip;
	char first;
	int second;
	in >> numRows;
	in >> numCols;
	in >> numOfShip;
	for (int i = 0; i < numOfShip; ++i) {
		in >> first >> second;
		shipAttributes.insert(shipAttributes.begin(), std::pair<char, int>(first, second));
	}
}

int BattleShip::GameAttributes::getNumCols() const {
	return numCols;
}

void BattleShip::GameAttributes::setNumCols(int numCols) {
	this->numCols = numCols;
}

int BattleShip::GameAttributes::getNumRows() const {
	return numRows;
}

void BattleShip::GameAttributes::setNumRows(int numRows) {
	this->numRows = numRows;
}

int BattleShip::GameAttributes::getShipSize(const char ShipChar) const {

	int shipSize;
	for (auto itr = shipAttributes.begin(); itr != shipAttributes.end(); ++itr) {
        if(ShipChar == itr->first){
	        shipSize = itr->second;
        }
	}
	return shipSize;
}

const std::map<char, int>& BattleShip::GameAttributes::getShipAttributes() const {
	return shipAttributes;
}