#include "integer-functions.c"
#include "float-functions.c"
#include "show-bytes.c"

int main(int argc, char const *argv[])
{
    char little_endian_flag = is_little_endian();
    /* int i = 12345;
    test_show_bytes(i, little_endian_flag); */

    /* unsigned b = 0x11e;
    printf("%d\n", odd_ones(b)); */

    /* unsigned c = 0xff00;
    show_unsigned(leftmost_one(c)); */

    /* unsigned c = 1 << 30;
    printf("%u\n", rotate_left(c, 1)); */

    /* int x = 12;
    printf("%d\n", threefourths(x)); */

    /* float_bits f = 0x4080f001; */
    /* show_unsigned(float_twice(f), little_endian_flag); */
    /* show_unsigned(float_half(f), little_endian_flag); */
    /* show_int(float_f2i(f), little_endian_flag); */
    int i = ~(1 << 31);
    show_unsigned(float_i2f(i), little_endian_flag);
    return 0;
}