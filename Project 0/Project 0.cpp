//********************************************************************
//      Project #0: Delete Duplicates from an Integer Array
//      Name: Chris Duhan
//      Class: Advanced Algorithms and Data Structures
//      Instructor: Mr. Richard Simpson
//      Due Date: 09/06/2017
//********************************************************************
//      Place your general program documentation here. It should
//      be quite a few lines explaining the programs duty carefully.
//      It should also indicate how to run the program and data
//      input format, filenames etc.
//********************************************************************

//********************************************************************
//      ObjectName::MethodName()
//      Parameters: List them here and comment
//      Complexity: O(N) (worst case)
//      A discussion of what the method/function does and required
//      parameters as well as return value. Also indicate the 
//      complexity of this function (worst case).
//********************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string fname = "none";
	cout << "Please enter the name of the file you wish to manipulate with file extension: " << endl;
	cin >> fname;
	ifstream input;
	ofstream output;
	input.open(fname);
	output.open("Chris_Duhan_output.txt");
	int x = 0;
	int val = 0;
	int cnt = 0;
	int list[101];
	vector <int> v;

	if (input)
	{
		while (input >> x)
		{
			for (int i = 0; i < x; i++)
			{
				input >> val;
				if (list[val] != 1)
				{
					list[val] = 1;
					v.push_back(val);
					cout << val << " ";
				}
			}
			cout << endl;
			int * p;
			p = new int[v.size()];
			for (unsigned i = 0; i < v.size(); i++)
			{
				p[i] = v[i];
				list[i] = 0;
			}
		}
		input.close();
	}
    return 0;
}
