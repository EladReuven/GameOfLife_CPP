#pragma once
#include "Cell.h"
#include <vector>
#include <iostream>

using namespace std;

class Board
{
public:

    //width, height, rounds
    Board(int newWidth, int newHeight, int rounds);
    void Update();
    vector<vector<Cell>> GetCells();
    bool EndGame();

private:
    int width;
    int height;
    int roundsRemaining;
    vector<vector<Cell>> cells;
};