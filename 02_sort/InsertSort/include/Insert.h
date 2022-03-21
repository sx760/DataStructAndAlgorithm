#ifndef INSERT_H
#define INSERT_H

template<class T>
class Insert
{
public:
    void sort(T* t, int n)
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = i; j > 0; j--)
            {
                if (greater(t[j - 1], t[j]))
                {
                    swap(t, j - 1, j);
                }
                else
                {
                    break;
                }
            }
        }
    }

    bool greater(const T& t1, const T& t2)
    {
        return t1 > t2;
    }

    void swap(T* t, int i, int j)
    {
        T temp;
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }

private:
};

#endif /* INSERT_H */
