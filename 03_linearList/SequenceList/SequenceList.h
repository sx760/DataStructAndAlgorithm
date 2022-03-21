#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

/**
 * @brief 顺序表
 * 
 * @tparam T 
 */
template <class T>
class SequenceList
{
public:
    SequenceList(int capacity)
    {
        capacity_ = capacity;
        eles_ = new T[capacity];
        n_ = 0;
    }
    ~SequenceList()
    {
        if (eles_ != nullptr)
        {
            delete[] eles_;
        }
    }

    void clear()
    {
        n_ = 0;
    }

    bool isEmpty() const
    {
        return n_ == 0;
    }

    int length() const
    {
        return n_;
    }

    T get(int index) const
    {
        return eles_[index];
    }

    void insert(const T &t)
    {
        if (n_ == capacity_)
        {
            resize(capacity_ * 2);
        }

        eles_[n_++] = t;
    }

    void insert(int index, const T &t)
    {
        if (n_ == capacity_)
        {
            resize(capacity_ * 2);
        }
        for (int i = n_; i > index; i--)
        {
            eles_[i] = eles_[i - 1];
        }
        eles_[index] = t;
        n_++;
    }

    T remove(int index)
    {
        T current = eles_[index];
        for (int i = index; i < n_ - 1; i++)
        {
            eles_[i] = eles_[i + 1];
        }
        n_--;

        if (n_ < capacity_ / 4)
        {
            resize(capacity_ / 2);
        }

        return current;
    }

    int indexOf(const T &t)
    {
        for (int i = 0; i < n_; i++)
        {
            if (eles_[i] == t)
            {
                return i;
            }
        }
        return -1;
    }

    void resize(int newSize)
    {
        capacity_ = newSize;
        if (eles_ != nullptr)
        {
            T *temp = new T[n_];
            for (int i = 0; i < n_; i++)
            {
                temp[i] = eles_[i];
            }
            delete[] eles_;

            eles_ = new T[newSize];
            for (int i = 0; i < n_; i++)
            {
                eles_[i] = temp[i];
            }
            delete[] temp;
        }
        else
        {
            eles_ = new T[newSize];
        }
    }

private:
    T *eles_;
    int n_;
    int capacity_;
};

#endif /* SEQUENCELIST_H */
