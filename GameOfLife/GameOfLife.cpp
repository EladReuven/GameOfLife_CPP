// This file contains the 'main' function. Program execution begins and ends here.
#include "Board.h"
#include "Renderer.h"

using namespace std;

int main()
{
    Board board(10, 10, 3);
    Renderer renderer('O', '-');
    while (!board.EndGame()){
        renderer.Print(board.GetCells());
        board.Update();
    }
    return 0;
}