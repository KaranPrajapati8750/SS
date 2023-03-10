#include <iostream>
using namespace std;

struct grid {
	int x;
	int y;
};

int main()
{
	int n;
	cin >> n;

	grid s,d;

	cin >> s.x >> s.y >> d.x >> d.y;

	grid* vertex = new grid[2 * n + 2];

	int* a = new int[n];

	for (int i = 0;i < 2*n;i+=2) {
		cin >> vertex[i].x >> vertex[i].y;
		cin >> vertex[i+1].x >> vertex[i+1].y;
		cin >> a[i / 2];
	}

	vertex[2 * n] = s;
	vertex[2 * n + 1] = d;

	int** graph = new int* [2 * n + 2];

	for (int i = 0;i < 2 * n + 2;i++) {
		graph[i] = new int[2 * n + 2];
	}

	int V = 2 * n + 2;

	for (int i = 0;i < V;i++) {
		for (int j = 0;j < V;j++) {
			graph[i][j] = abs(vertex[i].x - vertex[j].x) + abs(vertex[i].y - vertex[j].y);
		}
	}

	for (int i = 0;i < n;i++) {
		if (a[i] < graph[2*i][2*i+1]) {
			graph[2 * i][2 * i + 1] = a[i];
			graph[2 * i + 1][2 * i] = a[i];
		}
	}

	for (int i = 0;i < V;i++) {
		for (int j = 0;j < V;j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	for (int k = 0;k < V;k++) {
		for (int i = 0;i < V;i++) {
			for (int j = 0;j < V;j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	cout << graph[2 * n][2 * n + 1];
	return 0;

}