struct WeightedUnionFind {
    vector<int> parent, rank;
    vector<ll> diff_weight;

    WeightedUnionFind(int n): parent(n, -1), rank(n, 1), diff_weight(n) {}

    int find(int a) {
        if (parent[a] == -1) {
            return a;
        } else {
            int root = find(parent[a]);
            diff_weight[a] += diff_weight[parent[a]];
            return parent[a] = root;
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    bool merge(int a, int b, ll w) {
        // b --(+w)--> a
        w += weight(a); w -= weight(b);   
        a = find(a), b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) {
            parent[a] = b;
            diff_weight[a] = -w;
            rank[b] += rank[a];
        } else {
            parent[b] = a;
            diff_weight[b] = w;
            rank[a] += rank[b];
        }
        return true;
    }

    ll weight(int a) {
        find(a);
        return diff_weight[a];
    }

    ll diff(int a, int b) {
        // b -> a
        return weight(b) - weight(a);
    }
};
