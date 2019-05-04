//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <iostream>
#include <sstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "Model.h"
#include "Move.h"
#include "Attack.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"


BattleShip::Controller::Controller()
:hasBeenSetUp(), model(), view(std::make_unique<StandardView>()){}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile, int seed) {

	model.loadGameConfigurationFromFile(GameConfigurationFile);

	auto playerConfiguration = PlayerConfiguration();

	for (int i = 0; i < playerConfiguration.numHumanPlayers; ++i) {
		model.addPlayer<HumanPlayer>(*view);
	}
	for (int j = 0; j < playerConfiguration.numAiPlayers; ++j) {
		int aiChoice = view->getAiChoice();
		if(aiChoice == 1){
			model.addPlayer<CheatingAI>(*view);
			//???i am not sure

			BattleShip::AiPlayer::seed_random_number_generator(seed);
		}
		else if(aiChoice == 2){
			model.addPlayer<RandomAI>(*view);
			BattleShip::AiPlayer::seed_random_number_generator(seed);
		}
		else if(aiChoice == 3){
			model.addPlayer<HuntDestroyAI>(*view);
			BattleShip::AiPlayer::seed_random_number_generator(seed);
		}
	}
    hasBeenSetUp = true;
}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile) {
	model.loadGameConfigurationFromFile(GameConfigurationFile);
	auto playerConfiguration = PlayerConfiguration();
	for (int i = 0; i < playerConfiguration.numHumanPlayers; ++i) {
		model.addPlayer<HumanPlayer>(*view);
	}
	for (int j = 0; j < playerConfiguration.numAiPlayers; ++j) {
		int aiChoice = view->getAiChoice();
		if(aiChoice == 1){
			model.addPlayer<CheatingAI>(*view);
		}
		else if(aiChoice == 2){
			model.addPlayer<RandomAI>(*view);
		}
		else if(aiChoice == 3){
			model.addPlayer<HuntDestroyAI>(*view);
		}
	}
	hasBeenSetUp = true;
}

void BattleShip::Controller::setupGame() {
	//default
	std::string defaultConfigFilePath = "../GameConfigurations/DefaultConfiguration.txt";
    model.loadGameConfigurationFromFile(defaultConfigFilePath);
	auto playerConfiguration = PlayerConfiguration();
	for (int i = 0; i < playerConfiguration.numHumanPlayers; ++i) {
		model.addPlayer<HumanPlayer>(*view);
	}
	for (int j = 0; j < playerConfiguration.numAiPlayers; ++j) {
		int aiChoice = view->getAiChoice();
		if(aiChoice == 1){
			model.addPlayer<CheatingAI>(*view);
		}
		else if(aiChoice == 2){
			model.addPlayer<RandomAI>(*view);
		}
		else if(aiChoice == 3){
			model.addPlayer<HuntDestroyAI>(*view);
		}
	}
	hasBeenSetUp = true;
}

void BattleShip::Controller::playGame() {

	do{

		model.getAttackingPlayer().getMove(model, *view);

		model.changeTurn();

	}while(!model.isGameOver());

	std::cout << model.getWinner().getName() << " won the game!";
}
