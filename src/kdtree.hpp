#ifndef _KDTREE_HEADER
#define _KDTREE_HEADER

#include <vector>
#include <cstddef>
#include "geometry.hpp"

struct KDNode
{
    KDNode(Point p);

    const Point point();
    KDNode* p_left, *p_right;
private:
    Point p_point;
};

KDNode::KDNode(Point p): p_point(p) {}

const Point KDNode::point()
{
    return p_point;
}

class KDTree
{
public:
    KDTree();
    ~KDTree();

    KDNode* find(Point p);
    void insert(Point p);
    std::vector<KDNode*>* search(Rectangle r);
    void clear();
private:
    KDNode* root = nullptr;

    KDNode* find_(KDNode* root, KDNode* fnode, std::size_t dim);
    KDNode* insert_(KDNode* root, KDNode* nnode, std::size_t dim);
    void search_(KDNode* root, Rectangle r, std::vector<KDNode*>*, std::size_t dim);

    void clear_(KDNode* root);
};

KDTree::KDTree() { }

void KDTree::clear_(KDNode* root)
{
    if (root != nullptr)
        return;

    if (root->p_left != nullptr)
        clear_(root->p_left);
    if (root->p_right != nullptr)
        clear_(root->p_right);
    delete root;
}

KDTree::~KDTree()
{
    clear();
}

void KDTree::clear()
{
    clear_(root);
}

void KDTree::insert(Point p)
{
    root = insert_(root, new KDNode(p), 0);
}

KDNode* KDTree::insert_(KDNode* root, KDNode* nnode, std::size_t dim)
{
    if (root == nullptr)
        return nnode;

    if (root->point().dim(dim % 2) > nnode->point().dim(dim % 2))
        root->p_left = insert_(root->p_left, nnode, dim + 1);
    else
        root->p_right = insert_(root->p_right, nnode, dim + 1);
    return root;
}

KDNode* KDTree::find(Point p)
{
    return find_(root, new KDNode(p), 0);
}

KDNode* KDTree::find_(KDNode* root, KDNode* fnode, std::size_t dim)
{
    std::size_t actualDim = dim % 2;
    std::size_t nextDim = (dim + 1) % 2;

    if (root == nullptr)
        return nullptr;

    // Identifies whether the current node has the element searched element
    if (fnode->point().dim(actualDim) == root->point().dim(actualDim) && 
            fnode->point().dim(nextDim) == root->point().dim(nextDim))
        return root;

    // If the current node is not selected, then the search starts again 
    // considering a new dimension
    if (root->point().dim(actualDim) > fnode->point().dim(actualDim))
        return find_(root->p_left, fnode, dim + 1);
    else
        return find_(root->p_right, fnode, dim + 1);
    return nullptr;
}

std::vector<KDNode*>* KDTree::search(Rectangle r)
{
    std::vector<KDNode*>* reported = new std::vector<KDNode*>();
    search_(root, r, reported, 0);

    return reported;
}

void KDTree::search_(KDNode* root, Rectangle r, 
                        std::vector<KDNode*>* reported, std::size_t dim)
{
    std::size_t actualDim = dim % 2;
    std::size_t nextDim = (dim + 1) % 2;
    Range actualDimRange = r.dim(actualDim);
    Range nextDimRange = r.dim(nextDim); 

    if (root == nullptr)
        return; // Para evitar falha de segmentação

    // Check whether the element is within the delimited range. If 
    // one dimension is equal, the other dimension is checked; if the second 
    // dimension is equal, then the element is reported
    if (root->point().dim(actualDim) >= actualDimRange.min() && 
        root->point().dim(actualDim) <= actualDimRange.max()) 
    {
        if (root->point().dim(nextDim) >= nextDimRange.min() && 
            root->point().dim(nextDim) <= nextDimRange.max())
                reported->push_back(root);
                // The fact that this part does not return, indicating, for example, the end of a recursion
                // indicates that even if an element is found, the sides of the node need to be checked.
    }

    // In this part, what is being done is to eliminate the sides of 
    // the tree that do not meet the 'spatial requirements'
    if (actualDimRange.min() <= root->point().dim(actualDim))
        search_(root->p_left, r, reported, dim + 1);
    if (actualDimRange.max() >= root->point().dim(actualDim))
        search_(root->p_right, r, reported, dim + 1);
}

#endif
