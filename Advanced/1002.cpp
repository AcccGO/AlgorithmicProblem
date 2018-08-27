//All Roads Lead to Rome
//dijkstra
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>
#include<map>
#define INFIN 65535
using namespace std;

map<string, int>happy1;
map<int, string>happy2;

void PrintRoute(int index,int* preCity)
{
	if (preCity[index] != -1)
	{
		PrintRoute(preCity[index], preCity);
	}
	else if (preCity[index == -1])
		return;
	cout << "->" << happy2[index];
}

int main()
{
	int N, K;
	int romIndex;
	string startCity;
	cin >> N >> K >> startCity;
	int* happy = new int[N];
	int* cost = new int[N];
	int* visited = new int[N];
	int* routeNum = new int[N];
	int* cityNum = new int[N];
	int* happySum = new int[N];
	int* preCity = new int[N];
	int**matrixRoads = new int* [N];
	for (int i = 0; i < N; i++)
		matrixRoads[i] = new int[N];
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			matrixRoads[i][j] = INFIN;
		}
	fill(cost,cost+N, INFIN);
	fill(visited, visited + N, 0);
	fill(routeNum, routeNum + N, 0);
	fill(cityNum, cityNum + N, 0);
	fill(happySum, happySum + N, 0);
	fill(preCity, preCity + N, -1);

	happy1[startCity] = 0;
	happy2[0] = startCity;
	happy[0] = 0;

	//cityHappys
	for (int i = 1; i < N; i++)
	{
		string temps;
		int tempi;
		cin >> temps >> tempi;
		happy1[temps] = i;
		happy2[i] = temps;
		happy[i] = tempi;
		if (temps == "ROM")
			romIndex = i;
	}

	//roads
	for (int i = 0; i < K; i++)
	{
		string city1, city2;
		int cost;
		cin >> city1 >> city2 >> cost;
		matrixRoads[happy1[city1]][happy1[city2]] = cost;
		matrixRoads[happy1[city2]][happy1[city1]] = cost;
	}

	//dijkstra
	cost[0] = 0;
	routeNum[0] = 1;
	while (1)
	{
		int currentIndex;
		int currentCost = INFIN;
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && currentCost > cost[i])
			{
				currentCost = cost[i];
				currentIndex = i;
			}
		}
		if (currentCost == INFIN)
			break;
		visited[currentIndex] = 1;
		//update each road's cost
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && cost[i] == cost[currentIndex] + matrixRoads[currentIndex][i]&& matrixRoads[currentIndex][i]!=INFIN)
			{
				routeNum[i] += routeNum[currentIndex];
				if (happySum[currentIndex] + happy[i] > happySum[i])
				{
					happySum[i] = happySum[currentIndex] + happy[i];
					cityNum[i] = cityNum[currentIndex] + 1;
					preCity[i] = currentIndex;
				}
				else if (happySum[currentIndex] + happy[i] == happySum[i])
				{
					if (cityNum[currentIndex] + 1 < cityNum[i])
					{
						cityNum[i] = 1 + cityNum[currentIndex];
						preCity[i] = currentIndex;
					}
				}
			}
			else if (!visited[i] && cost[i] > cost[currentIndex] + matrixRoads[currentIndex][i])
			{
				cost[i] = cost[currentIndex] + matrixRoads[currentIndex][i];
				cityNum[i] = 1 + cityNum[currentIndex];
				preCity[i] = currentIndex;
				happySum[i] = happySum[currentIndex] + happy[i];
				routeNum[i] = routeNum[currentIndex];
			}
		}
	}
	
	//print
	cout << routeNum[romIndex]<<" "<< cost[romIndex] <<" "<< happySum[romIndex] <<" "<< happySum[romIndex] / cityNum[romIndex] << endl;
	cout<<startCity;
	PrintRoute(romIndex, preCity);
	cout << endl;

	//clear
	delete[] happy;
	delete[] cost;
	delete[] visited;
	delete[] routeNum;
	delete[] cityNum;
	delete[] happySum;
	delete[] matrixRoads;

	return 0;
}
