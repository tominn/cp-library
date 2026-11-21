struct Trie {
    struct Node {
        map<char,int> to;
        Node() {
        }
    };
    vector<Node> nodes;
    Trie() : nodes(1) {}
    void insert(const string& s) {
        int v = 0;
        for (char c : s) {
            if (!nodes[v].to.count(c)) {
                nodes[v].to[c] = (int)nodes.size();
                nodes.push_back(Node());
            }
            v = nodes[v].to[c];
        }
        return;
    }
    bool find(const string& s) {
        int v = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (nodes[v].to.count(s[i]) == 0) return false;
            v = nodes[v].to[s[i]];
        }
        return true;
    }
};
