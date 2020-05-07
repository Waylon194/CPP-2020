#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

std::vector<int> findLargestBlock(const std::vector<std::vector<int>>& m);
std::vector<int> findBlock(const std::vector<std::vector<int>>& m, int x, int y);
bool rightTrue(const std::vector<std::vector<int>>& m, int x, int y);
bool downTrue(const std::vector<std::vector<int>>& m, int x, int y);

int main()
{
	std::cout << "Enter bounds:\n";
	std::string input;
	std::cin >> input;

	int size = std::stoi(input);
	size %= 100;

	vector<vector<int>> matrix(size, std::vector<int>(size));

	for (size_t x = 0; x < matrix.size(); x++)
	{
		for (size_t y = 0; y < matrix[x].size(); y++)
		{
			matrix[x][y] = rand() % 2;
			cout << matrix[x][y] << " ";
		}
		cout << '\n';
	}

	vector<int> biggest = findLargestBlock(matrix);
	cout << biggest[2];
}

std::vector<int> findLargestBlock(const std::vector<std::vector<int>>& m)
{
	vector<std::vector<int>> cache = m;
	int xPos, yPos;
	int result = 0;

	for (size_t x = 0; x < m.size(); x++)
	{
		for (size_t y = 0; y < m[x].size(); y++)
		{
			if (x == 0 || y == 0)
			{

			}
			else if (m[x][y] > 0)
			{
				int lowest = m[x][y - 1];
				if (m[x - 1][y] < lowest)
				{
					lowest = m[x - 1][y];
				}
				if (m[x - 1][y - 1] < lowest)
				{
					lowest = m[x - 1][y - 1];
				}
				cache[x][y] = 1 + lowest;
			}
			if (cache[x][y] > result)
			{
				result = cache[x][y];
				xPos = x;
				yPos = y;
			}
		}
	}
	return {xPos - result + 1, yPos - result + 1, result};
}

bool rightTrue(const std::vector<std::vector<int>>& m, int x, int y)
{
	return m[x + 1][y] == 1;
}

bool downTrue(const std::vector<std::vector<int>>& m, int x, int y)
{
	return m[x][y + 1] == 1;
}