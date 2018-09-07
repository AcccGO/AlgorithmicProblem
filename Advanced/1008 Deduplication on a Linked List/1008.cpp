//Deduplication on a Linked List
/*
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys.  That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept.  At the mean time, all the removed nodes must be kept in a separate list.  For example, given L being 21→-15→-15→-7→15, you must output 21→-15→-7, and the removed list -15→15.
*/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>
#include<unordered_set>

using namespace std;
class node
{
public:
	int key;
	string address;
	string nextAddress;
	node(int k, string a, string n)
	{
		key = k;
		address = a;
		nextAddress = n;
	}
};

int main()
{
	map<string, pair<int, string>> list;
	vector<node>linkedList;
	int N;
	string startAddress;
	cin >> startAddress >> N;

	for (int i = 0; i < N; i++)
	{
		string add,  next;
		int val;
		cin>>add>>val>>next;
		list[add] = { val, next };
	}
	string curNode = startAddress;
	while (1)
	{
		int curV = list[curNode].first;
		string nextNode = list[curNode].second;
		linkedList.push_back(node(curV, curNode, nextNode));
		if (nextNode == "-1")
			break;
		curNode = nextNode;
	}
	
	unordered_set<int>num;
	vector<node>removedList;
	vector<node>restList;
	for (int i = 0; i < linkedList.size(); i++)
	{
		if (num.find(abs(linkedList[i].key)) == num.end())
		{
			restList.push_back(linkedList[i]);
			num.insert(abs(linkedList[i].key));
		}
		else
		{
			removedList.push_back(linkedList[i]);
		}
	}

	for (int i = 0; i < restList.size(); i++)
	{
		cout << restList[i].address << " " << restList[i].key << " ";
		if (i == restList.size() - 1)
			cout << "-1" << endl;
		else
			cout << restList[i + 1].address << endl;
	}
	for (int i = 0; i < removedList.size(); i++)
	{
		cout << removedList[i].address << " " << removedList[i].key << " ";
		if (i == removedList.size() - 1)
			cout << "-1"<<endl;
		else
			cout << removedList[i + 1].address << endl;
	}

	return 0;
}
