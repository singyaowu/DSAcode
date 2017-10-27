//#define BFSS
#ifdef BFSS
#include <iostream>
#include <queue>
using namespace std;
struct location
{
	int y;
	int x;
};
int BFS(int maze[][9], location start, location end)
{
	queue<int> x;
	queue<int> y;
	queue<int> numWalk;
	x.push(start.x);
	y.push(start.y);
	numWalk.push(0);
	while (true)
	{
		if (x.front() == end.x && y.front() == end.y)
		{
			return numWalk.front();
		}
		if ((x.front() <= 6 && y.front() <= 7) &&
			((maze[x.front() + 2][y.front() + 1] != 1) || (x.front() + 2 == end.x&&y.front() + 1 == end.y)))
		{
			x.push(x.front() + 2); y.push(y.front() + 1); numWalk.push(numWalk.front() + 1);
		}
		if ((x.front() <= 7 && y.front() <= 6) &&
			((maze[x.front() + 1][y.front() + 2] != 1) || (x.front() + 1 == end.x&&y.front() + 2 == end.y)))
		{
			x.push(x.front() + 1); y.push(y.front() + 2); numWalk.push(numWalk.front() + 1);
		}
		if ((x.front() >= 1 && y.front() <= 6) &&
			((maze[x.front() - 1][y.front() + 2] != 1) || (x.front() - 1 == end.x&&y.front() + 2 == end.y)))
		{
			x.push(x.front() - 1); y.push(y.front() + 2); numWalk.push(numWalk.front() + 1);
		}
		if ((x.front() >= 2 && y.front() <= 7) &&
			((maze[x.front() - 2][y.front() + 1] != 1) || (x.front() - 2 == end.x&&y.front() + 1 == end.y)))
		{
			x.push(x.front() - 2); y.push(y.front() + 1 ); numWalk.push(numWalk.front() + 1);
		}
		if ((x.front() >= 2 && y.front() >= 1) &&
			((maze[x.front() - 2][y.front() - 1] != 1) || (x.front() - 2 == end.x&&y.front() - 1 == end.y)))
		{
			x.push(x.front() - 2); y.push(y.front() - 1); numWalk.push(numWalk.front() + 1);
		}
		if ((x.front() >= 1 && y.front() >= 2) &&
			((maze[x.front() - 1][y.front() - 2] != 1) || (x.front() - 1 == end.x&&y.front() - 2 == end.y)))
		{
			x.push(x.front() - 1); y.push(y.front() - 2); numWalk.push(numWalk.front() + 1);
		}
		if ((x.front() <= 7 && y.front() >= 2) &&
			((maze[x.front() + 1][y.front() - 2] != 1) || ((x.front() + 1 == end.x)&&(y.front() - 2 == end.y))))
		{
			x.push(x.front() + 1); y.push(y.front() - 2); numWalk.push(numWalk.front() + 1);
		}
		if ((x.front() <= 6 && y.front() >= 1) &&
			((maze[x.front() + 2][y.front() - 1] != 1) || (x.front() + 2 == end.x&&y.front() - 1 == end.y)))
		{
			x.push(x.front() + 2); y.push(y.front() - 1); numWalk.push(numWalk.front() + 1);
		}
		x.pop();
		y.pop();
		numWalk.pop();
	}
}
int main()
{
	int N, M;
	int maze[9][9] = {0};
	location start;
	location end;
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		char x,y;
		cin >> y >> x; 
		maze[x - '1'][y - 'a'] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		char xs, ys, xf,yf;
		cin >> ys >> xs;
		start.y = ys - 'a';
		start.x = xs - '1';
		cin >> yf >> xf;
		end.y = yf - 'a';
		end.x = xf - '1';
		int need = BFS(maze, start, end);
		cout << "Going from " << ys << xs << " to " << yf << xf << " needs " << need << " moves.\n";
	}

	return 0;
}
#endif