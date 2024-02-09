#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &aux)
{
    // You MAY use this function
    if (n == NULL)
        return -1;
    return std::max(my_recur(n->left, aux), my_recur(n->right, aux)) + 1;
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance()
{
    // write your code here
    if (mSize == 0)
    {
        return -1;
    }

    int edges = 0;
    int aux = 0;

    if (mRoot->left != NULL)
    {
        ++edges;
        edges += my_recur(mRoot->left, aux);
    }
    if (mRoot->right != NULL)
    {
        ++edges;
        edges += my_recur(mRoot->right, aux);
    }

    return edges;
}

#endif
