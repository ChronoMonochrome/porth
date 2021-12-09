#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define BUF_CAP 32

__attribute__((noinline)) uint64_t div10(uint64_t x) {
    return x / 10;
}

void dump(uint64_t x)
{
    char buf[BUF_CAP];
    size_t buf_sz = 1;

    buf[sizeof(buf) - buf_sz] = '\n';
    do {
        buf[sizeof(buf) - buf_sz - 1] = x % 10 + '0';
	buf_sz++;
        x = div10(x);
    } while (x);

    write(1, &buf[sizeof(buf) - buf_sz], buf_sz);
}

int main()
{
    dump(18446744073709551615);
    return 0;
}
