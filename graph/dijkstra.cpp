#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<long long> dijkstra(const vector<vector<pair<int, int>>>& graph, int start) {
    const long long INF = 1e18;
    int n = graph.size();
    vector<long long> dist(n, INF);
    dist[start] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (d > dist[v]) continue;
        for (auto& edge : graph[v]) {
            long long nd = d + edge.second;
            if (nd < dist[edge.first]) {
                dist[edge.first] = nd;
                pq.emplace(nd, edge.first);
            }
        }
    }
    return dist;
}
int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        x--;
        graph[i].emplace_back(i + 1, a);
        graph[i].emplace_back(x, b);
    }
    vector<long long> dist = dijkstra(graph, 0);
    cout << dist[n - 1] << endl;
    return 0;
}
