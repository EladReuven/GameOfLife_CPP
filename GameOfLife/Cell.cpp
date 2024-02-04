#include "Cell.h"
using namespace std;

//###CONWAY GAME OF LIFE###
//1. Any live cell with fewer than two live neighbours dies, as if by underpopulation. v
//2. Any live cell with two or three live neighbours lives on to the next generation. v
//3. Any live cell with more than three live neighbours dies, as if by overpopulation. v
//4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


Cell::Cell(bool state, const vector<Cell*>& neighbors) : currState(state), neighbors(neighbors) {
	nextState = currState;
}

Cell::Cell() : currState(false), nextState(false)
{
}

bool Cell::GetState()
{
	return currState;
}

void Cell::CalculateNextState()
{
	int liveNeighbors = GetLiveNeighborsCount();

	//game of life logic
	if (currState) {

		//rule 1 and 3
		if (liveNeighbors < 2 || liveNeighbors > 3)
		{
			nextState = false;
		}

		//rule 2
		//else alive and 2 or 3 liveNeighbors, do nothing
	}
	else
	{
		//rule 4
		if (liveNeighbors == 3)
			nextState = true;
	}
}

void Cell::UpdateState()
{
	currState = nextState;
}

int Cell::GetLiveNeighborsCount()
{
	int liveNeighbors = 0;

	for (int i = 0; i < neighbors.size(); i++) {
		liveNeighbors += neighbors[i]->GetState() ? 1 : 0;
	}

	return liveNeighbors;
}
