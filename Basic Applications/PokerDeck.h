#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

class Pokerdeck{

public:
	//default constructor, initialize deck of cards stored as vector of string names
	Pokerdeck(){
		//hearts = H, diamonds = D, clubs = C, spades = S
		//each suite has 1 - 13
		deckOfCards = { "H01", "H02", "H03", "H04", "H05", "H06", "H07", "H08", "H09", "H10", "H11", "H12", "H13",
			"D01", "D02", "D03", "D04", "D05", "D06", "D07", "D08", "D09", "D10", "D11", "D12", "D13",
			"C01", "C02", "C03", "C04", "C05", "C06", "C07", "C08", "C09", "C10", "C11", "C12", "C13",
			"S01", "S02", "S03", "S04", "S05", "S06", "S07", "S08", "S09", "S10", "S11", "S12", "S13" };
	}

	~Pokerdeck(){

	}

	void resetDeckToNew(){
		deckOfCards = { "H01", "H02", "H03", "H04", "H05", "H06", "H07", "H08", "H09", "H10", "H11", "H12", "H13",
			"D01", "D02", "D03", "D04", "D05", "D06", "D07", "D08", "D09", "D10", "D11", "D12", "D13",
			"C01", "C02", "C03", "C04", "C05", "C06", "C07", "C08", "C09", "C10", "C11", "C12", "C13",
			"S01", "S02", "S03", "S04", "S05", "S06", "S07", "S08", "S09", "S10", "S11", "S12", "S13" };
	}

	void shuffleDeck(){
		for (unsigned int i = 1; i < deckOfCards.size(); i++){
			int randomNumber = rand() % i;
			std::swap(deckOfCards[randomNumber], deckOfCards[i]);
		}
	}

	std::string topCard(){
		return deckOfCards.back();
	}

	std::string botCard(){
		return deckOfCards.front();
	}

	std::string drawTopCard(){
		std::string temp = deckOfCards.back();
		deckOfCards.pop_back();
		return temp;
	}

	int currentDeckSize(){
		return deckOfCards.size();
	}

	void placeCardOnTop(std::string cardToBePlaced){
		deckOfCards.emplace_back(cardToBePlaced);
	}

	void printDeckList(){
		for (unsigned int i = 0; i < deckOfCards.size(); i++){
			std::cout << deckOfCards[i] << " ";
			if (((i+1) % 13) == 0)
			{
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}


private:
	std::vector<std::string> deckOfCards;
};

//Helper Functions
int valOfCard(std::string cardName){
	std::string numString = cardName.substr(1, 3);
	int value = atoi(numString.c_str());
	//std::cout << value << std::endl; 
	if (value > 10){
		value = 10;
	}
	return value;
}

int findBestHand(int numOfPlayers){
	Pokerdeck myPokerDeck = Pokerdeck();
	myPokerDeck.shuffleDeck();

	myPokerDeck.printDeckList();

	//myPokerDeck.drawTopCard();

	std::vector<int> playerScores;
	int tempPlayerScore = 0;
	int highestScore = 0;
	int highScorePlayerNumber = 0;
	//for each player
	for (int i = 0; i < numOfPlayers; i++){

		//calculate the value of his hand
		tempPlayerScore = 0;
		for (int j = 0; j < 5; j++){
			std::string temp = myPokerDeck.drawTopCard();
			//std::cout << "Player " << i << " drew a  " << valOfCard(temp) << std::endl;
			tempPlayerScore += valOfCard(temp);
		}

		//add that value to a playerScores vector
		playerScores.emplace_back(tempPlayerScore);
		std::cout << "Player " << i << " Scored " << tempPlayerScore << std::endl;

		//check to see if it is the highest score
		if (highestScore < tempPlayerScore){
			highestScore = tempPlayerScore;
			highScorePlayerNumber = i;
		}

	}

	std::cout << "The Highest score was " << highestScore << " scored by " << highScorePlayerNumber << std::endl;

	return highestScore;
}