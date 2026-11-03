#include <cstdint>
#include <iostream>

int main() {
    std::uint32_t a, i, k;
    std::cin >> a >> i >> k;
    if (a > 255 || i >= 8 || k > 8) return 1;

    for (int bit = 7; bit >= 0; --bit) {
        std::cout << ((a >> bit) & 1u);
    }
    std::cout << '\n';

    const std::uint32_t one_bit = 1u << i;
    const std::uint32_t low_bits = (1u << k) - 1u;
    std::cout << "set " << (a | one_bit) << '\n';
    std::cout << "clear " << (a & ~one_bit) << '\n';
    std::cout << "test " << ((a >> i) & 1u) << '\n';
    std::cout << "toggle " << (a ^ one_bit) << '\n';
    std::cout << "clear_low " << (a & ~low_bits) << '\n';
    std::cout << "keep_low " << (a & low_bits) << '\n';
}
