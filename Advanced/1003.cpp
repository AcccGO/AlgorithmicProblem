//Highest Price in Supply Chain 
#include<iostream>
#include <iomanip>
#include<math.h>
using namespace std;

int FindSource(int index, int*mm)
{
	if (mm[index] == -1) return 0;

	return FindSource(mm[index], mm) + 1;

}
int main()
{
	int N=0;
	float P, R;
	cin >> N >> P >> R;
	int *mm = new int[N];
	for (int i = 0; i < N; i++)
		cin >> mm[i];

	int max=-1;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = FindSource(i, mm);
		if (temp > max)
		{
			count = 1;
			max = temp;
		}
		else if (temp == max)
		{
			count++;
		}
	}

	float result = P*pow(0.01*R+1, max);
	cout << fixed << setprecision(2) << result << " " << count<<endl;

}

