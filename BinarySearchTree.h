#ifndef DATASTRUCTURES_BINARYSEARCHTREE_H
#define DATASTRUCTURES_BINARYSEARCHTREE_H

#include <queue>
#include <iostream>
template<class T>
struct node{
    T key;

    node<T>* right;
    node<T>* left;
    node<T>* parent;

    node();
    explicit node(T const & key);
    ~node() = default;

    void join_left(node<T>&child);
    void join_right(node<T>&child);

    void join_left(node<T>*child);
    void join_right(node<T>*child);

};

template<class T>node<T>::node() {
    parent = nullptr;
    right = nullptr;
    left = nullptr;
}

template<class T>node<T>::node(const T &key) {
    this->key = key;
    parent = nullptr;
    right = nullptr;
    left = nullptr;
}

template<class T>
void node<T>::join_left(node<T>& child) {
    left = *child;
    child.parent = this;
}

template<class T>void node<T>::join_right(node<T> &child) {
    right = *child;
    child.parent = this;
}

template<class T>void node<T>::join_left(node<T> *child) {
    this->left = child;
    child->parent = this;
}

template<class T>void node<T>::join_right(node<T> *child) {
    this->right = child;
    child->parent = this;
}


template<class T>
class BSTree{
public:
    node<T>* root;
    node<T>*search(T const & key);
    void push(T const & key);
    void print();
    BSTree();
};

template<class T>
BSTree<T>::BSTree() {
    root = nullptr;
}

template<class T>
node<T>* BSTree<T>::search(T const &key) {
    //static_assert(root == nullptr, "tree is empty wtf ?");
    node<T>* current = root;
    while(current->key != key){
        if(key <= current->key){
            if(current->left == nullptr){
               return current;
            }
            current = current->left;
        }
        if(key > current->key){
            if(current->right == nullptr){
                return current;
            }
            current = current->right;
        }
    }
    return current;
}

template<class T>
void BSTree<T>::push(T const &key) {
    if(root == nullptr){
        root = new node<T>(key);
        return;
    }

    node<T>* curr;
    curr = search(key);
    if(key <= curr->key)curr->join_left(new node<T>(key));
    else curr->join_right(new node<T>(key));
}

template<class T>
void BSTree<T>::print() {
    auto curr = root;
    std::queue<node<T>*>q;
    q.push(curr);
    while(!q.empty()){
        auto s = q.front();
        std::cout << s->key;
        q.pop();
        if(s->left != nullptr)q.push(s->left);
        if(s->right != nullptr)q.push(s->right);
    }
}

#endif //DATASTRUCTURES_BINARYSEARCHTREE_H