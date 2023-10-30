#include "header.h"

template <typename T>
class AVLNode{
    public:
    AVLNode(const T& value){
        data = T();
        data = value;
        pLeft = nullptr;
        pRight = nullptr;
        height = 1;
    };

    ~AVLNode(){
        delete pLeft;
        delete pRight;
    };

    // data members
    int value;
    T data;
    AVLNode<T> *pLeft;
    AVLNode<T> *pRight;
    int height;

};
