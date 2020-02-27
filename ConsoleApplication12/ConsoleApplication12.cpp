#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;
void fill(int** arr, int n, int m);
void in_file(int**, int, int, ofstream&);
void out_of_file( int, int, ifstream&);


int main()
{ 
	string p = "71.txt";
	ofstream file(p);
	srand(time (NULL));
	int** arr = new int* [8];
	for (int i = 0; i < 8; i++)
		arr[i] = new int[4];
	fill(arr, 8, 4);
	in_file(arr, 8, 4, file);
	fill(arr, 8, 4);
	file << endl;
	file.close();
	ofstream file1(p, ios::app);
	fill(arr, 8, 4);
	in_file(arr, 8, 4, file1);
	ifstream file2(p, ios::app);
	out_of_file(8, 4, file2);
	cout << endl;
	out_of_file(8, 4, file2);
}


void fill(int** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = rand() % 14 - 3;
}

void in_file(int** arr, int n, int m, ofstream& file)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			file << setw(4) << arr[i][j];
		file << endl;
	}
}

void out_of_file(int n, int m, ifstream& file)
{
	int buff;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			file >> buff;
			cout << setw(4) << buff;
		} cout << endl;
	}
	
}