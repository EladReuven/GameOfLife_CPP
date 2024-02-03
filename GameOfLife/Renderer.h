#pragma once
#include "Cell.h"
#include <vector>

using namespace std;
class Renderer
{
public:
	Renderer(char alive, char dead);
	void Print(vector<vector<Cell>> matrix);

private:
	char alive;
	char dead;

};