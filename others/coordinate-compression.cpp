template <typename T>
struct CC {
    vector<T> xs;
    void add(const T& x) {
        xs.push_back(x);
    }
    void build() {
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
    }
    int get(const T& x) const {
        return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
    }
    int size() const {
        return (int)xs.size();
    }
};
