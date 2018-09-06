//Forwards on Weibo (30)
/*
Weibo is known as the Chinese version of Twitter.  One user on Weibo may have many followers, and may follow many other users as well.  Hence a social network is formed with followers relations.  When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers.  Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.
*/

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<set>
using namespace std;

map<int, vector<int>>followed;
set<int>currentForward;

void cal(int user, int level, int L)
{
	vector<int> currentFollowers = followed[user];
	if (currentFollowers.empty()) return;
	if (level > L) return;
	for (int i = 0; i < currentFollowers.size(); i++)
	{
		if (currentForward.find(currentFollowers[i]) == currentForward.end())
		{
			currentForward.insert(currentFollowers[i]);
		}
		cal(currentFollowers[i], level + 1, L);
	}
	return;
}

int main()
{
	int N, L,K;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int num, temp;
		vector<int>tempVector;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> temp;
			followed[temp].push_back(i + 1);
			tempVector.push_back(temp);
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		//calculate
		currentForward.clear();
		currentForward.insert(temp);
		cal(temp, 1, L);
		cout << currentForward.size()-1 << endl;
	}
}

