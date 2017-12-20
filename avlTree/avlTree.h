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

        std::vector<int> *preorder() const;  // (Hauptreihenfolge)
        std::vector<int> *inorder() const;   // (Symmetrische Reihenfolge)
        std::vector<int> *postorder() const; // (Nebenreihenfolge)

    };
    void upIn();

    void upOut();

    void rotateLeft();

    void rotateRight();

public:
    ~avlTree();

    bool insert(const int key);

    bool search(const int key);

    void remove(const int key);

    std::vector<int> *preOrder() const;  // (Hauptreihenfolge)
    std::vector<int> *inOrder() const;   // (Symmetrische Reihenfolge)
    std::vector<int> *postOrder() const; // (Nebenreihenfolge)
};
#endif //BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
