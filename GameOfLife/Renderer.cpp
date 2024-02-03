#include "Renderer.h"
#include "Cell.h"
#include <vector>
#include <iostream>

using namespace std;

Renderer::Renderer(char alive, char dead)
{
	this->alive = alive;
	this->dead = dead;
}

void Renderer::Print(vector<vector<Cell>> matrix)
{
	//height loop
	for (int i = 0; i < matrix.size(); i++)
	{
		//get array at i
		const vector<Cell> row = matrix[i];
		
		//row loop
		for (int j = 0; j < row.size(); j++) {

			Cell cell = row[j];

			//check if cell alive or dead
			if (cell.GetState()) {
				cout << alive << " ";
			}
			else {
				cout << dead << " ";
			}
		}
		cout << endl;
	}
}