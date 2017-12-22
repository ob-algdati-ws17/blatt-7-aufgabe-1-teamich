//
// Created by Marti on 19.12.2017.
//
#include <vector>
#include "avlTree.h"

avlTree::~avlTree() {
    delete firstNode;
}

void avlTree::upIn(node* start) {
    if (start != nullptr && start->previous != nullptr) {
        node* before = start->previous;
        //check if node is on left or right side of the previous node.
        if (before->left == start) {
            //check what balance the previous node has/had
            if (before->balance == 1) {
                before->balance -= 1; //balance is now 0 --> no more upInOut needed.
            } else if (before->balance == 0) {
                before->balance -= 1;
                upIn(before);
            } else if (before->balance == -1) {
                if (start->balance == -1) {
                    rotateRight(before);
                } else {
                    rotateLeft(start);
                    rotateRight(before);
                }
            }
        } else {
            if (before->balance == -1) {
                before->balance += 1;
            } else if (before->balance == 0) {
                before->balance += 1;
                upIn(before);
            } else if (before->balance == 1) {
                if (start->balance == 1) {
                    rotateLeft(before);
                } else {
                    rotateRight(start);
                    rotateLeft(before);
                }
            }
        }
    }
    //============================================================
}

void avlTree::rotateLeft(node* rotate) {
    node* right = rotate->right;
    node* before = rotate->previous;
    if (before == nullptr) {
        firstNode = right;
        rotate->right = nullptr;
    } else {
        if (before->left != rotate) {
            before->right = right;
        } else {
            before->left = right;
        }
        right->previous = before;
    }
    rotate->right = right->left;
    right->left = rotate;
    rotate->previous = right;
    rotate->balance += 1;
    right->balance += 1;
}

void avlTree::rotateRight(node* rotate) {
    node* left = rotate->left;
    node* before = rotate->previous;
    if (before == nullptr) {
        firstNode = left;
        rotate->left = nullptr;
    } else {
        if (before->left != rotate) {
            before->right = left;
        } else {
            before->left = left;
        }
        left->previous = before;
    }
    rotate->left = left->right;
    left->right = rotate;
    rotate->previous = left;
    rotate->balance += 1;
    left->balance += 1;
}

//previous = true:  if the search reaches a leaf it returns the previous node holding the leaf. Only if the tree is empty it returns a nullptr.
//                  if a node is returned and not nullptr it must be checked if the returned node is the searched for key or a different one.
//previous = false: if the search reaches a leaf it returns a nullptr. otherwise it returns the node with the searched for key.
avlTree::node* avlTree::searchRecursive(node* start, const int key, bool previous) {
    if (start == nullptr) return nullptr;
    node* p = start;
    if (key == p->key) {
        return p;
    } else if (key < p->key) {
        if (p->left == nullptr && !previous) return nullptr;
        if (p->left == nullptr && previous) return p;
        searchRecursive(p->left, key, previous);
    } else {
        if (p->right == nullptr && !previous) return nullptr;
        if (p->right == nullptr && previous) return p;
        searchRecursive(p->right, key, previous);
    }
}

bool avlTree::search(const int key) {
    bool notPrevious = false;
    node* searchedNode = searchRecursive(firstNode, key, notPrevious);
    if (searchedNode == nullptr) {
        return false;
    } else {
        return true;
    }
}

bool avlTree::insert(const int key) {
    bool previous = true;
    node* insertNode = searchRecursive(firstNode, key, previous);
    //Only way searchRecursive returns nullPtr (with previous flag = true) is when tree is empty.
    if (insertNode == nullptr) {
        firstNode = new node(key, nullptr);
        return true;
    }
    //If anything else than nullptr is returned check if key already exists or if a previous node was returned.
    if (insertNode->key == key) return false;
    //If key does not exist insert left or right.
    if (key < insertNode->key) {
        insertNode->left = new node(key, insertNode, nullptr, nullptr,0);
        insertNode->balance -= 1;
        if (insertNode->balance != 0) {
            upIn(insertNode);
        }
        return true;
    } else {
        insertNode->right = new node(key, insertNode, nullptr, nullptr,0);
        insertNode->balance += 1;
        if (insertNode->balance != 0) {
            upIn(insertNode);
        }
        return true;
    }
}

void avlTree::remove(int key) {
    //TODO remove
}

std::vector<int>* avlTree::inOrder() const {
    auto* v = new std::vector<int>();
    inOrder(firstNode, v);
    return v;
}

std::vector<int>* avlTree::inOrder(avlTree::node* start, std::vector<int>* v) const {
    if (start->left != nullptr) {
        preOrder(start->left, v);
    }
    v->push_back(start->key);
    if (start->right != nullptr) {
        preOrder(start->right, v);
    }
    return v;
}

std::vector<int>* avlTree::preOrder() const {
    auto* v = new std::vector<int>();
    preOrder(firstNode, v);
    return v;
}

std::vector<int>* avlTree::preOrder(avlTree::node* start, std::vector<int>* v) const {
    v->push_back(start->key);
    if (start->left != nullptr) {
        preOrder(start->left, v);
    }
    if (start->right != nullptr) {
        preOrder(start->right, v);
    }
    return v;
}

std::vector<int>* avlTree::postOrder() const {
    auto* v = new std::vector<int>();
    postOrder(firstNode, v);
    return v;
}

std::vector<int>* avlTree::postOrder(avlTree::node* start, std::vector<int>* v) const {
    if (start->left != nullptr) {
        preOrder(start->left, v);
    }
    if (start->right != nullptr) {
        preOrder(start->right, v);
    }
    v->push_back(start->key);
    return v;
}

avlTree::node::~node() {
    delete left;
    delete right;
}

void avlTree::node::calculateBalance() {
    if (this->right == nullptr && this->left == nullptr) {
        this->balance = 0;
    } else if (this->right == nullptr) {
        this->balance = -left->balance;
    } else if (this->left == nullptr) {
        this->balance = right->balance;
    } else {
        this->balance = right->balance - left->balance;
    }
}

avlTree::node::node(int key, node* previous) : key(key), previous(previous) {
    this->right = nullptr;
    this->left = nullptr;
}

avlTree::node::node(int key, node* previous, node* left, node* right, int balance)
        : key(key), previous(previous), left(left), right(right) {
    this->calculateBalance();
}
