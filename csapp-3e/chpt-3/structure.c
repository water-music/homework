/* gcc -O1 -S structure.c
gcc -Og -c structure.c
objdump -D structure.o */
#define A 9
#define B 5
#define CNT 7

/* 结构体 */
typedef struct
{
    long a[2];
    long *p;
} strA;

typedef struct
{
    long u[2];
    long q;
} strB;

typedef struct
{
    int x[A][B];
    long y;
} str1;

typedef struct
{
    char array[B];
    int t;
    short s[A];
    long u;
} str2;

typedef struct
{
    int idx;
    int x[4];
} a_struct;

typedef struct
{
    int first;
    a_struct a[CNT];
    int last;
} b_struct;

union ele
{
    struct
    {
        long *p;
        long y;
    } e1;
    struct
    {
        long x;
        union ele *next;
    } e2;
};

/* 函数 */
strB process(strA s)
{
    strB r;
    r.u[0] = s.a[1];
    r.u[1] = s.a[0];
    r.q = *s.p;
    return r;
}

long eval(long x, long y, long z)
{
    strA s;
    s.a[0] = x;
    s.a[1] = y;
    s.p = &z;
    strB r = process(s);
    return r.u[0] + r.u[1] + r.q;
}

void setVal(str1 *p, str2 *q)
{
    long v1 = q->t;
    long v2 = q->u;
    p->y = v1 + v2;
}

void test(long i, b_struct *bp)
{
    int n = bp->first + bp->last;
    a_struct *ap = &bp->a[i];
    ap->x[ap->idx] = n;
}

void proc(union ele *up)
{
    up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;
}