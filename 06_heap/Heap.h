#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap
{
public:
    Heap(int capacity)
    {
        items_ = new T *[capacity + 1];
        size_ = 0;
    }
    ~Heap()
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

    T *delMax()
    {
        T *max = items_[1];
        swap(1, size_);
        //swap(1, size_);
        //items_[size_--] = nullptr;
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

    /**
     * @brief 上浮算法使索引k处元素位于正确的位置
     * 
     * @param k 索引
     */
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

    /**
     * @brief 下沉算法使索引k处元素位于正确的位置
     * 
     * @param k 索引
     */
    void sink(int k)
    {
        while (k * 2 <= size_)
        {
            int max = k * 2; // 子节点中较大的节点
            if (k * 2 + 1 <= size_) // 有右子节点
            {
                if (less(k * 2, k * 2 + 1))
                {
                    max = k * 2 + 1;
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
    T **items_;
    int size_; // 根节点索引为1
};
#endif /* HEAP_H */
