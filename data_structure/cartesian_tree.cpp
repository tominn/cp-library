struct CartesianTree {
    int n, root;
    vector<int> p, l, r;
    CartesianTree(const vector<int>& a) {
        n = (int)a.size();
        p = l = r = vector<int>(n, -1);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            int c = -1;
            while (!st.empty() && a[i] < a[st.back()]) {
                c = st.back(); st.pop_back();
            }
            if (c != -1) {
                l[i] = c;
                p[c] = i;
            }
            if (!st.empty()) {
                p[i] = st.back();
                r[st.back()] = i;
            }
            st.push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (p[i] == -1) root = i;
        }
    }
};
