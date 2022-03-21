#ifndef QUICK_H
#define QUICK_H

/**
 * @brief 快速排序
 * 
 * @tparam T 
 */
template <class T>
class Quick
{
public:
    static void sort(T *t, int n)
    {
        int lo = 0, hi = n - 1;
        sort(t, lo, hi);
    }

    static void sort(T *t, int lo, int hi)
    {
        if (hi <= lo) 
        {
            return;
        }

        int par = partition(t, lo, hi);
        sort(t, lo, par - 1);
        sort(t, par + 1, hi);
    }

    static int partition(T *t, int lo, int hi)
    {
        T key = t[lo];
        int left = lo, right = hi + 1;

        while (true)
        {
            while (less(key, t[--right]))
            {
                if (right == lo)
                {
                    break;
                }
            }
            
            while (less(t[++left], key))
            {
                if (left == hi)
                {
                    break;
                }
            }
            
            if (left >= right)
            {
                break;
            }
            else
            {
                swap(t, left, right);
            }
        }

        swap(t, lo, right);
        return right;
    }

    static bool less(const T &t1, const T &t2)
    {
        return t1 < t2;
    }

    static void swap(T *t, int i, int j)
    {
        T temp;
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }

};

#endif /* QUICK_H */
