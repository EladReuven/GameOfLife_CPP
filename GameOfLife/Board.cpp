#include "Board.h"
#include "random"
#include <vector>
#include <list>

using namespace std;


Board::Board(int newWidth, int newHeight)
{
	gameStarted = false;
	height = newHeight;
	width = newWidth;
	
	//totally not copied random generation stuff
	random_device rd;
	mt19937 gen(rd());

	// Define a uniform distribution for true or false (0 or 1)
	uniform_int_distribution<int> distribution(0, 1);


	//2D vector matrix in the size of height, width
	vector<vector<Cell>> newMatrix(height, vector<Cell>(width));

	for (int i = 0; i < newMatrix.size(); i++) {
		for (int j = 0; j < newMatrix[i].size(); j++) {
			
			vector<Cell*> newNeighbors;

			// get cell at: 
			// -x-y, x-y, +x-y
			// -xy, skip xy, +xy
			//-x+y, x+y, +x+y
			for (int y = -1; y <= 1; ++y) {
				for (int x = -1; x <= 1; ++x) {
					int row = i + y;
					int col = j + x;

					if (row >= 0 && row < height && col >= 0 && col < width && !(y == 0 && x == 0)) {
						//problem child
						newNeighbors.push_back(&newMatrix[row][col]);
					}
				}
			}
			bool randomBoolean = distribution(gen);
			newMatrix[i][j] = Cell(randomBoolean, newNeighbors);
		}
	}
	cells = newMatrix;
}

void Board::Update()
{
	cout << round << endl;
	round--;

	//every cell calculate the next state
	for (int i = 0; i < cells.size(); i++) {
		for (int j = 0; j < cells[i].size(); j++) {
			cells[i][j].CalculateNextState();
		}
	}
	//every cell update state
	for (int i = 0; i < cells.size(); i++) {
		for (int j = 0; j < cells[i].size(); j++) {
			cells[i][j].UpdateState();
		}
	}
}

vector<vector<Cell>> Board::GetCells()
{
	return cells;
}

void Board::StartGame(int rounds)
{
	gameStarted = true;
	round = rounds;
}

bool Board::EndGame()
{
	return round <= 0;
}
