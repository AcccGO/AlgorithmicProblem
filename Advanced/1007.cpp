//Consecutive Factors

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
using namespace std;

vector<vector<int>>conseNums;
vector<int>minConseNums;
vector<int>currentMinConseNums;
int N;

void Deviosion(int nextI,int M,vector<int> currentNums)
{
	if (M == 1)
	{
		conseNums.push_back(currentNums);
		return;
	}
	for (int i = nextI; i <= sqrt(N); i++)
	{
		if (M%i == 0)
		{
			if (i==nextI)
			{
				currentMinConseNums.push_back(i);
				if (currentMinConseNums.size() > minConseNums.size())
					minConseNums = currentMinConseNums;
				else if(currentMinConseNums.size()== minConseNums.size()&& currentMinConseNums.size()!=0&&currentMinConseNums[0]<minConseNums[0])
					minConseNums = currentMinConseNums;
			}
			else
			{
				currentMinConseNums.clear();
			}

			currentNums.push_back(i);
			Deviosion(i + 1, M / i, currentNums);
			currentNums.pop_back();
		}
	}
	
}

int main()
{
	cin >> N;

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (N%i!=0) continue;
		vector<int> New = *new vector<int>();
		New.push_back(i);

		currentMinConseNums.clear();
		currentMinConseNums.push_back(i);
		if (currentMinConseNums.size() > minConseNums.size())
			minConseNums = currentMinConseNums;
		else if (currentMinConseNums.size() == minConseNums.size() && currentMinConseNums.size() != 0 && currentMinConseNums[0]<minConseNums[0])
			minConseNums = currentMinConseNums;

		Deviosion(i + 1, N / i, New);
	}

	if (minConseNums.size() == 0)
		minConseNums.push_back(N);

	cout << minConseNums.size() << endl;
	for (int i = 0; i < minConseNums.size(); i++)
	{
		if (i == 0) cout << minConseNums[i];
		else cout << "*" << minConseNums[i];
	}
	cout << endl;

	return 0;
}
