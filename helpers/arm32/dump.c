#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define BUF_CAP 33

// https://stackoverflow.com/questions/5558492/divide-by-10-using-bit-shifts
inline int32_t div10(int32_t dividend)
{
    int64_t invDivisor = 0x1999999A;
    return (int32_t) ((invDivisor * dividend) >> 32);
}

void dump(int32_t x)
{
    int sign = x < 0;
    char buf[BUF_CAP];

    size_t buf_sz = 1;

    if (sign)
        x = abs(x);

    buf[sizeof(buf) - buf_sz] = '\n';
    do {
        buf[sizeof(buf) - buf_sz - 1] = x % 10 + '0';
	buf_sz++;
        x = div10(x);
    } while (x);

    if (sign)
        buf[sizeof(buf) - buf_sz - sign] = '-';

    write(1, &buf[sizeof(buf) - buf_sz - sign], buf_sz + sign);
}

int main()
{
    dump(19);
    return 0;
}
