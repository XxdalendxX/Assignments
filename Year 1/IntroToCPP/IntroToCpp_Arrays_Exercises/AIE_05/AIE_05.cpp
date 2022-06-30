
#include <iostream>




int main(int argc, char** argv)
{
	const int ROWS = 3;
	const int COLS = 5;

	const char* grid2D[ROWS][COLS] =
	{
		{ "a0", "a1", "a2", "a3", "a4" },
		{ "b0", "b1", "b2", "b3", "b4" },
		{ "c0", "c1", "c2", "c3", "c4" },
	};


	// Task 1:
	// Print all values in the grid using nested loops to iterate over rows and columns.
	// ------------------------------------------------------------------------

	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLS; y++)
		{
			std::cout << grid2D[x][y] << " ";
		}
		std::cout << std::endl;
	}
	
	std::cout << std:: endl;

	// ------------------------------------------------------------------------







	// Task 2:
	// Print all values in the grid using a single loop
	// ------------------------------------------------------------------------

	for (int index = 0; index < ROWS * COLS; index++)
	{
		// TODO: convert "index" to a "rowIndex" and "colIndex" value
		int rowIndex = 0;
		int colIndex = 0;
		
			rowIndex = floor(index / COLS);
			colIndex = (index % COLS);

		// use the resulting row and column index to print the value
		std::cout << grid2D[rowIndex][colIndex] << ", ";
	}

	std::cout << " " << std::endl;
	std::cout << std::endl;


	// ------------------------------------------------------------------------


	const char* grid1D[ROWS*COLS] =
	{
		"a0", "a1", "a2", "a3", "a4",
		"b0", "b1", "b2", "b3", "b4",
		"c0", "c1", "c2", "c3", "c4"
	};

	// Task 3:
	// using a nested loop to iterate over rows/columns
	// convert the row and column index to a single index value to print the values
	// of grid1D
	// ------------------------------------------------------------------------

	
	for (int rowIndex = 0; rowIndex < ROWS; rowIndex++)
	{
		for (int colIndex = 0; colIndex < COLS; colIndex++)
		{
			// TODO: calculate "index" based on rowIndex/colIndex value
			int index = 0;
			int xIndex = 0;
			int yIndex = 0;

			xIndex = colIndex;
			yIndex = rowIndex * COLS;


			index = xIndex + yIndex;

			// use the resulting index to print the value
			std::cout << grid1D[index] << ", ";
		}
		std::cout << std::endl;
	}

	// ------------------------------------------------------------------------

}

