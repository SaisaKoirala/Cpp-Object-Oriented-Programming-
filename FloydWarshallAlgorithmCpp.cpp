#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floyds(vector<vector<int>>& b, int V);

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> b(V, vector<int>(V));
    cout << "ENTER VALUES OF ADJACENCY MATRIX (-1 for infinity):\n\n";
    for (int i = 0; i < V; i++) {
        cout << "Enter values for row " << (i + 1) << ":\n";
        for (int j = 0; j < V; j++) {
            cin >> b[i][j];
            if (b[i][j] == -1)
                b[i][j] = INT_MAX; // Set infinity where the input is -1
        }
    }
    floyds(b, V);
    return 0;
}

void floyds(vector<vector<int>>& b, int V) {
    int i, j, k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (b[i][k] != INT_MAX && b[k][j] != INT_MAX && (i != j)) {
                    if (b[i][k] + b[k][j] < b[i][j]) {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }

    for (i = 0; i < V; i++) {
        cout << "Minimum Cost With Respect to Node: " << i<<endl;
        for (j = 0; j < V; j++) {
            if (b[i][j] == INT_MAX)
                cout << "INF\t";
            else
                cout << b[i][j] << "\t";
        }
        cout << endl;
    }
}
