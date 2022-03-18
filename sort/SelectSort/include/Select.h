#ifndef SELECT_H
#define SELECT_H

template <class T>
class Select
{
public:
    void sort(T *t, int n)
    {
        for (int i = 0; i <= n - 2; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (greater(t[minIndex], t[j]))
                {
                    minIndex = j;
                }
            }
            swap(t, i, minIndex);
        }
    }

    bool greater(T t1, T t2)
    {
        return t1 > t2;
    }

    void swap(T *t, int i, int j)
    {
        T temp;
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }

private:
};

#endif /* SELECT_H */
