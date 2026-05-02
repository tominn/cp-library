using ll = long long;
using Hash = pair<ll, ll>;
struct RollingHash {
    const ll BASE1 = 100000007;
    const ll BASE2 = 100000009;
    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    vector<Hash> hash, pow;

    RollingHash(const string& s) {
        int n = (int)s.size();
        hash.assign(n + 1, {0, 0});
        pow.assign(n + 1, {1, 1});
        for (int i = 0; i < n; i++) {
            ll x = static_cast<unsigned char>(s[i]) + 1;
            hash[i + 1].first = (hash[i].first * BASE1 + x) % MOD1;
            hash[i + 1].second = (hash[i].second * BASE2 + x) % MOD2;
            pow[i + 1].first = (pow[i].first * BASE1) % MOD1;
            pow[i + 1].second = (pow[i].second * BASE2) % MOD2;
        }
        return;
    }

    // Returns the hash of the half-open interval [l, r).
    Hash get(int l, int r) const {
        ll h1 = (hash[r].first - (hash[l].first * pow[r - l].first % MOD1) + MOD1) % MOD1;
        ll h2 = (hash[r].second - (hash[l].second * pow[r - l].second % MOD2) + MOD2) % MOD2;
        return {h1, h2};
    }
};
