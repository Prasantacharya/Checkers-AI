#include "piece.h"

float evaluate(const std::pair<bool, Piece*>& board[][]){
	//+ values are more benifitial to white
	//- values are more benifitial to black
	float eval = 0;
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if(board[i][j].first && borad[i][j].second){
			//basic version:
				//starts off with total pieces missing = +- 1 for each respective side
				if(board[i][j].second.getColor() % 2 == 1) eval += 1;
				else eval -= 1;
				//then takes into account the total number of kings = +- 0.5 for each respective side
				if(board[i][j].second.isKing()) eval += .5;
				else eval -= .5;
			//More advanced: take into account the number of jumps possible in the position
			}
		}
	}
	return eval;
}

std::pair<int, int> miniMax(int depth, std::pair<bool, Piece*>** board){//recursive minimax algo
	//first generate a possible board
	//recurse until you have reached depth
	//evaluate the position
	//return and compare
	//
}
void print(std::pair<bool, Piece*> board[][]){
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			std::cout << "|";
			if(board[i][j].first && board[i][j].second){
				if(board[i][j]){
					std::cout << " B ";
				}else{
					std::cout << " W ";
				}
			}else{
				std::cout << "   ";
			}
		}
		std::cout << "|" << std::endl;
	}
}

void destroyBoard(std::pair<bool, Piece*> board[][]){
	//destructor for the board
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if(board[i][j].first && board[i][j].second){
				delete board[i][j].second;
				board[i][j].second = NULL;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	//bool is wheather a piece can be there, and the second is the piece
	std::pair<bool, Piece*> board[8][8];
	bool isBlack = false;
	Piece* temp = NULL;
	//sets up the board
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		 {
		 	if(i + j % 2 == 0)
		 	{//for if the board is white
		 		isBlack = false;
		 		temp = NULL;
		 	}else{
		 		isBlack = true;
		 		if(i < 3){//if the board is 
		 			*temp = new Piece(1, i, j);
		 		}else if(i > 4){
		 			*temp = new Piece(2, i, j);
		 		}else{
		 			temp = NULL;
		 		}
		 	}
		 	board[i][j] = std::make_pair(isBlack, temp);
		 } 
	}

	return 0;
}
