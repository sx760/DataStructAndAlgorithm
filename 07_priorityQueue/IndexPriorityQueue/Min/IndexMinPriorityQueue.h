#ifndef INDEXMINPRIORITYQUEUE_H
#define INDEXMINPRIORITYQUEUE_H

template <class T>
class IndexMinPriorityQueue
{
public:
    IndexMinPriorityQueue(int capacity)
    {
        items_ = new T *[capacity + 1];
        pq_ = new int[capacity + 1];
        qp_ = new int[capacity + 1];
        size_ = 0;

        for (int i = 0; i < capacity + 1; i++)
        {
            qp_[i] = -1;
        }
    }
    ~IndexMinPriorityQueue()
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
        if (pq_ != nullptr)
        {
            delete[] pq_;
        }
        if (qp_ != nullptr)
        {
            delete[] qp_;
        }
    }

    int size() const { return size_; }

    bool isEmpty() const { return size_ == 0; }

    /**
     * @brief 插入元素, 并关联索引i
     * 
     * @param i 关联的索引
     * @param t 插入的元素
     */
    void insert(int i, T *t)
    {
        if (contains(i))
        {
            return;
        }

        size_++;
        items_[i] = t;
        pq_[size_] = i;
        qp_[i] = size_;

        swim(size_); // 使堆有序
    }

    /**
     * @brief 删除最小的元素, 返回该元素关联的索引
     * 
     * @return int 
     */
    int delMin()
    {
        int minIndex = pq_[1];
        swap(1, size_);
        qp_[pq_[size_]] = -1;
        pq_[size_] = -1;
        items_[minIndex] = nullptr;
        size_--;
        sink(1);

        return minIndex;
    }

    /**
     * @brief 是否存在k对应的元素
     * 
     * @param k 
     * @return true 
     * @return false 
     */
    bool contains(int k) const
    {
        return qp_[k] != -1;
    }

    /**
     * @brief 修改索引i关联的元素为t
     * 
     * @param i 
     * @param t 
     */
    void changeItem(int i, T *t)
    {
        items_[i] = t;
        // i在pq中的位置
        int k = qp_[i];
        sink(k);
        swim(k);
    }

    /**
     * @brief 最小元素关联的索引
     * 
     * @return int 
     */
    int minIndex()
    {
        return pq_[1];
    }

    /**
     * @brief 删除索引i关联的元素
     * 
     * @param i 
     */
    void del(int i)
    {
        int del = qp_[i];
        swap(del, size_);
        qp_[pq_[size_]] = -1;
        pq_[size_] = -1;
        items_[del] = nullptr;
        size_--;

        sink(del);
        swim(del);
    }

private:
    bool less(int i, int j) const
    {
        return *items_[pq_[i]] < *items_[pq_[j]];
    }

    void swap(int i, int j)
    {
        // pq_
        int temp = i;
        pq_[i] = pq_[j];
        pq_[j] = temp;

        // qp_
        qp_[pq_[i]] = i;
        qp_[pq_[j]] = j;
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
    T **items_; // 存储元素, 根节点从索引为1
    int *pq_;   // 储存元素的索引, 需要堆有序
    int *qp_;   // 储存pq_的逆序, pq_的值为索引, pq_的索引为值
    int size_;
};

#endif /* INDEXMINPRIORITYQUEUE_H */
