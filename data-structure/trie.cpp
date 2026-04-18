struct Trie {
    struct Node {
        map<char,int> to;
        Node() {
        }
    };
    vector<Node> d;
    Trie() {
        d.push_back(Node());
    }
    void insert(const string& s) {
        int v = 0;
        for (char c : s) {
            if (!d[v].to.count(c)) {
                d[v].to[c] = (int)d.size();
                d.push_back(Node());
            }
            v = d[v].to[c];
        }
        return;
    }
    bool find(const string& s) {
        int v = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (d[v].to.count(s[i]) == 0) return false;
            v = d[v].to[s[i]];
        }
        return true;
    }
};
