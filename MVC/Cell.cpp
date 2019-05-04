//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker)
: contents(contents), firedAt(), hiddenMarker(hiddenMarker), hitMarker(hitMarker), missMarker(missMarker){}

BattleShip::Cell::Cell(char contents)
: contents(contents), firedAt(), hiddenMarker('*'), hitMarker('X'), missMarker('O'){}

char BattleShip::Cell::getContents() const {
	return contents;
}

void BattleShip::Cell::setContents(char contents) {
	this->contents = contents;
}

char BattleShip::Cell::getContentsIfHidden() const {
	if(containsShip()) {
		return hiddenMarker;
	}
	else{
		return contents;
	}
}

char BattleShip::Cell::getContentsIfVisible() const {
	return contents;
}

bool BattleShip::Cell::HasBeenFiredAt() const {
	return (firedAt == true);
}

void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt) {
	if(hasBeenFiredAt == true){
		contents = 'X';
	}
}
//not so sure yet
bool BattleShip::Cell::containsShip() const {
	return  (contents != '*' && contents != 'O'&& contents != 'X');
}
