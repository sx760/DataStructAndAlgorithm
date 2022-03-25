#ifndef UF_TREE_H
#define UF_TREE_H

/**
 * @brief 并集查
 * 
 */
class UF_Tree
{
public:
    /**
     * @brief Construct a new uf tree object
     * 
     * @param n 元素数量
     */
    UF_Tree(int n)
    {
        elesAndGroup_ = new int[n];
        // 初始化父节点为其本身
        for (int i = 0; i < n; i++)
        {
            elesAndGroup_[i] = i;
        }
        count_ = n;
        size_ = n;
    }
    ~UF_Tree()
    {
        if (elesAndGroup_ != nullptr)
        {
            delete[] elesAndGroup_;
        }
    }

    int count() const { return count_; }

    bool isConnected(int p, int q) const { return find(p) == find(q); }

    /**
     * @brief 元素p所在分组的标识符
     * 
     * @param p 
     * @return int 
     */
    int find(int p) const 
    {
        while (true)
        {
            if (p == elesAndGroup_[p])
            {
                return p;
            }
            p = elesAndGroup_[p];
        }
    }

    void unions(int p, int q)
    {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot)
        {
            return;
        }
        elesAndGroup_[pRoot] = qRoot;
        count_--;
    }

private:
    int *elesAndGroup_; // 索引为存储的元素, 值为该节点的父节点
    int count_;         // 分组数量
    int size_;          // 元素个数
};

#endif /* UF_TREE_H */
