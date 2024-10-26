#include <stdio.h>
#include <stdint.h>

typedef union _LARGE_INTEGER {
    struct {
        char b0;
        char b1;
        char b2;
        char b3;
        char b4;
        char b5;
        char b6;
        char b7;
    };
    uint64_t value;
} LARGE_INTEGER;

// Function to convert 64-bit integer from host to network byte order
uint64_t hton64(uint64_t host_value) {
    LARGE_INTEGER li;
    li.value = host_value;

    // Swap bytes manually to convert to network byte order (big-endian)
    char temp;
    temp = li.b0; li.b0 = li.b7; li.b7 = temp;
    temp = li.b1; li.b1 = li.b6; li.b6 = temp;
    temp = li.b2; li.b2 = li.b5; li.b5 = temp;
    temp = li.b3; li.b3 = li.b4; li.b4 = temp;

    return li.value;
}

int main() {
    uint64_t num = 0x0123456789ABCDEF;
    uint64_t network_order = hton64(num);

    printf("Original: 0x%016llx\n", num);
    printf("Network order: 0x%016llx\n", network_order);

    return 0;
}
