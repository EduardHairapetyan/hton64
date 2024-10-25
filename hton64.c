#include <stdint.h>
#include <stdio.h>

struct Int64 {
    uint8_t bytes[8];
};

// Macro for swapping two bytes
// Should be a functionm,written as macro for learning porpuses only.
#define SWAP(a, b) do { uint8_t temp = (a); (a) = (b); (b) = temp; } while(0)

uint64_t htons64(uint64_t value) {
    struct Int64 data;
    *(uint64_t*)data.bytes = value;

    SWAP(data.bytes[0], data.bytes[7]);
    SWAP(data.bytes[1], data.bytes[6]);
    SWAP(data.bytes[2], data.bytes[5]);
    SWAP(data.bytes[3], data.bytes[4]);

    return *(uint64_t*)data.bytes;
}

int main() {
    uint64_t original = 0x1122334455667780;
    uint64_t converted = htons64(original);

    printf("Original: 0x%llx\n", original);
    printf("Converted: 0x%llx\n", converted);

    return 0;
}
