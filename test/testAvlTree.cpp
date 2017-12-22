//
// Created by Marti on 19.12.2017.
//
#include "testAvlTree.h"

using namespace std;

TEST(testAvlTree,TestInsertOne) {
    avlTree tree;
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.search(1));
}



// empty list
