/* gcc -Og -S cread.c */
long cread(long *xp)
{
    return (xp ? *xp : 0);
}

long cread_alt(long *xp)
{
    long zero = 0l;
    if (!xp)
    {
        xp = &zero;
    }
    return *xp;
}