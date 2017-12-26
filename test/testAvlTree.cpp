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
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(0));
    auto v1 = new vector<int>{0,1,2,3,4};
    auto v2 = tree.inOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvlTree,TestPreOrder){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(0));
    auto v1 = new vector<int>{2,1,0,3,4};
    auto v2 = tree.preOrder();
    cout<<v2->at(0)<<v2->at(1)<<v2->at(2)<<v2->at(3)<<v2->at(4)<<endl;
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvlTree,TestPostOrder){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(0));
    auto v1 = new vector<int>{0,1,4,3,2};
    auto v2 = tree.postOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvlTree,TestInOrderFalse){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(0));
    auto v1 = new vector<int>{1,2,3,4,5};
    auto v2 = tree.inOrder();
    EXPECT_FALSE(compareVectors(v1,v2));
}

TEST(testAvlTree,TestPreOrderFalse){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(0));
    auto v1 = new vector<int>{1,2,3,0,4};
    auto v2 = tree.preOrder();
    EXPECT_FALSE(compareVectors(v1,v2));
}

TEST(testAvlTree,TestPostOrderFalse){
    avlTree tree;
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(0));
    auto v1 = new vector<int>{1,2,3,0,4};
    auto v2 = tree.postOrder();
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
    EXPECT_TRUE(compareVectors(v1,v2));
}
TEST(testAvlTree, TestDoubleRoataionLeftSide){
    avlTree tree;
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(3));
    auto v1 = new vector<int>{3,2,4};
    auto v2 = tree.preOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvltTree, TestDeleteRootOneElement){
    avlTree tree;
    EXPECT_FALSE(tree.search(3));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.search(3));
    tree.remove(3);
    EXPECT_FALSE(tree.search(3));
}

TEST(testAvlTree, TestDeleteRootTwoElements){
    avlTree tree;
    EXPECT_FALSE(tree.search(3));
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.search(3));
    tree.remove(3);
    EXPECT_FALSE(tree.search(3));
    EXPECT_TRUE(tree.search(4));
}

TEST(testAvlTree, TestDeleteRootThreeElement){
    avlTree tree;
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(4));
    tree.remove(3);
    EXPECT_FALSE(tree.search(3));
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.search(4));
}

TEST(testAvlTree, TestDeleteElementLeafRight){
    avlTree tree;
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(8));
    EXPECT_TRUE(tree.insert(1));
    tree.remove(4);
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.search(8));
    EXPECT_TRUE(tree.search(1));
    EXPECT_FALSE(tree.search(4));
    auto v1 = new vector<int>{3,2,1,8};
    auto v2 = tree.preOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvlTree, TestDeleteElementLeafLeft){
    avlTree tree;
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(8));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(1));
    tree.remove(8);
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.search(4));
    EXPECT_TRUE(tree.search(1));
    EXPECT_FALSE(tree.search(8));
    auto v1 = new vector<int>{3,2,1,4};
    auto v2 = tree.preOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}

TEST(testAvlTree,TestDeleteElemetBothLeafs){
    avlTree tree;
    EXPECT_TRUE(tree.insert(3));
    EXPECT_TRUE(tree.insert(2));
    EXPECT_TRUE(tree.insert(8));
    EXPECT_TRUE(tree.insert(4));
    EXPECT_TRUE(tree.insert(1));
    EXPECT_TRUE(tree.insert(9));
    tree.remove(8);
    EXPECT_TRUE(tree.search(2));
    EXPECT_TRUE(tree.search(3));
    EXPECT_TRUE(tree.search(4));
    EXPECT_TRUE(tree.search(1));
    EXPECT_TRUE(tree.search(9));
    EXPECT_FALSE(tree.search(8));
    auto v1 = new vector<int>{3,2,1,4,9};
    auto v2 = tree.preOrder();
    EXPECT_TRUE(compareVectors(v1,v2));
}
