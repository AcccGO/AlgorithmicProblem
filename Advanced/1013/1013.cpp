//Hashing
/*
The task of this problem is simple: insert a sequence of distinct positive integers into a hash table, and output the positions of the input numbers.  The hash function is defined to be "H(key) = key % TSize" where TSize is the maximum size of the hash table.  Quadratic probing (with positive increments only) is used to solve the collisions.
Note that the table size is better to be prime.  If the maximum size given by the user is not prime, you must re-define the table size to be the smallest prime number which is larger than the size given by the user.
*/
//冲突时使用二次探查
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int main()
{
	int Msize, N;
	cin >> Msize >> N;
	vector<int>nums=*new vector<int>(N);

	void FindPrime(int *m);
	FindPrime(&Msize);
	vector<bool>*hashTable = new vector<bool>(Msize);
	hashTable->assign(Msize, false);

	void Hash(int n, int m, vector<bool>*hashTable, bool first);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		Hash(nums[i],Msize, hashTable, !i);
	}
	return 0;
}

bool isPrime(int m)
{
	if (m == 2) return true;
	if (m==1||!(m % 2)) return false;
	for (int i = 3; i <= sqrt(m); i = i + 2)
	{
		if (!(m%i))
			return false;
	}
	return true;
}

void FindPrime(int *m)
{
	while (!isPrime(*m))
		*m += 1;
}

void Hash(int n,int m, vector<bool>*hashTable,bool first)
{
	int key = n%m;
	int i = 0;
	while (1)
	{
		int nextKey = (key + i*i)%m;
		if (nextKey > ((*hashTable).size() - 1))
		{
			if (first) cout << "-";
			else  cout << " " << "-";
			return;
		}
		if ( !(*hashTable)[nextKey])
		{
			(*hashTable)[nextKey] = true;
			if (first)  cout << nextKey;
			else  cout << " " << nextKey;
			return;
		}
		i++;
	}
}
