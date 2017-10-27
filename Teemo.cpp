//#define te
#ifdef te
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int maze[2001][2001];

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < 2001; j++)
		{
			for (int k = 0; k < 2001; k++)
			{
				maze[j][k] = 0;
			}
		}
		int N, M;
		cin >> N >> M;
		//vector<bool[2 * N][2 * N]> maze;
		vector<int> lavaX;
		vector<int> lavaY;
		for (int j = 0; j < M; j++) {
			int X, Y;
			cin >> X >> Y;
			X += N;
			Y += N;
			maze[X][Y] = 1;
			int in = 2;
			int count = 0;
			while (count < 8) {
				count = 0;
				if (Y+in <= 2*N && (maze[X][Y + in] > in || maze[X][Y + in] == 0)) {
					maze[X][Y + in] = in;
				}
				else count++;
				if(X + in <= 2 * N &&( maze[X + in][Y] > in|| maze[X + in][Y] == 0)) {
					maze[X + in][Y] = in;
				}
				else count++;
				if (Y - in >= 0 && (maze[X][Y - in] > in|| maze[X][Y - in] == 0)) {
					maze[X][Y - in] = in;
				}
				else count++;
				if (X - in >= 0 && (maze[X - in][Y] > in||maze[X - in][Y] > in == 0)) {
					maze[X - in][Y] = in;
				}
				else count++;
				if (X + in <= 2 * N &&Y + in <= 2 * N &&(maze[X + in][Y + in] > in||maze[X + in][Y + in] == 0)) {
					maze[X + in][Y + in] = in;
				}
				else count++;
				if (X + in <= 2 * N &&Y - in >= 0 && (maze[X + in][Y - in] > in||maze[X + in][Y - in] == 0)) {
					maze[X + in][Y - in] = in;
				}
				else count++;
				if (X - in >= 0 && Y + in <= 2 * N && (maze[X - in][Y + in] > in||maze[X - in][Y + in] == 0)) {
					maze[X - in][Y + in] = in;
				}
				else count++;
				if (X - in >= 0 && Y - in >= 0 && (maze[X - in][Y - in] > in||maze[X - in][Y - in] == 0)) {
					maze[X - in][Y - in] = in;
				}
				else count++;
				in++;
			}
		}
		queue<int>x;
		queue<int>y;
		queue<int>time;
		x.push(N); y.push(N); time.push(0);
		int max = 0;
		while (!x.empty()) {
			int xf = x.front();
			int yf = y.front();
			int tim = time.front();
			if (xf >= 1 && yf >= 1) {
				if (maze[xf - 1][yf - 1] > 0 && maze[xf - 1][yf - 1] > tim) {
					x.push(xf - 1);
					y.push(yf - 1);
					time.push(tim + 1);
				}
			}
			if (xf >= 1 && yf <= 2*N - 1) {
				if (maze[xf - 1][yf + 1] > 0 && maze[xf - 1][yf + 1] > tim) {
					x.push(xf - 1);
					y.push(yf + 1);
					time.push(tim + 1);
				}
			}
			if (xf <= 2*N - 1 && yf >= 1) {
				if (maze[xf + 1][yf - 1] > 0 && maze[xf + 1][yf - 1] > tim) {
					x.push(xf + 1);
					y.push(yf - 1);
					time.push(tim + 1);
				}
			}
			if (xf <= 2 * N - 1 && yf >= 1) {
				if (maze[xf + 1][yf - 1] > 0 && maze[xf + 1][yf - 1] > tim) {
					x.push(xf + 1);
					y.push(yf - 1);
					time.push(tim + 1);
				}
			}
			if (xf <= 2 * N - 1 && yf <= 2 * N - 1) {
				if (maze[xf + 1][yf + 1] > 0 && maze[xf + 1][yf + 1] > tim) {
					x.push(xf + 1);
					y.push(yf + 1);
					time.push(tim + 1);
				}
			}
			if (xf <= 2 * N - 1) {
				if (maze[xf + 1][yf] > 0 && maze[xf + 1][yf] > tim) {
					x.push(xf + 1);
					y.push(yf);
					time.push(tim + 1);
				}
			}
			if (yf <= 2 * N - 1) {
				if (maze[xf][yf + 1] > 0 && maze[xf][yf + 1] > tim) {
					x.push(xf);
					y.push(yf + 1);
					time.push(tim + 1);
				}
			}
			if (xf >= 1) {
				if (maze[xf - 1][yf] > 0 && maze[xf - 1][yf] > tim) {
					x.push(xf - 1);
					y.push(yf);
					time.push(tim + 1);
				}
			}
			if (yf >= 1) {
				if (maze[xf][yf - 1] > 0 && maze[xf][yf - 1] > tim) {
					x.push(xf);
					y.push(yf - 1);
					time.push(tim + 1);
				}
			}
			if (maze[xf][yf] > 0 && maze[xf][yf] > tim) {
				x.push(xf);
				y.push(yf);
				time.push(tim + 1);
			}
			x.pop();
			y.pop();
			if (tim > max) {
				max = tim;
			}
			time.pop();
		}
		cout << max << '\n';
	}
	

	return 0;
}
#endif