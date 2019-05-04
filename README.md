# Battleship
The implementation of the game in C++.

The game can be played in 3 different modes
1. Human vs Human
2. Human vs AI
3. AI vs AI

There are three AIs, CheatingAI, RandomAI, and HuntDestroyAI. 
The CheatingAI never misses a ship and the RandomAI guesses location at random. 
The HuntDestroyAI has two mode, Hunt mode and Destroy mode, where Hunt mode behaves like RandomAI and Destroy mode is activated once a ship has been hit and it fires around the location of that ship.
