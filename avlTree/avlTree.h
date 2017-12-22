//
// Created by Marti on 19.12.2017.
//
#ifndef BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
#define BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
class avlTree{
private:
    struct node {
        const int key;
        node *left;
        node *right;
        int balance;
        node *previous;

        node(const int key, node* previous);

        node(const int key, node* previous, node* left, node* right, int balance);

        ~node();

        void calculateBalance();

        //std::vector<int> *preorder() const;  // (Hauptreihenfolge)
        //std::vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        //std::vector<int> *postorder() const; // (Nebenreihenfolge)

    };

    node* firstNode = nullptr;

    void upIn(node *start);

    void rotateLeft(node* rotateThis);

    void rotateRight(node* rotateThis);

    node* searchRecursive(node *start, int key, bool previous);

public:
    ~avlTree();

    bool insert(int key);

    bool search(int key);

    void remove(int key);

    //std::vector<int> *preOrder() const;  // (Hauptreihenfolge)
    //std::vector<int> *inOrder() const;   // (Symmetrische Reihenfolge)
    //std::vector<int> *postOrder() const; // (Nebenreihenfolge)
};
#endif //BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
