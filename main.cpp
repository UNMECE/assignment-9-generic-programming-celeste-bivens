#include <iostream>
#include <cassert>//testing array values
#include <limits>

template <typename T>//data type T
class GenericArray
{
private: 
    T *data; //pointer to dynamic array. 
    int size;
    int capacity;  
    
public: 
    //Constructor
    GenericArray(){
        capacity = 5;
        data = new T[capacity];//allocate memory for T array.
        size = 0;
    }

    GenericArray& addElement(const T& value){
        if(size <= capacity)//Making sure array cannot go over the designated size
        {
            data[size++] = value;
        }
        return *this;
    }

    int length()
    {
        return size; 
    }

    T valueAt(int index)
    {
        return data[index];
    }

   
    T sum()
    {
        T total = 0;
        for(int i = 0; i < size; i++)
        {
            total += data[i];
        }
        return total;
    }

    T max()
    {
        T maximum = std::numeric_limits<T>::min();
        for(int i = 0; i < size; i++)
        {
            if (data[i] > maximum)
            {
                maximum = data[i];
            }
        }
        return maximum; 
    }

    T min()
    {
        T minimum = data[0];
        for(int i = 0; i < size; i++)
        {
            if (data[i] < minimum)
            {
                minimum = data[i];
            }
        }
        return minimum; 
    }

    T* slice(int startIndex, int endIndex)
    {
        if(startIndex == 0)
        {
            std::cout << "First bound not correctly defined." << std::endl;
        }

        if(endIndex == size)
        {
            std::cout << "Last bound not correctly defined." << std::endl;
        }
        
        int new_size = endIndex - startIndex + 1; 

        T* new_array = new T[new_size];//Allocating memory for sliced array.
        int j = 0;
        for(int i = startIndex; i <= endIndex; i++)
        {
            new_array[j++] = data[i];
        }
        return new_array;
        }

    //Destructor
    ~GenericArray(){
        delete[] data;
    }

};


int main(){
    GenericArray<int> int_array;

    int_array.addElement(1)
    .addElement(99)
    .addElement(200)
    .addElement(35)
    .addElement(25)
    .addElement(15);

    auto size = int_array.length();
    auto index = 0;
    auto actual = int_array.valueAt(index++);
    
    std::cout << "Array elements: ";
        for(int i = 0; i < size; i++)
        {
            std::cout << int_array.valueAt(i) << ", ";
        }
        std::cout << std::endl;

    // length of the slice (endIndex - startIndex + 1)
    int new_size = 4 - 2 + 1;
    
    std::cout << "size of array is " << size << std::endl;
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array is " << int_array.max() << " and " << int_array.min() << std::endl;

    //print sliced array.
    auto slice_array = int_array.slice(2,4);
    std::cout << "sliced array elements: ";
    for (int i = 0; i < new_size; ++i) 
    {
        std::cout << slice_array[i] << ", ";
    }
    std::cout << std::endl;
    
    //deallocating memory for the sliced array. 
    delete [] slice_array;
    return 0;
}
