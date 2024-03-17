#include <stdio.h>

typedef unsigned char *byte_pointer;

/**
 * @brief 判断是否是小端
 *
 * @return char 1表示小端，0表示大端
 */
char is_little_endian()
{
    short x = 1;
    return (char)(*(char *)&x);
}

/**
 * @brief 打印对象的字节表示(大端)
 *
 * @param start 对象指针
 * @param len 对象长度
 * @param little_endian_flag 1表示小端，0表示大端
 */
void show_bytes(byte_pointer start, size_t len, char little_endian_flag)
{
    if (little_endian_flag)
    {
        for (size_t i = 0; i < len; i++)
        {
            printf("%.2x", start[len - i - 1]);
        }
    }
    else
    {
        for (size_t i = 0; i < len; i++)
        {
            printf("%.2x", start[i]);
        }
    }
    printf("\n");
}

/**
 * @brief 打印short的字节表示
 *
 * @param x
 * @param little_endian_flag 1表示小端，0表示大端
 */
void show_short(short x, char little_endian_flag)
{
    show_bytes((byte_pointer)&x, sizeof(short), little_endian_flag);
}

/**
 * @brief 打印int的字节表示
 *
 * @param x
 * @param little_endian_flag 1表示小端，0表示大端
 */
void show_int(int x, char little_endian_flag)
{
    show_bytes((byte_pointer)&x, sizeof(int), little_endian_flag);
}

/**
 * @brief 打印long的字节表示
 *
 * @param x
 * @param little_endian_flag 1表示小端，0表示大端
 */
void show_long(long x, char little_endian_flag)
{
    show_bytes((byte_pointer)&x, sizeof(long), little_endian_flag);
}

/**
 * @brief 打印unsigned的字节表示
 *
 * @param x
 * @param little_endian_flag 1表示小端，0表示大端
 */
void show_unsigned(unsigned x, char little_endian_flag)
{
    show_bytes((byte_pointer)&x, sizeof(unsigned), little_endian_flag);
}

/**
 * @brief 打印float的字节表示
 *
 * @param x
 * @param little_endian_flag 1表示小端，0表示大端
 */
void show_float(float x, char little_endian_flag)
{
    show_bytes((byte_pointer)&x, sizeof(float), little_endian_flag);
}

/**
 * @brief 打印double的字节表示
 *
 * @param x
 * @param little_endian_flag 1表示小端，0表示大端
 */
void show_double(double x, char little_endian_flag)
{
    show_bytes((byte_pointer)&x, sizeof(double), little_endian_flag);
}

/**
 * @brief 打印指针的字节表示
 *
 * @param x
 * @param little_endian_flag 1表示小端，0表示大端
 */
void show_pointer(void *x, char little_endian_flag)
{
    show_bytes((byte_pointer)&x, sizeof(void *), little_endian_flag);
}

/**
 * @brief 测试函数
 *
 * @param val
 * @param little_endian_flag 1表示小端，0表示大端
 */
void test_show_bytes(int val, char little_endian_flag)
{
    int ival = val;
    short sval = (short)ival;
    long lval = (long)ival;
    float fval = (float)ival;
    double dval = (double)ival;
    int *pval = &ival;
    show_short(sval, little_endian_flag);
    show_int(ival, little_endian_flag);
    show_long(lval, little_endian_flag);
    show_float(fval, little_endian_flag);
    show_double(dval, little_endian_flag);
    show_pointer(pval, little_endian_flag);
};