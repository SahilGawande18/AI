#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 4;

struct Node {
    vector<int> queens;
    int g; // cost from start
    int h; // heuristic cost to goal

    Node() : g(0), h(0) {
        queens.resize(N);
        for (int i = 0; i < N; ++i) {
            queens[i] = -1;
        }
    }

    int f() const {
        return g + h;
    }
};

// Helper function to calculate heuristic cost
int heuristic(const Node& node) {
    int attacks = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (node.queens[i] == node.queens[j] || abs(i - j) == abs(node.queens[i] - node.queens[j])) {
                attacks++;
            }
        }
    }
    return attacks;
}

// A* algorithm to find solution
Node aStar(const Node& initialNode) {
    vector<Node> openSet;
    openSet.push_back(initialNode);

    while (!openSet.empty()) {
        // Find node with lowest f value
        int minFIndex = 0;
        for (int i = 1; i < openSet.size(); ++i) {
            if (openSet[i].f() < openSet[minFIndex].f())
                minFIndex = i;
        }

        Node current = openSet[minFIndex];
        openSet.erase(openSet.begin() + minFIndex);

        // Check if current node is a terminal state
        if (current.g == N) {
            return current;
        }

        // Generate possible moves and add to open set
        for (int i = 0; i < N; ++i) {
            if (current.queens[i] == -1) {
                Node next = current;
                next.queens[i] = current.g; // Place queen in this row
                next.g++;
                next.h = heuristic(next);
                openSet.push_back(next);
            }
        }
    }

    // If no solution found, return the initial node
    return initialNode;
}

// Helper function to print the board
void printBoard(const Node& node) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << (node.queens[i] == j ? 'Q' : '-') << " ";
        }
        cout << endl;
    }
}

int main() {
    Node initialNode;

    // Find solution
    Node solution = aStar(initialNode);

    cout << "Solution:" << endl;
    printBoard(solution);

    return 0;
}