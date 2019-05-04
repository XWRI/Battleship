//
// Created by mfbut on 3/11/2019.
//

#include <algorithm>
#include "HuntDestroyAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::View &view)
: RandomAI(gameAttributes, view), hasBeenHit(false){}

void BattleShip::HuntDestroyAI::getMove(Model& model, View& view) {
	std::unique_ptr<BattleShip::Attack> attack;

	if(!hasBeenHit) {
		if (priorityFiringQueue.size() == 0) {
		firingLocations.front().first = getRandInt(0, model.gameAttributes.getNumRows(), randomNumberGenerator);
		firingLocations.front().second = getRandInt(0, model.gameAttributes.getNumCols(), randomNumberGenerator);
		attack->enact(model, view, firingLocations.front().first, firingLocations.front().second);
		AttackResult attackResult = model.getAttackingPlayer().fireAt(firingLocations.front().first,
		                                                              firingLocations.front().second);
		    if (attackResult.hit) {
			    hasBeenHit = true;
			    priorityFiringQueue.insert(priorityFiringQueue.end(),
			                               getSurroundingLocations(firingLocations.front(), model).begin(),
			                               getSurroundingLocations(firingLocations.front(), model).end());
		    }
		    else{
			    hasBeenHit = false;
		    }
	    }
		else{
			attack->enact(model, view, priorityFiringQueue.front().first, priorityFiringQueue.front().second);
			priorityFiringQueue.erase(priorityFiringQueue.begin());
			AttackResult attackResult = model.getAttackingPlayer().fireAt(priorityFiringQueue.front().first,
			                                                              priorityFiringQueue.front().second);
			if(attackResult.hit){
				hasBeenHit = true;
				priorityFiringQueue.insert(priorityFiringQueue.end(),
				                           getSurroundingLocations(priorityFiringQueue.front(), model).begin(),
				                           getSurroundingLocations(priorityFiringQueue.front(), model).end());
			}
			else{
				hasBeenHit = false;
			}
		}
	}
	else {

		attack->enact(model, view, priorityFiringQueue.front().first, priorityFiringQueue.front().second);
		priorityFiringQueue.erase(priorityFiringQueue.begin());
		AttackResult attackResult = model.getAttackingPlayer().fireAt(priorityFiringQueue.front().first,
		                                                              priorityFiringQueue.front().second);
		if(attackResult.hit){
			hasBeenHit = true;
			priorityFiringQueue.insert(priorityFiringQueue.end(),
			                           getSurroundingLocations(priorityFiringQueue.front(), model).begin(),
			                           getSurroundingLocations(priorityFiringQueue.front(), model).end());
		}
		else{
			hasBeenHit = false;
		}
	}


}



std::vector<std::pair<int, int>> BattleShip::HuntDestroyAI::getSurroundingLocations(
	const std::pair<int, int> &center, Model& model) const {
	std::vector<std::pair<int, int>> firingQueue;
	if(!(model.getDefendingPlayer().getBoard().at(center.first, center.second - 1).HasBeenFiredAt() &&
	     model.getDefendingPlayer().getBoard().inBounds(center.first, center.second - 1))) {
		firingQueue.push_back({center.first, center.second - 1});
	}
	if(!(model.getDefendingPlayer().getBoard().at(center.first - 1, center.second).HasBeenFiredAt() &&
	      model.getDefendingPlayer().getBoard().inBounds(center.first - 1, center.second))){
		firingQueue.push_back({center.first - 1, center.second});
	}
	if(!(model.getDefendingPlayer().getBoard().at(center.first, center.second + 1).HasBeenFiredAt() &&
	     model.getDefendingPlayer().getBoard().inBounds(center.first, center.second + 1))){
		firingQueue.push_back({center.first, center.second + 1});
	}
	if(!(model.getDefendingPlayer().getBoard().at(center.first + 1, center.second).HasBeenFiredAt() &&
	     model.getDefendingPlayer().getBoard().inBounds(center.first + 1, center.second))){
		firingQueue.push_back({center.first + 1, center.second});
	}
	return firingQueue;
}
