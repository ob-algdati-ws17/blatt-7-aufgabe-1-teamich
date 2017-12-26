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

TEST(testAvlTree,TestInOrder){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.search(1));
    auto v1 = new vector<int>{1,2,3};
    auto v2 = tree.inOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvlTree,TestInOrderFalse){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.search(1));
    auto v1 = new vector<int>{1,3,3};
    auto v2 = tree.inOrder();
    EXPECT_FALSE(compareVectors(v1,v2));
}

TEST(testAvlTree, TestInsertDouble){
    avlTree tree;
    EXPECT_TRUE(tree.insert(1));
    EXPECT_FALSE(tree.insert(1));
    EXPECT_TRUE(tree.search(1));
}

TEST(testAvlTree, TestRotationRight){
    avlTree tree;
    EXPECT_TRUE(tree.insert(5));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(3));
    auto v1 = new vector<int>{4,3,5};
    auto v2 = tree.preOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvlTree, TestRotationLeft){
    avlTree tree;
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(5));
    auto v1 = new vector<int>{4,3,5};
    auto v2 = tree.preOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvlTree, TestDoubleRoataionRightSide){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(3));
    auto v1 = new vector<int>{3,2,4};
    auto v2 = tree.preOrder();
    cout<<v2->at(0)<<v2->at(1)<<v2->at(2)<<endl;
    EXPECT_TRUE(compareVectors(v1,v2));
}
TEST(testAvlTree, TestDoubleRoataionLeftSide){
    avlTree tree;
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(3));
    auto v1 = new vector<int>{2,4,3};
    auto v2 = tree.postOrder();
    cout<<v2->at(0)<<v2->at(1)<<v2->at(2)<<endl;
    EXPECT_TRUE(compareVectors(v1,v2));
}



/*TEST(testAvlTree, TestInsert3Left){
    avlTree tree;
    EXPECT_TRUE(tree);
}*/




// empty list
