#include <iostream>
#include <map>

using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long d = 2; d <= n / d; ++d) {
        if (n % d == 0) return false;
    }
    return true;
}

map<long long, int> factorize(long long n) {
    map<long long, int> factors;
    for (long long d = 2; d <= n / d; ++d) {
        while (n % d == 0) {
            ++factors[d];
            n /= d;
        }
    }
    if (n > 1) ++factors[n];
    return factors;
}

long long divisor_count(const map<long long, int>& factors) {
    long long count = 1;
    for (const auto& [prime, exponent] : factors) {
        (void)prime;
        count *= exponent + 1;
    }
    return count;
}

long long gcd_euclid(long long a, long long b) {
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

long long mod(long long x, long long p) {
    long long remainder = x % p;
    if (remainder < 0) remainder += p;
    return remainder;
}

int main() {
    long long n, a, b, p;
    if (!(cin >> n >> a >> b >> p)) return 0;
    if (n < 1 || n > 1000000000LL || a < 1 || a > 1000000000LL ||
        b < 1 || b > 1000000000LL || p < 1 || p > 1000000000LL) {
        cerr << "Expected 1 <= n, a, b, p <= 10^9\n";
        return 1;
    }

    cout << (is_prime(n) ? "PRIME" : "COMPOSITE") << '\n';

    auto factors = factorize(n);
    if (factors.empty()) {
        cout << "1";
    } else {
        bool first = true;
        for (const auto& [prime, exponent] : factors) {
            if (!first) cout << ' ';
            cout << prime << '^' << exponent;
            first = false;
        }
    }
    cout << '\n' << divisor_count(factors) << '\n';

    long long g = gcd_euclid(a, b);
    long long l = a / g * b;
    cout << g << ' ' << l << '\n';
    cout << mod(a + b, p) << ' ' << mod(a - b, p) << ' ' << mod(a * b, p) << '\n';
}
