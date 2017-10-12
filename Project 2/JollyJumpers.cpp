#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	//vector<int>::iterator position;
	int val = 0, size = 0, difference = 0;

	while (cin >> size)
	{
		vector <int> vect_values(size);
		vector <int> check_values(size);
		for (int i = 0; i < size; i++)
		{
			cin >> val;
			vect_values[i] = val;
		}
		check_values[0] = 1;
		for (int i = 0; i < size - 1; ++i)
		{
			difference = abs(vect_values[i + 1] - vect_values[i]);
			if (difference > 0 && difference < size)
				check_values[difference] = 1;
		}

		vector<int>::iterator position = find(check_values.begin(), check_values.end(), 0);
		if (position == check_values.end())
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
	return 0;
}
