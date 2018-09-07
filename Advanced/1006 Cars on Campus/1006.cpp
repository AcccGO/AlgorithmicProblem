//Cars on Campus

#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;

class Node
{
public:
	string carId;
	int seconds;
	int inOrOout;//1 is IN, -1 is OUT
public:
	Node(string CarId, int Seconds, int InOrOut);
};

Node::Node(string CarId, int Seconds, int InOrOut)
{
	carId = CarId;
	seconds = Seconds;
	inOrOout = InOrOut;
}

void secondsToTime(int time)
{
	cout << setw(2) << setfill('0') << (int)time / 3600 << ":" << setw(2) << setfill('0') << (int)time % 3600 / 60 << ":" << setw(2) << setfill('0') << (int)time % 60 << endl;
}

bool compare1(Node a, Node b)
{
	if (a.carId != b.carId) return a.carId < b.carId;
	return a.seconds < b.seconds;
}

bool compare2(Node a, Node b)
{
	return a.seconds < b.seconds;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<Node>records;
	vector<Node>validRecords;
	map<string, int>carsTimeSum;
	int maxParkingTime = 0;
	for (int i = 0; i < N; i++)
	{
		string car;
		int hour,min,sec;
		string inOrOut;
		cin >> car;
		scanf("%d:%d:%d",&hour,&min,&sec);
		cin >> inOrOut;
		int seconds = hour*3600+min*60+sec;
		int intInOrOut = (inOrOut == "in") ? 1 : -1;
		Node temp(car, seconds, intInOrOut);
		records.push_back(temp);
	}
	
	//sort by car id
	sort(records.begin(), records.end(), compare1);
	//remove invalid records and cal max time for each car
	for (int i = 0; i < N - 1; i++)
	{
		if (records[i].carId == records[i + 1].carId&&records[i].inOrOout == 1 && records[i + 1].inOrOout == (-1))
		{
			validRecords.push_back(records[i]);
			validRecords.push_back(records[i + 1]);
			carsTimeSum[records[i].carId] += records[i + 1].seconds - records[i].seconds;
			if (carsTimeSum[records[i].carId] > maxParkingTime)
				maxParkingTime = carsTimeSum[records[i].carId];
		}
	}
	
	//sort by time
	sort(validRecords.begin(), validRecords.end(), compare2);
	//cal the sum of cars at each record point
	int* currentCarNum = new int[validRecords.size()];
	for (int i = 0; i < validRecords.size(); i++)
	{
		if (i == 0)
			currentCarNum[0] = validRecords[0].inOrOout;
		else
			currentCarNum[i] = currentCarNum[i - 1] + validRecords[i].inOrOout;
	}

	//get record to cal
	//** k records is ascending, so we can save some time while looping
	vector<int>answers;
	int currentPos = 0;
	for (int i = 0; i < K; i++)
	{
		int hour, min, sec;
		scanf("%d:%d:%d", &hour, &min, &sec);

		int currentTime=hour*3600+min*60+sec;
		for (int j = currentPos; j < validRecords.size(); j++)
		{
			if (currentTime >= validRecords[j].seconds && ((j == validRecords.size() - 1) || (currentTime < validRecords[j + 1].seconds)))
			{
				answers.push_back(currentCarNum[j]);
				//cout << currentCarNum[j] <<endl;
				currentPos = j;
				break;
			}
		}
	}

	for (int i = 0; i < answers.size(); i++)
	{
		cout << answers[i] << endl;
	}
	//cout max parking time
	//** may have many cars 
	for (map<string, int>::iterator it = carsTimeSum.begin(); it != carsTimeSum.end(); it++)
	{
		if (it->second == maxParkingTime)
			cout << it->first<<" ";
	}
	secondsToTime(maxParkingTime);

	delete[] currentCarNum;
	return 0;
}

