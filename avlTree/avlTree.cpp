//
// Created by Marti on 19.12.2017.
//
#include "avlTree.h"

void avlTree::upIn(node *start) {
    if (start != nullptr && start->previous != nullptr) {
        node *before = start->previous;
        //check if node is on left or right side of the previous node.
        if (before->left == start) {
            //check what balance the previous node has/had
            if (before->balance == 1) {
                before->balance -= 1; //balance is now 0 --> no more upInOut needed.
            } else if (before->balance == 0) {
                before->balance -= 1;
                upIn(before);
            } else if (before->balance == -1) {
                if (start->balance == -1){
                    rotateRight(before);
                }
                else{
                    rotateLeft(start);
                    rotateRight(before);
                }
            }
        } else {
            if (before->balance == 1) {
                before->balance += 1;
            } else if (before->balance == 0) {
                before->balance += 1;
                upIn(before);
            } else if (before->balance == -1) {
                if (start->balance == -1){
                    rotateLeft(before);
                }
                else{
                    rotateRight(start);
                    rotateLeft(before);
                }
            }
        }
    }
    //============================================================
}

void avlTree::rotateLeft() {
    //TODO rotateLeft
}

void avlTree::rotateRight() {
    //TODO roateRight
}

//previous = true:  if the search reaches a leaf it returns the previous node holding the leaf. Only if the tree is empty it returns a nullptr.
//                  if a node is returned and not nullptr it must be checked if the returned node is the searched for key or a different one.
//previous = false: if the search reaches a leaf it returns a nullptr. otherwise it returns the node with the searched for key.
node *avlTree::searchRecursive(node *start, const int key, bool previous) {
    if (start == nullptr) return nullptr;
    node *p = start;
    if (k == p->key) {
        return p;
    } else if (key < p->key) {
        if (p->left == nullptr && !previous) return nullptr;
        if (p->left == nullptr && previous) return p;
        searchRecursive(p->left, key);
    } else {
        if (p->right == nullptr && !previous) return nullptr;
        if (p->right == nullptr && previous) return p;
        searchRecursive(p->right, key);
    }
}

bool avlTree::search(const int key) {
    bool notPrevious = false;
    node *searchedNode = searchRecursive(firstNode, key, notPrevious);
    if (searchedNode == nullptr) {
        return false;
    } else {
        return true;
    }
}

bool avlTree::insert(const int key) {
    bool previous = true;
    node *insertNode = searchRecursive(firstNode, key, previous);
    //Only way searchRecursive returns nullPtr (with previous flag = true) is when tree is empty.
    if (insertNode == nullptr) insertNode = new node(key, nullptr);
    //If anything else than nullptr is returned check if key already exists or if a previous node was returned.
    if (insertNode->key == key) return false;
    //If key does not exist insert left or right.
    if (key < insertNode->key) {
        insertNode->left = new node(key, insertNode);
        insertNode->balance -= 1;
        if (insertNode->balance != 0) {
            upIn(insertNode);
        }
    } else {
        insertNode->right = new node(key, insertNode);
        insertNode->balance += 1;
        if (insertNode->balance != 1) {
            upIn(insertNode);
        }

    }

    void avlTree::remove() {
        //TODO remove
    }

    void avlTree::node::calculateBalance() {
        if ((this->right && this->left) == nullptr) {
            this.balance = 0;
        } else if (this->right == nullptr) {
            this->balance = -left->balance;
        } else if (this->left == nullptr) {
            this->balance = right->balance;
        } else {
            this->balance = right->balance - left->balance;
        }
    }
}

