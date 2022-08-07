#ifndef _NODE_H
#define _NODE_H

    /**
    * @struct Node
    * @brief Provides Node for Bst
    *
    *
    *
    *
    * @author Mitchel King
    * @version 01
    * @date 17/5/21
    */

template<class T>
struct Node {
    T info; ///< data of type T
    Node<T> * right; ///< right Node pointer
    Node<T> * left; ///< left Node pointer;
    //Struct constructor
    Node(): info(T()), right(nullptr), left(nullptr){} ///< default constructor
    Node(const T & data):info(data), right(nullptr),left(nullptr) {} ///< overloaded constructor

    //operators, 4 warnings if these are removed, still trying to be minimal and complete
    Node(const Node<T> & node);
    Node & operator=(const Node<T> & otherNode);
    //copy routine
    void copy(Node<T> * & resultNode, Node<T> & otherNode);
};

////copy constructor
template<class T>
Node<T>::Node(const Node<T> & node){
    //copy constructor
    copy(this, node);
}

template<class T>
Node<T> & Node<T>::operator=(const Node<T> & otherNode){
    copy(this, otherNode);
}

//copy method
template<class T>
void Node<T>::copy(Node<T> * & resultNode,Node<T> & otherNode){
    //set to null
    if(otherNode == nullptr){
        resultNode = nullptr;
    }
    else{
        Node<T> * newNode = new Node<T>;
        resultNode = newNode;
        resultNode->info = otherNode->info;

        //recursive call with left then right
        copy(resultNode->left, otherNode->left);
        copy(resultNode->right, otherNode->right);
    }
}
#endif //_NODE_H
