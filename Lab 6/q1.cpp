#include <iostream>
using namespace std;

class Heap {
private:
    int* arr;
    int capacity;
    int size;

    int parent(int i) { 
        return (i - 1) / 2; 
        
    }

    void heapify_up(int index) {
        
        while (index != 0 && arr[index] > arr[parent(index)]) {
            swap(arr[index], arr[parent(index)]);
            index = parent(index);
        }
    }

    void heapify_down(int index) {
        int largest = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if (l < size && arr[l] > arr[largest])
            largest = l;
        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify_down(largest);
        }
    }

public:
    Heap(int cap = 100) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    ~Heap() {
        delete[] arr;
    }

    void insertInMaxHeap(int value) {
        if (size == capacity) {
            cout << "Heap Overflow\n";
            return;
        }
        arr[size] = value;
        heapify_up(size);
        size++;
    }

    void deleteKey(int index) {
        if (index < 0 || index >= size) {
            cout << "Index not found";
            return;
        }
        arr[index] = arr[size - 1];
        size--;
        heapify_down(index);
    }

    void update_key(int index, int new_val) {
        if (index < 0 || index >= size) {
            cout << "Index not found";
            return;
        }

        int old_val = arr[index];
        arr[index] = new_val;

        if (new_val > old_val) {
            heapify_up(index);
        } else {
            heapify_down(index);
        }
    }

    void printHeap() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
       
    }
};

int main() {
    Heap h;

    h.insertInMaxHeap(8);
    h.insertInMaxHeap(7);
    h.insertInMaxHeap(6);
    h.insertInMaxHeap(5);
    h.insertInMaxHeap(4);

    cout << "Max Heap: ";
    h.printHeap();
    cout << endl;

    h.update_key(2, 10);
    cout << "After updating index 2 to 10: ";
    h.printHeap();
    cout << endl;


    h.deleteKey(1);
    cout << "After deleting index 1: ";
    h.printHeap();

    return 0;
}
