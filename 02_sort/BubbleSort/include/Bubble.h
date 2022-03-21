#ifndef BUBBLE_H
#define BUBBLE_H

template<class T>
class Bubble
{
public:
    void sort(T* t, int n)
    {
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (greater(t[j], t[j + 1]))
                {
                    swap(t, j, j + 1);
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

#endif /* BUBBLE_H */
