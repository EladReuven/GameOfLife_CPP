// Game Of Life.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include "Board.h"
#include "Renderer.h"

using namespace std;

int main()
{
    Board board(10, 10);
    Renderer renderer('*', '-');
    board.StartGame(10);
    while (!board.EndGame()){
        board.Update();
        renderer.Print(board.GetCells());
    }
    return 0;
}