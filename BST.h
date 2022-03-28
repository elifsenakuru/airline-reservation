#ifndef BST_H
#define BST_H

#include <iostream>

#include "BSTNode.h"

enum TraversalPlan {preorder, inorder, postorder};

template<class T>
class BST {
public: // DO NOT CHANGE THIS PART.
    BST();
    BST(const BST<T> &obj);

    ~BST();

    BSTNode<T> *getRoot() const;
    bool isEmpty() const;
    bool contains(BSTNode<T> *node) const;

    void insert(const T &data);

    void remove(const T &data);
    void removeAllNodes();

    BSTNode<T> *search(const T &data) const;
    BSTNode<T> *getSuccessor(BSTNode<T> *node, TraversalPlan tp) const;

    void print(TraversalPlan tp=inorder) const;

    BST<T> &operator=(const BST<T> &rhs);
    
    T getMin();

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void print(BSTNode<T> *node, TraversalPlan tp) const;
    void make_copy(BSTNode<T> *&r1, BSTNode<T> *r2);
    bool contains(BSTNode<T> *t1, BSTNode<T> *t2) const;
    void removeAllNodes(BSTNode<T> *&r1);
    BSTNode<T>* search(BSTNode<T> *r, const T &data) const;
    void insert(BSTNode<T> *&r, const T &data);
    T getMin(BSTNode<T> *r);
    void remove(BSTNode<T> *&r, const T &data);
    
private: // DO NOT CHANGE THIS PART.
    BSTNode<T> *root;
};

#endif //BST_H

template<class T>
BST<T>::BST() {
    /* TODO */
    root = NULL;
}

template<class T>
BST<T>::BST(const BST<T> &obj) {
    /* TODO */
    if (obj.root == NULL){
        root = NULL;
    }
    else{
        make_copy(root, obj.root);
    }
        
}

template<class T>
BST<T>::~BST() {
    /* TODO*/
    removeAllNodes();
}

template<class T>
BSTNode<T> *BST<T>::getRoot() const {
    /* TODO */
    if(root == NULL){
        return NULL;
    }
    else{
        return root;
    }
}

template<class T>
bool BST<T>::isEmpty() const {
    /* TODO */
    if(root == NULL){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool BST<T>::contains(BSTNode<T> *node) const {
    /* TODO */
    return contains(root,node);
}

template<class T>
bool BST<T>::contains(BSTNode<T> *r1, BSTNode<T> *r2) const{
    if (r1==r2){
        return true;
    }
    else if (contains(r1->right,r2)){
        return true;
    }
    else if (contains(r1->left,r2)){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
void BST<T>::insert(const T &data) {
    /* TODO */
    insert(root, data);
}

template<class T>
void BST<T>::insert(BSTNode<T> *&r, const T &data){
    if (r==NULL){
        r = new BSTNode<T>(data,NULL,NULL);
    }
    else if(r->data< data){
        insert(r->right,data);
    }
    else if(r->data >data){
        insert(r->left, data);
    }
    else{
        ;
    }
}

template<class T>
T BST<T>::getMin(){
    return getMin(root);
}

template<class T>
T BST<T>::getMin(BSTNode<T> *r){
    if(r->left == NULL){
        return r->data;
    }
    else{
        return getMin(r->left);
    }
}

template<class T>
void BST<T>::remove(const T &data) {
    /* TODO */
    remove(root,data);
}

template<class T>
void BST<T>::remove(BSTNode<T> *&r, const T &data){
    if(r==NULL){
        return;
    }
    else if(data > r->data){
        remove(r->right,data);
    }
    else if(data < r->data){
        remove(r->left,data);
    }
    
    else{
        if(r->left != NULL && r->right != NULL){
            r->data = getMin(r->right);  
            remove(r->right,r->data);
        }
        else{
            BSTNode<T> *oldNode = r;
            if(r->left != NULL){
                r = r->left;
            }
            else{
                r = r->right;
            }
            delete oldNode;
        }
    }
}

template<class T>
void BST<T>::removeAllNodes() {
    /* TODO */
    removeAllNodes(root);
}

template<class T>
void BST<T>::removeAllNodes(BSTNode<T> *&r){
    if (r==NULL){
        return;
    }
    else{
        removeAllNodes(r->right);
        removeAllNodes(r->left);
        delete r;
        r =NULL;
    }
}

template<class T>
BSTNode<T> *BST<T>::search(const T &data) const {
    /* TODO */
    
    return search(root, data);
    
}

template<class T>
BSTNode<T> *BST<T>::search(BSTNode<T> *r, const T &data) const{
    if (r == NULL || r->data == data){
        return r;
    }
    else if(r->data < data){
        return search(r->right, data);
    }
    else if(r->data > data){
        return search(r->left,data);
    }
    else{
        return NULL;
    }
}

template<class T>
BSTNode<T> *BST<T>::getSuccessor(BSTNode<T> *node, TraversalPlan tp) const {

    if (tp == inorder) {
        /* TODO */
    } else if (tp == preorder) {
        /* TODO */
    } else if (tp == postorder) {
        /* TODO */
    }
}

template<class T>
void BST<T>::print(TraversalPlan tp) const {

    if (tp == inorder) {
        // check if the tree is empty?
        if (isEmpty()) {
            // the tree is empty.
            std::cout << "BST_inorder{}" << std::endl;
            return;
        }

        // the tree is not empty.

        // recursively output the tree.
        std::cout << "BST_inorder{" << std::endl;
        print(root, inorder);
        std::cout << std::endl << "}" << std::endl;
    } else if (tp == preorder) {
        /* TODO*/
        if(isEmpty()){
            std::cout << "BST_preorder{}" << std::endl;
            return;
        }   
        std::cout << "BST_preorder{" << std::endl;
        print(root,preorder);
        std::cout << std::endl << "}" << std::endl;
        
    } else if (tp == postorder) {
        /* TODO */
        if(isEmpty()){
            std::cout << "BST_postorder{}" << std::endl;
            return;
        }   
        std::cout << "BST_postorder{" << std::endl;
        print(root,postorder);
        std::cout << std::endl << "}" << std::endl;
        
    }
}

template<class T>
void BST<T>::make_copy(BSTNode<T> *&t1, BSTNode<T> *t2){
    if (t2 == NULL){
        t1 =NULL;
    }
    else{
        t1 = new BSTNode<T>(t2->data,NULL,NULL);
        make_copy(t1->left, t2->left);
        make_copy(t1->right, t2->right);
    }
}

template<class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {
    /* TODO */
    if(this != &rhs){
        removeAllNodes(root);
        make_copy(root, rhs.root);
    }
    return *this;
}

template<class T>
void BST<T>::print(BSTNode<T> *node, TraversalPlan tp) const {

    // check if the node is NULL?
    if (node == NULL)
        return;

    if (tp == inorder) {
        // first, output left subtree and comma (if needed).
        print(node->left, inorder);
        if (node->left) {
            std::cout << "," << std::endl;
        }

        // then, output the node.
        std::cout << "\t" << node->data;

        // finally, output comma (if needed) and the right subtree.
        if (node->right) {
            std::cout << "," << std::endl;
        }
        print(node->right, inorder);
    } else if (tp == preorder) {
        /* TODO */
        std::cout << "\t" << node->data;
        
        if(node->left){
            std::cout << "," << std::endl;
        }
        print(node->left,preorder);
        
        if(node->right){
            std::cout << "," << std::endl;
        }
        
        print(node->right,preorder);
    } else if (tp == postorder) {
        /* TODO */
        print(node->left,postorder);
        
        if(node->left){
            std::cout << "," << std::endl;
        }
        
        print(node->right, postorder);
        
        if(node->right){
            std::cout << "," << std::endl;
        }
        
        std::cout << "\t" << node->data;
    }
}
