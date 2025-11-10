#include <iostream>

//using namespace std;

int ROW, COLUMN, R, X1, Y1, X2, Y2, MAX;
int matrix[108][108];

int main()
{
	std::cin >> ROW >> COLUMN >> R;
	for (int row = 1; row <= ROW; row++)
	{
		for (int column = 1; column <= COLUMN; column++)
		{
			std::cin >> matrix[row][column];
		}
	}

	for (int temp = 1; temp <= R; temp++)
	{
		std::cin >> X1 >> Y1 >> X2 >> Y2;
		if ((X1 > X2) || (Y1 > Y2))
		{
			std::cout << "INVALID" << "\n";
		}
		else if ((X1 > ROW) || (Y1 > COLUMN) || (X2 < 1) || (Y2 < 1))
		{
			std::cout << "OUTSIDE" << "\n";
		}
		else
		{
			X1 = std::max(1,X1);
			Y1 = std::max(1,Y1);
			X2 = std::min(ROW,X2);
			Y2 = std::min(COLUMN,Y2);

			MAX = matrix[X1][Y1];

			for (int row = X1; row <= X2; row++)
			{
				for (int column = Y1; column <= Y2; column++)
				{
					if (matrix[row][column] > MAX)
					{
						MAX = matrix[row][column];
					}
				}
			}

			std::cout << MAX << "\n";

		}
	}
}