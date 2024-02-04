// Game Of Life.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Board.h"
#include "Renderer.h"

using namespace std;

int main()
{
    Board board(10, 10, 3);
    Renderer renderer('*', '-');
    while (!board.EndGame()){
        renderer.Print(board.GetCells());
        board.Update();
    }
    return 0;
}