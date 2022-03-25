#ifndef UF_H
#define UF_H

/**
 * @brief 并查集
 * 
 */
class UF
{
public:
    /**
     * @brief Construct a new UF object
     * 
     * @param n 元素个数, 初始化时默认分为n个组, 每个元素独立分组
     */
    UF(int n)
    {
        elesAndGroup_ = new int[n];
        // 索引为存储的元素, 值为该节点所在的分组
        for (int i = 0; i < n; i++)
        {
            elesAndGroup_[i] = i;
        }
        count_ = n;
        size_ = n;
    }
    ~UF()
    {
        if (elesAndGroup_ != nullptr)
        {
            delete[] elesAndGroup_;
        }
    }

    /**
     * @brief 当前并查集中数据的分组个数
     * 
     * @return int 
     */
    int count() const { return count_; }

    /**
     * @brief p和q是否在同一组
     * 
     * @param p 
     * @param q 
     * @return true 
     * @return false 
     */
    bool isConnected(int p, int q) const 
    {
        return elesAndGroup_[p] == elesAndGroup_[q];
    }
    
    /**
     * @brief p所在的分组标识
     * 
     * @param p 
     * @return int 
     */
    int find(int p) const
    {
        return elesAndGroup_[p];
    }

    /**
     * @brief 合并p和q所在的分组
     * 
     * @param p 
     * @param q 
     */
    void unions(int p, int q)
    {
        if (isConnected(p, q))
        {
            // 已在同一分组
            return;
        }
        int pGroup = find(p);
        int qGroup = find(q);
        for (int i = 0; i < size_; i++)
        {
            if (find(i) == pGroup)
            {
                elesAndGroup_[i] = qGroup;
            }
        }
        count_--;
    }

private:
    int *elesAndGroup_; // 节点元素和该元素所在分组的标识
    int count_; // 并查集中数据分组个数
    int size_; // 元素个数

};

#endif /* UF_H */
