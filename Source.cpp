#include <iostream>
#include <stdexcept>

class SmartArray {
private:
    int* data;
    int capacity;
    int size;

public:
    
    SmartArray(int initialCapacity) : capacity(initialCapacity), size(0) {
        if (initialCapacity <= 0) {
            throw std::invalid_argument(" оличество элементов должно быть больше 0");
        }
        data = new int[capacity];
    }

    
    ~SmartArray() {
        delete[] data;
    }

    
    void push_back(int value) {
        if (size == capacity) {
           
            capacity *= 2;
            int* newData = new int[capacity];
           
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size++] = value;
    }

    int at(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Out of bounds");
        }
        return data[index];
    }
};

int main() {
    try {
     
        SmartArray myArray(5);

       
        myArray.push_back(10);
        myArray.push_back(20);
        myArray.push_back(30);
        myArray.push_back(40);
        myArray.push_back(50);
        myArray.push_back(60); 

       
        std::cout << "Ёлемент с индексом 0: " << myArray.at(0) << std::endl;
        std::cout << "Ёлемент с индексом 2: " << myArray.at(2) << std::endl;

       
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}