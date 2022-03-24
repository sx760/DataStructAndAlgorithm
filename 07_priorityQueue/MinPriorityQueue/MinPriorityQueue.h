#ifndef MINPRIORITYQUEUE_H
#define MINPRIORITYQUEUE_H

/**
 * @brief 最小优先队列
 * 
 * @tparam T 
 */
template <class T>
class MinPriorityQueue
{
public:
    MinPriorityQueue(int capacity)
    {
        items_ = new T *[capacity];
        size_ = 0;
    }
    ~MinPriorityQueue()
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

    void insert(T *t)
    {
        items_[++size_] = t;
        swim(size_);
    }

    T *delMin()
    {
        T *min = items_[1];
        swap(1, size_--);
        sink(1);
        return min;
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
            if (less(k, (int)k / 2))
            {
                swap(k, (int)k / 2);
            }
            k = (int)k / 2;
        }
    }

    void sink(int k)
    {
        while (k * 2 <= size_)
        {
            int min = k * 2;
            if (min + 1 <= size_)
            {
                if (less(min + 1, min))
                {
                    min = min + 1;
                }
            }
            
            if (less(k, min))
            {
                break;
            }
            swap(k, min);
            k = min;
        }
    }

private:
    T **items_; // 根节点索引为1
    int size_;
};

#endif /* MINPRIORITYQUEUE_H */
