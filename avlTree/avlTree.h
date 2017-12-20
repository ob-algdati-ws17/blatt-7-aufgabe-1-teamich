//
// Created by Marti on 19.12.2017.
//

#ifndef BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
#define BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
class avlTree{
private:
    struct node{
        const int key;
        node* left;
        node* right;
        int balance;
        node(int k):key(k){}
    };

    upin();



public:
    bool insert();
    node get();
    bool contains();
    void remove();
};
#endif //BLATT_7_AUFGABE_1_TEAMICH_AVLTREE_H
