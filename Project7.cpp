#include <iostream>
#include <list>
#include <fstream>
#include <queue>
#include <cassert>

using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	list<int> weight = {};
	void DFSUtil(int v, bool visited[])
	{
		visited[v] = true;
		cout << v << " ";
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
		{
			if (!visited[*i])
			{
				DFSUtil(*i, visited);
			}
		}
	}

public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int v, int w, int wght)
	{
		adj[v].push_back(w);
		weight.push_back(wght);
	}
	
	void DFS(int v)
	{
		bool* visited = new bool[V];
		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
		}
		DFSUtil(v, visited);
		delete[] visited;
	}

	void breadthFirstTraversal() {
		queue<int> q;
		bool* visited;
		visited = new bool[V];
		for (int index = 0; index < V; index++) {
			visited[index] = false;
		}
		list<int>::iterator i;
		for (int index = 0; index < V; index++) {
			q.push(index);
			if (!visited[index]) {
				visited[index] = true;
				cout << index << " ";
			}
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (i = adj[u].begin(); i != adj[u].end(); ++i) {
					int w = *i;
					if (!visited[w]) {
						q.push(w);
						visited[w] = true;
						cout << w << " ";
					}
				}
			}
		}
		delete[] visited;
	}
	int totalWeight() {
		assert(!weight.empty());
		int total = 0;
		list<int>::iterator i;
		for (i = weight.begin(); i != weight.end(); ++i) {
			total += *i;
		}
		return total;
	}
};

int main()
{
	ifstream inFile;
	inFile.open("data.txt");
	if (!inFile) {
		cout << "File could not open." << endl;
	}
	else {
		int size;
		inFile >> size;
		Graph g(size);
		int n, v, w;
		w = 1;
		while (!inFile.eof()) {
			inFile >> v;
			inFile >> n;
			while (n != -999) {
				g.addEdge(v, n, w);
				inFile >> n;
				w++;
			}
		}
		cout << "Following is Breadth First Traversal " << endl;
		g.breadthFirstTraversal();
		cout << "\nTotal weight of graph is: " << g.totalWeight() << endl;
	}
	
}