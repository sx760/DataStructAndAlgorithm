#ifndef FACTORIAL_H
#define FACTORIAL_H

inline long long factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

#endif /* FACTORIAL_H */
