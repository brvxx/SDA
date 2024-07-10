#include "tree.h"

Node* TreeCopy(const Node* t) {
    if (TreeIsEmpty(t)) {
        return NULL;
    }
    Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
    n->left = TreeCopy(TreeLeft(t));
    n->right = TreeCopy(TreeRight(t));
    return n;
}

Node* MergeTreeRec(const Node* t1, const Node* t2) {

    // tre casi base
    if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
        return NULL;
    }
    else if (TreeIsEmpty(t1)) {
        return TreeCopy(t2);
    }
    else if (TreeIsEmpty(t2)) {
        return TreeCopy(t1);
    }

    ElemType sum = 0;
    sum += t1->value;
    sum += t2->value;

    Node* n = TreeCreateRoot(&sum, NULL, NULL); 
    n->left = MergeTreeRec(TreeLeft(t1), TreeLeft(t2)); 
    n->right = MergeTreeRec(TreeRight(t1), TreeRight(t2)); 

    return n; 
}

Node* MergeTree(const Node* t1, const Node* t2) {
    return MergeTreeRec(t1, t2);
}