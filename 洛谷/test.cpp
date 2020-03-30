#include <windows.h>

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

unsigned char __f[] = {0x8b, 0x44, 0x24, 0x04, 0xc7, 0x00, 0x01, 0x00,
                       0x00, 0x00, 0xc3, 0x90, 0x90, 0x90, 0x90, 0x90};

int main()
{
    LPVOID addressPointer = VirtualAlloc(NULL, sizeof(__f), 0x3000, 0x40);
    RtlMoveMemory(addressPointer, __f, sizeof(__f));
    int x = 2;
    ((void (*)(int *))addressPointer)(&x);
    printf("%d", x);
    return 0;
}
