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
  }
};
