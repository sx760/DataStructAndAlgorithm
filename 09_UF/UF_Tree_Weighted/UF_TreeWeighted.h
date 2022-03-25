#ifndef UF_TREEWEIGHTED_H
#define UF_TREEWEIGHTED_H

/**
 * @brief 并集查, 路径压缩
 * 
 */
class UF_TreeWeighted
{
public:
    /**
     * @brief Construct a new uf treeweighted object
     * 
     * @param n 
     */
    UF_TreeWeighted(int n)
    {
        elesAndGroup_ = new int[n];
        sz_ = new int[n];
        for (int i = 0; i < n; i++)
        {
            // 初始化父节点为其本身
            elesAndGroup_[i] = i;
            // 初始化树中元素个数为1
            sz_[i] = 1;
        }
        count_ = n;
        size_ = n;
    }
    ~UF_TreeWeighted()
    {
        if (elesAndGroup_ != nullptr)
        {
            delete[] elesAndGroup_;
            elesAndGroup_ = nullptr;
        }
        if (sz_ != nullptr)
        {
            delete[] sz_;
            elesAndGroup_ = nullptr;
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

        // 将较小的树合并到较大的树中
        if (sz_[pRoot] < sz_[qRoot])
        {
            elesAndGroup_[pRoot] = qRoot;
            sz_[qRoot] += sz_[pRoot];
        }
        else
        {
            elesAndGroup_[qRoot] = pRoot;
            sz_[pRoot] += sz_[qRoot];
        }

        count_--;
    }

private:
    int *elesAndGroup_; // 索引为存储的元素, 值为该节点的父节点
    int *sz_;           // 每个根节点对应的树中元素个数
    int count_;         // 分组数量
    int size_;          // 元素个数
};

#endif /* UF_TREEWEIGHTED_H */
