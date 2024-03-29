
#pragma once
#include <vector>

using namespace std;
class Cell
{
public:
    Cell(bool state, const vector<Cell*>& neighbors);
    Cell();
    bool GetState();
    void CalculateNextState();
    void UpdateState();

private:
    //true - alive, false - dead
    bool currState;
    //true - alive, false - dead
    bool nextState;
    vector<Cell*> neighbors;
    int GetLiveNeighborsCount();
};