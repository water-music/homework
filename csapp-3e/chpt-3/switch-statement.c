/* gcc -Og -S switch-statement.c
gcc -Og -c switch-statement.c
objdump -d switch-statement.o */
typedef enum
{
    MODE_A,
    MODE_B,
    MODE_C,
    MODE_D,
    MODE_E
} mode_t;

long switch3(long *p1, long *p2, mode_t action)
{
    long result = 0;
    switch (action)
    {
    case MODE_A:
        result = *p2;
        *p2 = *p1;
        break;

    case MODE_B:
        result = *p1;
        result += *p2;
        *p1 = result;
        break;

    case MODE_C:
        *p1 = 59;
        result = *p2;
        break;

    case MODE_D:
        *p1 = *p2;

    case MODE_E:
        result = 27;
        break;

    default:
        result = 12;
        break;
    }
    return result;
}

long switch_prod(long x, long n)
{
    long result = x;
    switch (n)
    {
    case 60:
    case 62:
        result <<= result;
        break;

    case 63:
        result >>= 3;
        break;

    case 64:
        result *= 15;
    case 65:
        result *= result;
    default:
        result += 75;
        break;
    }
    return result;
}