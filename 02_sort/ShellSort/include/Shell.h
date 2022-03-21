#ifndef SHELL_H
#define SHELL_H

template<class T>
class Shell
{
public:
    static void sort(T *t, int n)
    {
        int h = 1;
        while (h < n / 2)
        {
            h = 2 * h + 1;
        }

        while (h >= 1)
        {
            for (int i = h; i < n; i++)
            {
                for (int j = i; j >= h; j -= h)
                {
                    if (greater(t[j - h], t[j]))
                    {
                        swap(t, j - h, j);
                    }
                    else
                    {
                        break;
                    }
                }
            }
            h /= 2;
        }
    }

    static bool greater(T t1, T t2)
    {
        return t1 > t2;
    }

    static void swap(T *t, int i, int j)
    {
        T temp;
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }
};

#endif /* SHELL_H */
