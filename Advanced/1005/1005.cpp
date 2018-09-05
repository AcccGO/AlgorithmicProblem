//The Largest Generation
/*
A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation.  Your task is to find the generation with the largest population.
*/

#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

map<int, int>levelsChildNum;
map<string, vector<string>>level;

int main()
{
	int N, M;
	cin >> N >> M;
		
	for (int i = 0; i < M; i++)
	{
		string member,nextChild;
		int childNum;

		cin >> member >> childNum;
		level[member] = *new vector<string>();
		for (int j = 0;j < childNum;j++)
		{
			cin >> nextChild;
			level[member].push_back(nextChild);
		}
	}

	int maxMembers = 1;
	int maxLevel = 1;
	void countTree(string currentMember, int currentLevel);
	countTree("01", 1);
	map<int, int>reverseNum;
	map<int, int>::iterator iter;
	for (iter=levelsChildNum.begin();iter!=levelsChildNum.end();iter++)
	{
		reverseNum[iter->second] = iter->first;
	}
	iter = reverseNum.end();
	iter--;
	cout<<iter->first<<" "<<iter->second<<endl;
}



void countTree(string currentMember, int currentLevel)
{
	if (currentMember.empty())
		return ;
	levelsChildNum[currentLevel] += 1;
	for (int i = 0; i < level[currentMember].size(); i++)
	{
		countTree(level[currentMember][i], currentLevel + 1);
	}
}
