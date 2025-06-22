//Saisa Koirala
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define V 10 // Maximum number of vertices

// Implementation of traveling Salesman Problem
int travelingSalesmanProblem(int graph[][V], int s, int vertices)
{
    // Store all vertex apart from source vertex
    vector<int> vertex;
    for (int i = 0; i < vertices; i++)
    {
        if (i != s)
            vertex.push_back(i);
    }

    // Store minimum weight Hamiltonian Cycle.
    int min_path = INT_MAX;
    do
    {
        // Store current Path weight(cost)
        int current_pathweight = 0;
        // Compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        // Update minimum
        min_path = min(min_path, current_pathweight);
    } while (next_permutation(vertex.begin(), vertex.end()));
    return min_path;
}

// Driver program to test above function
int main()
{
    int vertices;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Matrix representation of graph
    int graph[V][V];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cin >> graph[i][j];
        }
    }

    int s;
    cout << "Enter the source vertex (0 to " << vertices - 1 << "): ";
    cin >> s;

    cout << "Minimum Cost: " << travelingSalesmanProblem(graph, s, vertices) << endl;

    return 0;
}
