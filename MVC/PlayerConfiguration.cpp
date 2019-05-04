//
// Created by mfbut on 3/9/2019.
//

#include <iostream>
#include "PlayerConfiguration.h"

BattleShip::PlayerConfiguration::PlayerConfiguration() {
	int yourChoice;
	do{
		std::cout << "What type of game do you want to play?" << std::endl;
		std::cout << "1. Human vs Human" << std::endl;
		std::cout << "2. Human vs AI" << std::endl;
		std::cout << "3. AI vs AI" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> yourChoice;
	}while(yourChoice !=1 && yourChoice != 2 && yourChoice != 3);

	if(yourChoice == 1){
		numHumanPlayers = 2;
		numAiPlayers = 0;
	}
	else if(yourChoice == 2){
		numHumanPlayers = 1;
		numAiPlayers = 1;
	}
	else if(yourChoice == 3){
		numHumanPlayers = 0;
		numAiPlayers = 2;
	}
}
