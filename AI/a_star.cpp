#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

const string GOAL_STATE = "12345678_";

struct Node {
    string state;
    int level;
    int fval;

    Node(const string &state, int level, int fval) : state(state), level(level), fval(fval) {}

    // Generate child nodes by moving the blank space
    vector<Node> generate_child() {
        vector<Node> children;
        int blankIndex = state.find('_');
        vector<int> moves = {1, -1, 3, -3}; // right, left, down, up

        for (int move : moves) {
            int newIndex = blankIndex + move;
            if (newIndex >= 0 && newIndex < 9 && !(blankIndex == 2 && move == 1) && !(blankIndex == 5 && move == -1)) {
                string newState = state;
                swap(newState[blankIndex], newState[newIndex]);
                children.push_back(Node(newState, level + 1, 0));
            }
        }

        return children;
    }
};

struct Puzzle {
    unordered_map<string, int> gval;
    vector<Node> open;
    vector<Node> closed;

    int h(const string &state) {
        int temp = 0;
        for (int i = 0; i < 9; ++i) {
            if (state[i] != '_' && state[i] != GOAL_STATE[i]) {
                temp++;
            }
        }
        return temp;
    }

    int f(const Node &node) {
        return node.level + h(node.state);
    }

    void process(const string &start_state) {
        Node start(start_state, 0, 0);
        start.fval = f(start);
        open.push_back(start);

        while (!open.empty()) {
            auto cur = open.front();

            if (cur.state == GOAL_STATE) {
                cout << "Goal state reached in " << cur.level << " moves." << endl;
                break;
            }

            auto children = cur.generate_child();
            for (auto &child : children) {
                child.fval = f(child);
                if (gval.find(child.state) == gval.end() || child.level < gval[child.state]) {
                    gval[child.state] = child.level;
                    open.push_back(child);
                }
            }

            closed.push_back(cur);
            open.erase(open.begin());

            sort(open.begin(), open.end(), [](const Node &a, const Node &b) {
                return a.fval < b.fval;
            });
        }
    }
};

int main() {
    string start_state;
    cout << "Enter the start state (use '_' for blank space): ";
    cin >> start_state;

    Puzzle puz;
    puz.process(start_state);

    return 0;
}
