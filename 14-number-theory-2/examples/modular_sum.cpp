#include <iostream>

using int64 = long long;
constexpr int64 MOD = 1'000'000'007;

// Inputs to the arithmetic helpers are normalized residues in [0, MOD).
int64 add_mod(int64 a, int64 b) {
    int64 s = a + b;
    if (s >= MOD) s -= MOD;
    return s;
}

int64 sub_mod(int64 a, int64 b) {
    int64 d = a - b;
    if (d < 0) d += MOD;
    return d;
}

int64 mul_mod(int64 a, int64 b) {
    return a * b % MOD; // Safe here: a,b < 1e9+7, product fits int64.
}

int64 pow_mod(int64 base, int64 exponent) {
    if (exponent == 0) return 1;
    if (exponent % 2 == 0) {
        return pow_mod(mul_mod(base, base), exponent / 2);
    }
    return mul_mod(base, pow_mod(base, exponent - 1));
}

int64 div_mod(int64 a, int64 b) {
    // MOD is prime and b must be nonzero modulo MOD.
    return mul_mod(a, pow_mod(b, MOD - 2));
}

int main() {
    int64 a, l, r;
    std::cin >> a >> l >> r;
    a %= MOD;
    if (a < 0) a += MOD;
    const int64 count = r - l + 1;

    if (a == 1) {
        std::cout << count % MOD << '\n';
        return 0;
    }

    const int64 first = pow_mod(a, l);
    const int64 numerator = sub_mod(1, pow_mod(a, count));
    const int64 denominator = sub_mod(1, a);
    const int64 answer = div_mod(mul_mod(first, numerator), denominator);
    std::cout << answer << '\n';
}
