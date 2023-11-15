#include "OpenMP.h"
#include "Heap.h"

using namespace std;

void runOpenMP() {
    hello_world();
    cal_sum();
    cal_max();
}

void runHeap() {
    printf("\nStart runHeap()\n");
    int data_size = 10000;
    int* data = new int[data_size];
    for (int i = 0; i < data_size; ++i) {
        data[i] = rand() % data_size;
    }
    auto *hp = new Heap<int>();
    for (int i = 0; i < data_size; ++i) {
        hp->push(data[i]);
    }

    // Sort these values using stl
    std::vector<int> vect(data, data + data_size);
    std::sort(vect.begin(), vect.end());

    for (int i = 0; i < data_size; ++i) {
        // Compare the pop result with the value sorted by stl
        // If the two required functions are correct, the assertion should pass
        assert(vect[i] == hp->pop());
    }
    printf("\nStart runHeap(): assert pass!\n");
}
int main(int argc, char* argv[])
{
    std::vector<int> data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int stlMax = *max_element(data.begin(), data.end());
    int omp_max = 0;
    
    void calc_max();

    cout << "STL Max Value: " << stlMax << endl;
    cout << "OMP Max Value: " << omp_max << endl;
    runOpenMP();

    srand(static_cast<unsigned>(time(nullptr)));
    runHeap();
    
}
