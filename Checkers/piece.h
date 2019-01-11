#ifndef _CHESS_H__
#define _CHESS_H__
#include <iostream>

class Piece{
public:
	//colors: 0 = white, 1 = black
	Piece(int color, int x, int y): posX(x), posY(y), color_(color), isKing(false) {}
	void findLegalMoves(const std::pair<bool, int>& board[][]);
	const std::vector<std::pair<int, int>> getLegalMoves(){return legalMoves;}
	bool move(int newX, int newY);
	int getColor(){return color_;}
	bool isKing(){return isKing;}
private:
	int hashFunction(const std::pair<int, int>& temp);//hashFunction for hashTable
	void resizeTable();//resizing function for hashTable
	void promote(); 
	int posX;
	int posY;
	int color_;
	bool isKing;
	std::vector<std::pair<int, int>> legalMoves;//hashTable of possible moves
	//the first number is x the second number is y
};
int Piece::hashFunciton(const std::pair<int, int>& temp){
	int index;
	//hashes based off the position of the piece and the color
	index += posX + posY;
	//collision handeling: just go over one spot in the table
	return index % legalMoves.size();
}
void Piece::findLegalMoves(const std::pair<bool, Piece*>& board[][]){
	legalMoves.clear();
	for (int i = -1; i <= 1; ++i)
	{
		if(i == 0) continue;
		for (int j = -1; j <= 1; ++j)
		{
			if(j == 0) continue;//makes sure only the diagonals are checked
			if(posX + i < 0 || posX + i > 7 || posY + j < 0 || posY + j > 7)
				continue;//checks for bounds
			if(board[posX + i][posY + j].first)//if it is a black square
			{
				if(board[posX + i][posY + j] == NULL){
					//no piece there, can definately go there
				}
				else if(){
					//if there is a piece there, check that its next is 
				}
				//check 
			}
		}
	}
}
void Piece::promote(){
	if(color_ != -1 && (posY == 0 && color_ == 0 || posY == 7 && color_ == 1)){
		isKing = true;
	}
}
bool Piece::move(int newX, int newY){
	std::pair<int, int> temp = std::make_pair(newX, newY);
	int index = hashFunction(temp);
	if(legalMoves[index] != temp){//check if that move was legal
		return false;
	}else{
		//if it was, then go the that spot
		posX = newX;
		posY = newY;
		//check for promotion
		promote();
	}
	return true;
}
#endif