#ifndef MAXPRIORITYQUEUE_H
#define MAXPRIORITYQUEUE_H

/**
 * @brief 最大优先队列
 * 
 * @tparam T 
 */
template <class T>
class MaxPriorityQueue
{
public:
    MaxPriorityQueue(int capacity)
    {
        items_ = new T *[capacity + 1];
        size_ = 0;
    }
    ~MaxPriorityQueue()
    {
        if (items_ != nullptr)
        {
            for (int i = 0; i < size_ + 1; i++)
            {
                if (items_[i] != nullptr)
                {
                    delete items_[i];
                    items_[i] = nullptr;
                }
            }
            delete[] items_;
            items_ = nullptr;
        }
    }

    int size() const { return size_; }

    bool isEmpty() const { return size_ == 0; }

    T *delMax()
    {
        T *max = items_[1];
        swap(1, size_--);
        sink(1);
        return max;
    }

    void insert(T *t)
    {
        items_[++size_] = t;
        swim(size_);
    }

private:
    bool less(int i, int j) const
    {
        return *items_[i] < *items_[j];
    }

    void swap(int i, int j)
    {
        T *temp = items_[i];
        items_[i] = items_[j];
        items_[j] = temp;
    }

    void swim(int k)
    {
        while (k > 1)
        {
            if (less((int)k / 2, k))
            {
                swap((int)k / 2, k);
            }
            k = (int)k / 2;
        }
    }

    void sink(int k)
    {
        while (k * 2 <= size_)
        {
            int max = k * 2;
            if (max + 1 <= size_)
            {
                if (less(max, max + 1))
                {
                    max = max + 1;
                }
            }

            if (!less(k, max))
            {
                break;
            }
            swap(k, max);
            k = max;
        }
    }

private:
    T **items_; // 根节点索引为1
    int size_;
};

#endif /* MAXPRIORITYQUEUE_H */
