//Graduate Admission
/*
太长了省略，自行搜索
*/
//先给学生按成绩排序，按成绩先后选学校，选满就不再选
#include<iostream>
#include<vector>
using namespace std;

class stu
{
public:
	int GE;
	int GI;
	int sum;
	vector<int>preferSchool;
	int stuID;
	int rank;
	int schoolAccepted;
};

class sch
{
public:
	int schID;
	int quota;
	int curCount;
	int* studentsAccepted;
	sch()
	{
		curCount = 0;
	}
};

int cmp1(const void* a, const void* b)
{
	stu* aa = (stu*)a;
	stu* bb = (stu*)b;
	if (aa->sum != bb->sum)
		return -aa->sum + bb->sum;
	else
		return -aa->GE + bb->GE;
}
int cmp2(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	stu *students=new stu[N];
	sch *schools=new sch[M];
	for (int i = 0; i < M; i++)
	{
		cin >> schools[i].quota;
		schools[i].studentsAccepted = new int[schools[i].quota];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> students[i].GE >> students[i].GI;
		students[i].sum = students[i].GE + students[i].GI;
		students[i].preferSchool = vector<int>(K);
		students[i].stuID = i;
		for (int j = 0; j < K; j++)
			cin >> students[i].preferSchool[j];
	}
	qsort(students, N, sizeof(stu), cmp1);
	students[0].rank = 1;
	for (int i = 1; i<N; i++)
	{
		if (students[i].sum == students[i - 1].sum&&students[i].GE == students[i-1].GE)
			students[i].rank = students[i - 1].rank;
		else
			students[i].rank = students[i-1].rank + 1;
	}
	for(int i=0;i<N;i++)
		for (int j = 0; j < K; j++)
		{
			int choice = students[i].preferSchool[j];
			if (schools[choice].curCount< schools[choice].quota)
			{
				schools[choice].studentsAccepted[schools[choice].curCount]=students[i].stuID;
				students[i].schoolAccepted = choice;
				schools[choice].curCount++;
				break;
			}
			else if((i>=1)&&(students[i].rank==students[i-1].rank)&&(choice==students[i-1].schoolAccepted))
			{
				schools[choice].studentsAccepted[schools[choice].curCount] = students[i].stuID;
				students[i].schoolAccepted = choice;
				schools[choice].curCount++;
				break;
			}
		}
	for (int i = 0; i < M; i++)
	{
		//yong vector有问题！
		qsort(schools[i].studentsAccepted, schools[i].curCount, sizeof(int), cmp2);
		for (int j = 0; j < schools[i].curCount; j++)
		{
			if (j == 0)
				cout << schools[i].studentsAccepted[j];
			else
				cout<<" " << schools[i].studentsAccepted[j];
		}
		cout << endl;
	}

	return 0;
}
