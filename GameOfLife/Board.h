#pragma once
#include "Cell.h"
#include <vector>
#include <iostream>

using namespace std;

class Board
{
public:

    Board(int newWidth, int newHeight);
    void Update();
    vector<vector<Cell>> GetCells(); //returns the matrix
    void StartGame(int rounds);
    bool EndGame();

private:
    int width;
    int height;
    int round;
    bool gameStarted;
    vector<vector<Cell>> cells;
};