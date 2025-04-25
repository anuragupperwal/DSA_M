#include <iostream>
#include <bitset> // Optional, for easier output

int main() {
    int num = 10; // Example integer
    int numBits = sizeof(num) * 8; // Number of bits in an integer

    std::cout << "Integer: " << num << std::endl;
    std::cout << "Bits: ";

    for (int i = 0; i < numBits; ++i) {
        if (num & (1 << i)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }
    }
    std::cout << std::endl;

    // Using bitset for easier output (optional)
    std::cout << "Bits (using bitset): " << std::bitset<sizeof(num) * 8>(num) << std::endl;

    return 0;
}

// clang++ -o findBits findBits.cpp -stdlib=libc++ -isysroot $(xcrun --sdk macosx --show-sdk-path)
