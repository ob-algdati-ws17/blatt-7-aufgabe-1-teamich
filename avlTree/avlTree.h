//
// Created by Marti on 19.12.2017.
//
#ifndef BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
#define BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H

class avlTree {
private:
    struct node {
        const int key;
        node* left = nullptr;
        node* right = nullptr;
        int balance = 0;
        node* previous = nullptr;

        node(int key, node* previous);

        node(int key, node* previous, node* left, node* right, int balance);

        ~node();

        void calculateBalance();

    };

    node* firstNode = nullptr;

    void upIn(node* start);

    void upOut(node* start);

    void rotateLeft(node* rotateThis);

    void rotateRight(node* rotateThis);

    node* searchRecursive(node* start, int key, bool previous);

    void noLeaf(node* removeNode);

    void leafRight(node* removeNode);

    void leafLeft(node* removeNode);

    void twoLeafs(node* removeNode);

    void removeRotation(node* previous,node* removeNode,bool leftSide);

    std::vector<int>* inOrder(node* start, std::vector<int>* v) const;

    std::vector<int>* preOrder(node* start, std::vector<int>* v) const;

    std::vector<int>* postOrder(node* start, std::vector<int>* v) const;

public:
    ~avlTree();

    bool insert(int key);

    bool search(int key);

    void remove(int key);

    std::vector<int>* preOrder() const;  // (Hauptreihenfolge)

    std::vector<int>* inOrder() const;   // (Symmetrische Reihenfolge)

    std::vector<int>* postOrder() const; // (Nebenreihenfolge)
};

#endif //BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
