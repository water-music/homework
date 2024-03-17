/**
 * @brief 将无符号数的位模式中的首个1后所有位置0
 *
 * @param x
 * @return int
 */
int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x ^ (x >> 1);
}

/**
 * @brief 若参数中有奇数个1则返回1，否则，返回0
 *
 * @param x
 * @return int
 */
int odd_ones(unsigned x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

/**
 * @brief 循环左移
 *
 * @param x
 * @param n 左移位数，范围是[0,32)
 * @return unsigned
 */
unsigned rotate_left(unsigned x, int n)
{
    unsigned mask = (2 << ((sizeof(int) << 3) - 1 - n)) - 1;
    return ((x & ~mask) >> ((sizeof(int) << 3) - n)) | ((x & mask) << n);
}

/**
 * @brief x * 3 / 4(向0舍入，不会溢出)
 *
 * @param x
 * @return int
 */
int threefourths(int x)
{
    /* 单独计算最低位的舍入，其他位都是通过右移1位加右移2位来计算 */
    int l2 = x & 3;
    int l1 = (x & 1) << 1;
    int bias = x >> ((sizeof(int) << 3) - 1) & 3;
    int incr = (l2 + l1 + bias) >> 2;
    return (x >> 2) + (x >> 1) + incr;
}