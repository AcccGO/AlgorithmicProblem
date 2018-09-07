//Acute Stroke
//孤岛问题，广度优先搜索BFS
#include<iostream>
#include<queue>
using namespace std;

int slices[60][1286][128] = { 0 };
int	isInQueue[60][1286][128] = { 0 };
int moveStep[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};

class Pixel
{
public:
	Pixel(int xx, int yy, int zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}
	int x;
	int y;
	int z;
};

int CalVolume(int i,int j,int k)
{
	if (!slices[i][j][k]||isInQueue[i][j][k]) return 0;

	int sum = 0;
	queue<Pixel> currentQue;
	currentQue.push(*new Pixel(i, j, k));
	isInQueue[i][j][k] = 1;
	while (currentQue.size()!=0)
	{
		Pixel currentPixel = currentQue.front();
		currentQue.pop();
		sum++;
		for (int m = 0; m < 6; m++)
		{
			int nextZ = currentPixel.x + moveStep[m][0];
			int nextX = currentPixel.y + moveStep[m][1];
			int nextY = currentPixel.z + moveStep[m][2];
			if (nextX < 0 || nextY < 0 || nextZ < 0) continue;
			
			if (slices[nextZ][nextX][nextY]!=0 && !isInQueue[nextZ][nextX][nextY])
			{
				Pixel nextPixel = *new Pixel(nextZ,nextX,nextY);
				currentQue.push(nextPixel);
				isInQueue[nextZ][nextX][nextY] = 1;
			}
		}
	}
	return sum;

}

int main()
{
	int M, N, L, T;
	cin >> M >> N >> L >> T;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				cin >> slices[i][j][k];
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				int temp= CalVolume(i, j, k);
				if (temp >= T) sum += temp;
			}
		}
	}
	cout << sum << endl;
	return 0;
}
