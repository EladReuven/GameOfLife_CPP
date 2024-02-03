#include "Cell.h"
using namespace std;

//###CONWAY GAME OF LIFE###
//1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
//2. Any live cell with two or three live neighbours lives on to the next generation.
//3. Any live cell with more than three live neighbours dies, as if by overpopulation.
//4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


Cell::Cell(bool state, const vector<Cell*>& neighbors) : currState(state), nextState(state), neighbors(neighbors) {

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
    //game of life logic
}

void Cell::UpdateState()
{
    currState = nextState;
}