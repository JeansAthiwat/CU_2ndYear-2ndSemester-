#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node *n, int &height)
{
    /*
    IDEA: where is max dist?
        it is the maximum between
        1.the left height + right hight  plus 2 edges from linking to the psudo root
        2.the max dist of child node (if it is greater than the 1. )

    */
    int left_height = -1, right_height = -1; // assume no child node height value
    int left_mdist = 0, right_mdist = 0;     // mdist of the children

    if (n == NULL)
        return -1;

    // calculate the diameter(max number of edges from this node) (we get the height as byproduct recursively)
    left_mdist = my_recur(n->left, left_height);
    right_mdist = my_recur(n->right, right_height);

    // calculate the current node height
    height = std::max(left_height, right_height) + 1;


    return std::max(left_height + right_height + 2, std::max(left_mdist, right_mdist));
}

template <typename KeyT,
          typename MappedT,
          typename CompareT>
int CP::map_bst<KeyT, MappedT, CompareT>::furthest_distance()
{
    // write your code here
    if (mSize == 0)
        return -1;

    int height = 0;
    int mdist = my_recur(mRoot, height);
    return mdist;
}

#endif
