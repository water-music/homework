typedef unsigned float_bits;

/**
 * @brief 将32位浮点数转换为int
 *
 * @param f
 * @return int
 */
int float_f2i(float_bits f)
{
    unsigned exp = f >> 23 & 0xff;
    if (exp < 127)
    {
        /* 若阶码小于0，则直接返回0 */
        return 0;
    }
    if (exp > 158)
    {
        /* 若阶码大于31，则直接返回特殊值 */
        return (int)0x80000000u;
    }
    unsigned sign = f >> 31;
    unsigned frac = f & 0x7fffff;
    unsigned val = (0x80000000u + (frac << 8)) >> (158 - exp);
    if (sign)
    {
        /* 值为负 */
        return val > 0x80000000u ? (int)0x80000000u : -(int)val;
    }
    else
    {
        /* 值为正 */
        return val > 0x7FFFFFFF ? (int)0x80000000u : (int)val;
    }
}

/**
 * @brief 计算0.5 * f
 *
 * @param f
 * @return float_bits
 */
float_bits float_half(float_bits f)
{
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned roundup = (f & 3) == 3; /* 默认向偶数舍入 */
    if (!exp)
    {
        // 非规格数
        frac = (frac >> 1) + roundup;
    }
    else if (exp < 0xff)
    {
        // 规格数
        exp--;
        if (!exp)
        {
            frac = (frac >> 1) + roundup + 0x400000; /* 考虑隐含前导1 */
        }
    }
    else
    {
        // 非数字或无穷大
        return f;
    }
    return (f & (1 << 31)) | (exp << 23) | frac;
}

/**
 * @brief 将int转换为32位浮点数
 *
 * @param i
 * @return float_bits
 */
float_bits float_i2f(int i)
{
    if (!i)
    {
        /* 非规格数 */
        return (float_bits)0;
    }
    unsigned sign = i >> 31;
    unsigned exp = 158;
    unsigned frac;
    unsigned absolute_i = sign ? -i : i;
    unsigned mask = 1 << 31;
    unsigned residue; /* 转换为尾数时会被去除的部分(舍入) */
    /* 规格数(考虑隐含前导1) */
    while (!(mask & absolute_i))
    {
        /* 将首个1移到最高位，转换时第0~7位将会去除(舍入)，8~30位将会作为尾数，第31位将作为隐含前导1 */
        exp--;
        absolute_i = absolute_i << 1;
    }
    residue = absolute_i & 0xff;
    frac = (absolute_i >> 8) & 0x7fffff;
    if (residue > 0x80 || (residue == 0x80 && (frac & 1)))
    {
        /* 默认向偶数舍入 */
        frac++;
        if (frac > 0x7fffff)
        {
            frac = (frac & 0x7fffff) >> 1;
            exp++;
        }
    }
    return (i << 31) | (exp << 23) | frac;
}

/**
 * @brief 计算2 * f
 *
 * @param f
 * @return float_bits
 */
float_bits float_twice(float_bits f)
{
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if (!exp)
    {
        // 非规格数(若尾数乘2会溢出，则转换为规格数。否则，直接将尾数乘2)
        if (frac >> 22)
        {
            exp = 1;
        }
        else
        {
            frac = frac << 1;
        }
    }
    else if (exp < 0xff)
    {
        // 规格数(若阶码全为1，则转换为无穷大)
        exp++;
        if (exp == 0xff)
        {
            frac = 0;
        }
    }
    else
    {
        // 非数字或无穷大
        return f;
    }
    return (f & (1 << 31)) | (exp << 23) | frac;
}