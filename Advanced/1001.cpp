//public Bike Management
//dijkstra+dfs

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#define INFI 65535
using namespace std;
int minSend = INFI;
int minBack = INFI;
vector<int>finalPath;

int main()
{
	int CMAX, N, SP, M;
	cin >> CMAX >> N >> SP >> M;

	int* bikesInStation = new int[1+N];
	bikesInStation[0] = 0;//0 is PBMC
	for (int i = 1; i < N+1; i++)
	{
		cin >> bikesInStation[i];
		bikesInStation[i] = bikesInStation[i] - CMAX*0.5;
	}

	int**roadsCost = new int*[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		roadsCost[i] = new int[N + 1];
	}
	for(int i=0;i<N+1;i++)
		for (int j = 0; j < N + 1; j++)
		{
			roadsCost[i][j] = INFI;
		}
	for (int i = 0; i < M; i++)
	{
		int s1, s2,cost;
		cin >> s1 >> s2 >> cost;
		roadsCost[s1][s2] = cost;
		roadsCost[s2][s1] = cost;
	}

	//dijkstra, find shortest path
	vector<int>*prevStation = new vector<int>[N + 1];
	int*cost = new int[N + 1];
	int*visited = new int[N + 1];
	fill(cost, cost + N + 1, INFI);
	fill(visited, visited + N + 1, 0);

	cost[0] = 0;
	while (1)
	{
		int currentCost = INFI;
		int currentIndex = 0;
		for (int i = 0; i < N + 1; i++)
		{
			if (!visited[i] && cost[i] < currentCost)
			{
				currentCost = cost[i];
				currentIndex = i;
			}
		}
		if (currentCost == INFI) break;
		visited[currentIndex] = 1;
		//adjust
		for (int i = 0; i < N + 1; i++)
		{
			if (!visited[i] && cost[i] == cost[currentIndex] + roadsCost[currentIndex][i] && roadsCost[currentIndex][i] != INFI)
			{
				prevStation[i].push_back(currentIndex);
			}
			else if (!visited[i] && cost[i] > cost[currentIndex] + roadsCost[currentIndex][i] && roadsCost[currentIndex][i] != INFI)
			{
				prevStation[i].clear();
				prevStation[i].push_back(currentIndex);
				cost[i] = cost[currentIndex] + roadsCost[currentIndex][i];
			}
		}
	}
	void dfs(int sp,vector<int>* prevStation,vector<int>currentPath, int*bikesInStation);
	vector<int>currentPath = *new vector<int>();
	dfs(SP,prevStation,currentPath, bikesInStation);

	//print
	cout << minSend << " 0";
	for (int i = finalPath.size() - 2; i >= 0; i--)
		cout <<"->"<< finalPath[i];
	cout << " "<<minBack << endl;

	delete[] bikesInStation;
	delete[] roadsCost;
	delete[] prevStation;

	return 0;
}

void dfs(int sp, vector<int>* prevStation, vector<int>currentPath,int*bikesInStation)
{
	currentPath.push_back(sp);
	//when go back to PBMS
	if (sp == 0)
	{
		int send = 0, back = 0;
		for (int i = currentPath.size() - 2; i >= 0; i--)
		{
			int currentStation = currentPath[i];
			if (bikesInStation[currentStation] > 0)
				back += bikesInStation[currentStation];
			else if (bikesInStation[currentStation] < 0)
			{
				if (back + bikesInStation[currentStation] >= 0)
				{
					back += bikesInStation[currentStation];
				}
				else
				{
					send += -bikesInStation[currentStation] - back;
					back = 0;
				}
			}
		}
		if (send < minSend)
		{
			minSend = send;
			minBack = back;
			finalPath = currentPath;
		}
		else if (send == minSend&&back < minBack)
		{
			minBack = back;
			finalPath = currentPath;
		}
		currentPath.pop_back();
		return;
	}
	for (int i = 0; i < prevStation[sp].size(); i++)
	{
		dfs(prevStation[sp][i], prevStation,currentPath, bikesInStation);
	}
	currentPath.pop_back();
}
