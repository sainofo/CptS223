#include "header.h"
#include "AVLNode.h"

template <typename T>
class AVL{
    public:
    AVL(){
     root = nullptr;
    };

    ~AVL(){
        delete root;
    };

    int height(){
        int lHeight = 0, rHeight = 0;

        if(this == nullptr){
            return 0;
        }
        lHeight = (left != nullptr);
        rHeight = (right != nullptr);

        return 1 + max(lHeight, rHeight);
    };

    int getBalance(){
        return balance;
    }

    void inOrderTraversal(){
        if(root == nullptr){
            return 0;
        }
        inOrderTraversal(root->pLeft);
        cout<< root->value << " " << endl;
        inOrderTraversal(root->pRight);
    }

    void postOrderTraversal(){
        if(root == nullptr){
            return 0;
        }
        postOrderTraversal(root->pRight);
        cout << root->value << " " << endl;
        postOrderTraversal(root->pLeft);
    }

    AVLNode<T>* rotateRight(){
        AVLNode<T> *&k2;

        AVLNode<T>*k1 = k2->pRight;
        k2->pRight = k1->pLeft;
        k1->pRight = k2;
        k2->height = max(height(k2->pRight), height(k2->pLeft)) + 1;
        k1->height = max(height(k1->pRight), height(k2->pLeft)) + 1;
        k2 = k1;
    };

   AVLNode<T>* rotateLeft(){
        AVLNode<T> *&k1;

        AVLNode *k2 = k1->pLeft;
        k1->pLeft = k1->pRight;
        k2->pRight = k2;
        k1->height = max(height(k2->pLeft), height(k2->pRight)) + 1;
        k2->height = max(height(k1->pLeft), height(k2->pRight)) + 1;
        k1 = k1;
    }

   AVLNode<T>* rotateRightLeft(){
        AVLNode<T> *&k3;

        rotateRight(k3->pLeft);
        rotateLeft(k3);
    }

    AVLNode<T>* rotateLeftRight(){
        AVLNode<T> *&k4;

        rotateLeft(k4->pLeft);
        rotateRight(k4);
    }

   AVLNode<T>* insert(AVLNode<T>*&t, const T &value){

        if(AVLNode<T> == nullptr){
            return new AVLNode<T>(value);
        }

        if(value < t->data){
            t->left = insert(node->pLeft, value);
        }
        else if(value > t->data){
            t->right = insert(node->pRight, value);
        }
        else{
            return t;
        }

        t->height = 1 + max(height(t->pLeft), height(t->pRight));

        int balance = getBalance(t);

        if(balance > 1){
            return rotateRight(t);
            if(value < t->pLeft->data){
                return rotateRight(t);
            }
            else{
            t->pLeft = rotateLeft(t->pLeft);
            return rotateRight(t);
            }
        }

        if(balance < -1){
            if(value > node->Pright->data){
                return rotateLeft(t);
            }
            else{
                t->pRight = rotateRight(t->pRight);
                return rotateLeft(t);
            }
        }
        return t;
    };

    void insert(const T &value){ 
        root = insert(root, value);
    }

    void deleteTree(){
        if(root == nullptr){
            return 0;
        }

        deleteTree(root->pLeft);
        deleteTree(root->pRight);

        delete root;
    }

    void contains(const T &value){
        AVLNode<T>*node;

        if(node==nullptr){
            return 0;
        }

        if(value == node->data){
            return 1;
        }
        else if(value < node->data){
            return contains(node->pLeft);
        }
        else if(value > node->data){
            return contains(node->pRight);
        }
        else{
            return 0;
        }
        return contains(root, value);
    };

    void validate(){
        const T &value;
        AVLNode<T> * balancedTree;
        AVLNode<T>*height;

        if(node == nullptr){
            return 0;
        }

        if(value == balancedTree){
            value = balancedTree->height->pLeft;
            value = balancedTree->height->pRight;
            return 1;
        }
        else{
            return 0;
        }
        return validate(root);
    };

    // data member 
    AVLNode<T> *root;
    
    private:
    int balance;
};
