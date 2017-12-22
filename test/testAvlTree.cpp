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

TEST(testAvlTree,TestInsertBiggerAndLower){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.search(1));
}

TEST(textAvlTree, TestInsertDouble){
    avlTree tree;
    EXPECT_TRUE(tree.insert(1));
    EXPECT_FALSE(tree.insert(1));
    EXPECT_TRUE(tree.search(1));
}



// empty list
