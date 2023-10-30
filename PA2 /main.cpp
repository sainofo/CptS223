/*
* Sainofo "Nofo" Fanene
* 10/4/23
* CptS 223
* PA 2: AVL Trees
*/

#include "header.h"
#include "AVLNode.h"
#include "AVL.h"

// test cases
// 1. Ascending order
vector <int> ascendingOrderGenerate(){
    vector<int> order;

    for(int i = 0; i <= 100; i++){
       order.push_back(i);
    }
    return order;
}

// 2. Descending Order
vector<int> descendingOrderGenerate(){
    vector<int> order;

    for(int i = 99; i >= 1; i -=2){
        order.push_back(i);
    }
    return order;
}

// 3. Random Order
vector<int> randomOrderGenerate(){
    vector<int> order;

    for(int i = 1; i <= 100; i+= 2){
        order.push_back(i);
    }

    srand(time(NULL));
    return order;
}

template <typename T>
int main(void){
    // generating the test cases
    vector<int> ascendingOrder = ascendingOrderGenerate();
    vector<int> descendingOrder = descendingOrderGenerate();
    vector<int> randomOrder = randomOrderGenerate();

    // displaying the ascendingOrder test case
    for(int i = 0; i < 10; i++){
        cout << ascendingOrder[i] << " " <<endl;
    }
    cout << endl;

    // displaying the descendingOrder test case
    for(int i = 0; i < 10; i++){
        cout << descendingOrder[i] << " " << endl;
    }
    cout << endl;

    // displaying the RandomOrder test case
    for(int i = 0; i < 10; i++){
        cout << randomOrder[i] << " " << endl;
    }
    cout << endl;

    AVL<T> AVLtree1;
    AVL<T> AVLTree2;
    AVL<T> AVLTree3;

    AVLTree1.insert(50);
    AVLTree2.insert(50);
    AVLTree3.insert(50);

    cout << "Height for AVLTree1: " << AVLTree1.height() << endl;
    cout << "Height for AVLTree2: " << AVLTree2.height() << endl;
    cout << "Height for AVLTree3: " << AVLTree3.height() << endl;

    cout << "Result for AVLTree1: " << AVLTree1.validate() << endl;
    cout << "Result for AVLTree2: " << AVLTree2.validate() << endl;
    cout << "Result for AVLTree3: " << AVLTree3.validate() << endl;

    for(int i = 0; i <= 100; i++){
        AVLTree1.insert(i);
        AVLTree2.insert(i);
        AVLTree3.insert(i);
    }

    for(int i = 1; i <= 100; i++){
        bool isOdd = 1;
        int expected = 0;

        bool result1 = AVLTree1.contains(i);
        bool result2 = AVLTree2.contains(i);
        bool result3 = AVLTree3.contains(i);
        
        if(expected == isOdd){
            expected = (i % 2 == 1);
            return 1;
        }
        else{
            expected = (i % 2 == 0);
            return 0;
        }

        if(result1 != expected && result2 != expected && result3 != expected){
            cout << "My AVL trees implementation is wrong" << endl;
            break;
        }
    }
    return 0;
}
