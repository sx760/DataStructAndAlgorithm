#ifndef MERGE_H
#define MERGE_H

/**
 * @brief 归并排序
 * 
 * @tparam T 
 */
template <class T>
class Merge
{
public:
    Merge(int n)
    {
        assist_ = new T[n];
    }
    ~Merge()
    {
        if (assist_ != nullptr)
        {
            delete[] assist_;
        }
    }

    void sort(T *t, int n)
    {
        int lo = 0, hi = n - 1;
        sort(t, lo, hi);
    }

    void sort(T *t, int lo, int hi)
    {
        if (hi <= lo)
        {
            return;
        }

        int mid = lo + (hi - lo) / 2;
        sort(t, lo, mid);
        sort(t, mid + 1, hi);
        merge(t, lo, mid, hi);
    }

    void merge(T *t, int lo, int mid, int hi)
    {
        int i = lo, p1 = lo, p2 = mid + 1;

        while (p1 <= mid && p2 <= hi)
        {
            if (less(t[p1], t[p2]))
            {
                assist_[i++] = t[p1++];
            }
            else
            {
                assist_[i++] = t[p2++];
            }
        }

        while (p1 <= mid)
        {
            assist_[i++] = t[p1++];
        }
        while (p2 <= hi)
        {
            assist_[i++] = t[p2++];
        }

        for (int index = lo; index <= hi; index++)
        {
            t[index] = assist_[index];
        }    
    }

    bool less(const T &t1, const T &t2)
    {
        return t1 < t2;
    }

    void swap(T *t, int i, int j)
    {
        T temp;
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }

private:
    T *assist_;
};

#endif /* MERGE_H */
