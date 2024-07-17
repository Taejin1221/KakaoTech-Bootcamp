#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using pis = pair<int, string>;

vector<pair<int, string>> adjList[1'001];

bool compare(pis& a, pis& b) {
    return a.second.compare(b.second) < 0;
}

int isIn(vector<pis>& directory, string& target) {
    for (pis& file : directory)
        if (file.second == target)
            return file.first;

    return -1;
}

void dfs(int curr, int level) {
    for(pis& adj : adjList[curr]) {
        for (int i = 0; i < level; i++)
            cout << ' ';
        cout << adj.second << '\n';
        dfs(adj.first, level + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int parent[1'001] = { 0, };
    int currDirectory = 0, adjIdx = 1;

    for (int i = 0; i < n; i++) {
        string oper;
        cin >> oper;

        if (oper == "mkdir") {
            string fileName;
            cin >> fileName;

            if (isIn(adjList[currDirectory], fileName) == -1) {
                adjList[currDirectory].push_back({adjIdx, fileName});
                parent[adjIdx++] = currDirectory;
            }
        } else if (oper == "cd") {
            string fileName;
            cin >> fileName;

            int nextDirectory = isIn(adjList[currDirectory], fileName);
            if (nextDirectory != -1)
                currDirectory = nextDirectory;
        } else if (oper == "cd..") {
            currDirectory = parent[currDirectory];
        }
    }

    for (int i = 0; i < adjIdx; i++)
        sort(adjList[i].begin(), adjList[i].end(), compare);

    cout << "root" << '\n';
    dfs(0, 1);

    return 0;
}