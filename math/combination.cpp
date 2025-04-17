struct Combination {
    int MAX;
    vector<mint> fact, fact_inv, inv;

    Combination(int MAX): MAX(MAX) {
        fact.resize(MAX);
        fact_inv.resize(MAX);
        inv.resize(MAX);
        Build();
    }

    void Build() {
        const int MOD = mint::mod();
        fact[0] = fact[1] = 1;
        fact_inv[0] = fact_inv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++){
            fact[i] = fact[i - 1] * i;
            inv[i] = MOD - inv[MOD % i] * (MOD / i);
            fact_inv[i] = fact_inv[i - 1] * inv[i];
        }
    }

    mint c(int n, int k) {
        if (k < 0 || n < k) return 0;
        return fact[n] * fact_inv[k] * fact_inv[n - k];
    }

    mint p(int n, int k) {
        return fact[n] * fact_inv[n - k];
    }
};
