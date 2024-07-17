// Prob3.cpp
#include <iostream>

#include <queue>
#include <vector>

using namespace std;

struct Node {
    int vertex, cost;
    Node(int v, int c): vertex(v), cost(c) { }
    bool operator<(const Node& n2) const {
        return cost > n2.cost;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int start, end, people;
    cin >> start >> end >> people;

    vector<Node> adjList[200'001];
    for (int i = 0; i < m; i++) {
        int v, u, maxPeople;
        cin >> v >> u >> maxPeople;

        int cost = people / maxPeople + (people % maxPeople != 0 ? 1 : 0);
        adjList[v].push_back(Node(u, cost));
        adjList[u].push_back(Node(v, cost));
    }

    priority_queue<Node> pq;
    bool visited[200'001] = { false, };

    int ans = -1;
    pq.push(Node(start, 0));
    while (!pq.empty()) {
        Node curr = pq.top(); pq.pop();

        if (curr.vertex == end) {
            ans = curr.cost;
            break;
        }

        if (!visited[curr.vertex]) {
            visited[curr.vertex] = true;

            for (Node& adj : adjList[curr.vertex]) {
                if (!visited[adj.vertex])
                    pq.push(Node(adj.vertex, curr.cost + adj.cost));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}