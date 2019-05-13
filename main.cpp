//Alexander Urbanyak

#include <iostream>
#include <stdlib.h>
#include <queue>
#include "bintree.h"

using namespace main_savitch_10;

binary_tree_node<int>* create_binary_tree();
//Post-Condition: Return an unbalanced tree

template <class T>
std::size_t tree_height(binary_tree_node<T>* tree);
//Post-condition: Return height of the tree

template <class T>
void print_node(binary_tree_node<T>* node_ptr);
//Post-condition: Print data at the node or null if there is no data

template <class Process, class BTNode>
void display_tree_levels(Process f, BTNode* tree, size_t height);
//Post Condition: Print level number and the associated level of the tree,
//display data at each node or {NULL} if the node is empty


int main(){
    binary_tree_node<int>* tree = create_binary_tree();
    print(tree, 1);

    display_tree_levels(print_node<int>, tree, tree_height(tree));
    return 0;
}


binary_tree_node<int>* create_binary_tree(){
    binary_tree_node<int>* t1 = new binary_tree_node<int>(1);
    binary_tree_node<int>* t2 = new binary_tree_node<int>(2);
    binary_tree_node<int>* t3 = new binary_tree_node<int>(3);
    binary_tree_node<int>* t4 = new binary_tree_node<int>(4);
    binary_tree_node<int>* t5 = new binary_tree_node<int>(5);
    binary_tree_node<int>* t6 = new binary_tree_node<int>(6);
    binary_tree_node<int>* t7 = new binary_tree_node<int>(7);
    binary_tree_node<int>* t8 = new binary_tree_node<int>(8);
    binary_tree_node<int>* t9 = new binary_tree_node<int>(9);
    binary_tree_node<int>* t10 = new binary_tree_node<int>(10);
    binary_tree_node<int>* t11 = new binary_tree_node<int>(11);
    binary_tree_node<int>* t12 = new binary_tree_node<int>(12);
    binary_tree_node<int>* t13 = new binary_tree_node<int>(13);

    t6->set_left(t5);
    t6->set_right(t10);

    t5->set_left(t4);
    t4->set_left(t2);
    t2->set_left(t1);
    t2->set_right(t3);

    t10->set_left(t8);
    t10->set_right(t11);
    t8->set_left(t7);
    t8->set_right(t9);
    t11->set_right(t12);
    t12->set_right(t13);

    return t6;
}

template <class T>
std::size_t tree_height(binary_tree_node<T>* tree){
    if(tree == NULL)
        return 0;

    size_t left_height = 1 + tree_height(tree->left());
    size_t right_height = 1 + tree_height(tree->right());

    if(left_height>right_height)
        return left_height;
    else
        return right_height;
}

template <class T>
void print_node(binary_tree_node<T>* node_ptr){
    if(node_ptr != NULL)
        std::cout << node_ptr->data() << " ";
    else
        std::cout << "{NULL}" << " ";
}

template <class Process, class BTNode>
void display_tree_levels(Process f, BTNode* tree, size_t height){
    size_t level = 1;
    std::queue<BTNode*> q;

    q.push(tree);

    if(tree == NULL)
        f(NULL);

    while(level <= q.size()){
        size_t node_size = q.size();
        std::cout << "Level " << level << ": ";

        while(node_size > 0){
            BTNode* temp = q.front();
            if(temp != NULL)
                f(temp);
            else
                f(NULL);

            q.pop();
            if(temp != NULL && (temp->left()!= NULL || temp->right()!= NULL)){
                if(temp->left() != NULL)
                    q.push(temp->left());
                else
                    q.push(NULL);

                if(temp->right() != NULL)
                    q.push(temp->right());
                else
                    q.push(NULL);
            }
            else if(temp != NULL && temp->left() == NULL && temp->right() == NULL && level < height){
                q.push(NULL);
                q.push(NULL);
            }
            else if(temp == NULL && level < height){
                q.push(NULL);
                q.push(NULL);
            }
            node_size--;
        }
        std::cout << std::endl;
        level++;
    }
}