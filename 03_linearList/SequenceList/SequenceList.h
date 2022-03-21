#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

template <class T>
class SequenceList
{
public:
    SequenceList(int capacity)
    {
        eles_ = new T[capacity];
        n_ = 0;
    }

    void clear()
    {
        n_ = 0;
    }

    bool isEmpty()
    {
        return n_ == 0;
    }

    int length()
    {
        return n_;
    }

    public T get(int index) const
    {
        return eles_[index];
    }

    void insert(const T &t)
    {

    }

private:
    T *eles_;
    int n_;
}

#endif /* SEQUENCELIST_H */
