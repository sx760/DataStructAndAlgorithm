#ifndef HEAPSORT_H
#define HEAPSORT_H

/**
 * @brief 堆排序
 * 
 * @tparam T 
 */
template <class T>
class HeapSort
{
public:
    static void sort(T **source, int n)
    {
        T **heap = new T *[n + 1];
        for (int i = 0; i < n; i++)
        {
            heap[i + 1] = new T();
        }

        createHeap(source, n, heap);
        int N = n; // 未排序的元素最大索引
        while (N != 1)
        {
            swap(heap, 1, N);   // 交换元素
            sink(heap, 1, --N); // 下沉索引1处元素
        }
        for (int i = 0; i < n; i++)
        {
            source[i] = heap[i + 1]; 
        }
        
        /* for (int i = 0; i < n; i++)
        {
            delete heap[i + 1];
        }
        delete[] heap; */
    }

private:
    static void createHeap(T **source, int n, T **heap)
    {
        for (int i = 0; i < n; i++)
        {
            heap[i + 1] = source[i];
        }

        for (int i = n / 2; i > 0; i--)
        {
            sink(heap, i, n);
        }
    }

    static bool less(T **heap, int i, int j)
    {
        return *heap[i] < *heap[j];
    }

    static void swap(T **heap, int i, int j)
    {
        T *temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    /**
     * @brief 下沉算法
     * 
     * @param heap 
     * @param target 
     * @param range 范围0-range
     */
    static void sink(T **heap, int target, int range)
    {
        while (target * 2 <= range)
        {
            int max = target * 2;
            if (target * 2 + 1 <= range)
            {
                if (less(heap, max, max + 1))
                {
                    max = max + 1;
                }
            }

            if (!less(heap, target, max))
            {
                break;
            }

            swap(heap, target, max);
            target = max;
        }
    }
};

#endif /* HEAPSORT_H */
