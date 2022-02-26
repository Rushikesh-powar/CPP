// Array.h

/**
 * @file Array.h
 * This header file can be imported directly.
 * @author Rushi Powar.
 * @date 02/2022
 */

#ifndef ARRAY_H // include guard
#define ARRAY_H

/**
 * @brief A standerd container which offers access to all elements of array
 * in any order.In sort a %Array can be described as a dynamic
 * C-style array, it offers fast and efficient access to individual
 * elements in any order and saves the user from worrying about
 * memory and size allocation, with additional functionalities like
 * Sort, Append, Delete, etc.
 *
 * @ingroup sequences.
 *
 * @tparam T Type of Array.
 * @tparam s Size of Array.
 */
template <typename T, int s>
class Array
{
private:
    int _size{};         // initialized to 0.
    bool _sorted{false}; // initialized to false.
    bool _reversed{false};
    T *ptr;

    int _del(T value);

public:
    /**
     * @brief Builds a %Array from an user-array.
     * @param arr[] an user defined array.
     */
    Array(const T arr[]);

    /**
     * @brief Builds a %Array from an initializer_list.
     * @param list an initalizer_list.
     */
    Array(const std::initializer_list<T> list);

    /**
     * @brief prints all elements of %Array.
     * @param newLine if true the prints each element on new line,
     * if false then prints all elements on a single line.
     */
    void printArray(bool newLine = true);

    /**
     * @brief returns total length of %Array.
     * @returns int type length of %Array
     */
    int len();

    /**
     * @brief returns an element at a specific index.
     * @param index array index of value.
     * @returns value at index in %Array if index is valid,
     * else nothing is returned.
     */
    T getValue(int index);

    /**
     * @brief returns index of an item.
     * @param element element in %Array.
     * @returns index/key of the item which is present in %Array.
     * if item not present inside %Array then -1 is returned.
     */
    int getKey(T element);

    /**
     * @brief appends an element at the end of %Array.
     * @param element element which is to be added.
     */
    void append(T element);

    /**
     * @brief assign/reassign an element to an index in %Array.
     * @param index array index to be modified.
     * @param element element which is to be assigned to index.
     */
    void setValue(int index, T element);

    /**
     * @brief to sort elements of %Array.
     * by default %Array is sorted in Ascending order.
     * @param reverse sort in reverse/Decending order.
     */
    void sort(bool reverse = false);

    /**
     * @brief remove an index from %Array.
     * @param index index value to be deleted.
     */
    void delKey(int index);

    /**
     * @brief remove an element from %Array.
     * @param element element to be deleted.
     */
    void delValue(T element);

    // Destructor.
    ~Array();
};

template <typename T, int s>
Array<T, s>::Array(const T arr[])
{
    this->_size = s;
    // ptr = new T[s];
    this->ptr = new T[s];

    for (int i = 0; i < s; i++)
    {
        this->ptr[i] = arr[i];
    }
    delete arr;
}

template <typename T, int s>
Array<T, s>::Array(const std::initializer_list<T> list)
{
    int list_len = list.size(), i;

    if (s > list_len)
        this->_size = s;
    else
        this->_size = list_len;

    // ptr = new T[list_len];
    this->ptr = new T[s];

    for (i = 0; i < list_len; i++)
        this->ptr[i] = (list.begin())[i];
}

template <typename T, int s>
void Array<T, s>::printArray(bool newLine)
{
    if (newLine)
        for (int i = 0; i < _size; i++)
            std::cout << this->ptr[i] << "\n";
    else
        for (int i = 0; i < _size; i++)
            std::cout << this->ptr[i] << " ";
}

template <typename T, int s>
int Array<T, s>::len()
{
    return this->_size;
}

template <typename T, int s>
T Array<T, s>::getValue(int index)
{
    if (0 <= index < this->_size)
        return this->ptr[index];
}

template <typename T, int s>
int Array<T, s>::getKey(T element)
{
    if (this->ptr[0] == element)
        return 0;

    else if (this->ptr[_size] == element)
        return this->_size;

    else
    {
        for (int i = 0; i < _size; i++)
        {
            if (this->ptr[i] == element)
            {
                return i;
            }
        }
    }

    std::cout << "Array does not contain " << element << "\n";
    return -1;
}

template <typename T, int s>
void Array<T, s>::append(T element)
{
    this->ptr[this->_size] = element;
    this->_size++;
}

template <typename T, int s>
void Array<T, s>::setValue(int index, T element)
{
    if (index < 0)
        std::cout << "Invalid Index"
                  << "\n";
    else
    {
        if (index < this->_size)
        {
            this->ptr[index] = element;
        }
        else
            std::cout << "Index out of bound"
                      << "\n";
    }
}

template <typename T, int s>
void Array<T, s>::sort(bool reverse)
{
    if (reverse)
    {
        if (!this->_reversed)
        {
            std::sort(this->ptr, this->ptr + this->_size, std::greater<int>());
            this->_reversed = true;
        }
    }
    if (!this->_sorted)
    {
        std::sort(this->ptr, this->ptr + this->_size);
        this->_sorted = true;
    }
}

template <typename T, int s>
void Array<T, s>::delKey(int index)
{
    T value = this->getValue(index);
    this->_size = this->_del(value);
}
template <typename T, int s>
void Array<T, s>::delValue(T element)
{
    if (this->getKey(element) != -1)
        this->_size = this->_del(element);
}

template <typename T, int s>
int Array<T, s>::_del(T value)
{
    // If x is last element, nothing to do
    if (this->ptr[this->_size - 1] == value)
        return (this->_size - 1);

    // Start from rightmost element and keep moving
    // elements one position ahead.
    T prev = this->ptr[this->_size - 1];
    int i;
    for (i = this->_size - 2; i >= 0 && this->ptr[i] != value; i--)
    {
        T curr = this->ptr[i];
        this->ptr[i] = prev;
        prev = curr;
    }

    // If element was not found
    if (i < 0)
        return 0;

    // Else move the next element in place of value
    this->ptr[i] = prev;

    return (this->_size - 1);
}

template <typename T, int s>
Array<T, s>::~Array()
{
    free(this->ptr);
}

template <typename T, int n>
int findSize(T (&arr)[n])
{
    std::cout << n << std::endl;
    return n;
};
#endif /* ARRAY_H */