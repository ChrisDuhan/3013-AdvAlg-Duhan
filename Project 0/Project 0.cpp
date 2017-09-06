//********************************************************************
//      Project #0: Delete Duplicates from an Integer Array
//      Name: Chris Duhan
//      Class: Advanced Algorithms and Data Structures
//      Instructor: Mr. Richard Simpson
//      Due Date: 09/06/2017
//********************************************************************
//      This program takes a file containing a line of numbers
//		and checks it for duplicated numbers. It takes 
//		non-duplicated numbers and stores them in a new array
//		while ignoring duplicates. The input file must have the
//		quantity of numbers on the line (minus one) as the first
//		number on the line. When telling the program the user 
//		must give the filename as well as the file extension.
//		It is simple enoungh to do without containing it to
//		it's own function so the worst case complexity that
//		the program could experience is O(2n), occuring if there
//		no unique numbers in the list. Otherwise the complexity
//		is O(n).
//
//********************************************************************

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string fname = "none";
	cout << "Please enter the name of the file you wish to manipulate with file extension: " << endl;
	cin >> fname;
	ifstream input;
	input.open(fname);
	int init_array_size = 0;
	int readin_val = 0;
	int unique_cnt = 0;
	int list[101];

	if (input)
	{
		while (input >> init_array_size)
		{
			int * p1;
			p1 = new int[init_array_size];
			int p1_pos = 0;

			int unique_cnt = 0;				// reseting for each array

			for (int i = 0; i < init_array_size; i++)
			{
				input >> readin_val;

				if (list[readin_val] != 1)
				{
					list[readin_val] = 1;
					p1[p1_pos] = readin_val;
					unique_cnt++;			// I know p1_pos and unique_cnt are going to 
					p1_pos++;				// be the same but they handle different things
				}
			}

			for (int i = 0; i < 101; i++)
			{
				list[i] = 0;				// clearing for each array
			}

			int * p2;
			p2 = new int[unique_cnt];

			for (int i = 0; i < unique_cnt; i++)
			{
				p2[i] = p1[i];
			}
			
			delete [] p1;
			p1 = nullptr;

			for (int i = 0; i < unique_cnt; i++)
			{
				cout << p2[i] << " ";
			}
			cout << endl;

			delete[] p2;
			p2 = nullptr;
		}
		input.close();
	}
    return 0;
}
