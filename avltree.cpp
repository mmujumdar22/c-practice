/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
int AVLTree<K, V>::myMax(int c1, int c2){
    if(c1==-1 && c2==-1)
        return 0;
    if(c1==-1 && c2!=-1)
        return c2;
    if(c1!=-1 && c2==-1)
        return c1;

    if( c1>=c2){
        return c1;
    }else{
        return c2;
    }



}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    Node * temp = t->right;
    t->right = temp->left;
    temp->left = t;
    t->height = myMax(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    t = temp;
    t->height = myMax(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{

    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    Node * temp = t->left;
    t->left = temp->right;
    temp->right = t;
    t->height = myMax(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
    t = temp;
    t->height = myMax(heightOrNeg1(t->left),heightOrNeg1(t->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);

}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
    if(heightOrNeg1(subtree -> left) - heightOrNeg1(subtree -> right) > 1){
        if(heightOrNeg1(subtree -> left -> left) - heightOrNeg1(subtree -> left -> right) < 0){
            rotateLeftRight(subtree);
        }else{
            rotateRight(subtree);
        }
    }
    if(heightOrNeg1(subtree -> left) - heightOrNeg1(subtree -> right) < -1){
        if(heightOrNeg1(subtree -> right -> left) - heightOrNeg1(subtree -> right -> right) > 0){
            rotateRightLeft(subtree);
        }else{
            rotateLeft(subtree);
        }
    }
    subtree -> height = 1 + AVLTree<K, V>::myMax(heightOrNeg1(subtree -> left), heightOrNeg1(subtree -> right));

}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    // your code here
    if(subtree == NULL){
        subtree = new Node(key, value);
    }else if(key < subtree -> key){
        insert(subtree -> left, key, value);
    }else if(key > subtree -> key){
        insert(subtree -> right, key, value);
    }else{
        subtree -> value = value;
    }
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
        remove(subtree -> left, key);
    } else if (key > subtree->key) {
        // your code here
        remove(subtree -> right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            delete subtree;
            subtree = NULL;
            /* no-child remove */
            // your code here
        } else if (subtree->left != NULL && subtree->right != NULL) {
            Node* temp = subtree -> left;
            while(temp -> right != NULL){
                temp = temp -> right;
            }
            swap(temp, subtree);
            remove(subtree -> left, key);
            /* two-child remove */
            // your code here
        } else {
            if(subtree -> left == NULL){
                Node* temp = subtree -> right;
                swap(subtree, temp);
                subtree -> right = temp -> right;
                subtree -> left = temp -> left;
                delete temp;
                temp = NULL;
            }else{
                Node* temp = subtree -> left;
                swap(subtree, temp);
                subtree -> right = temp -> right;
                subtree -> left = temp -> left;
                delete temp;
                temp = NULL;
            }
            /* one-child remove */
            // your code here
        }
        // your code here
        if(subtree != NULL){
            rebalance(subtree);
        }
    }
}