#pragma once

#include <exception>
using namespace std;

 class Bad_range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Error! exit outside of array";
    }
};

 class Bad_length : public exception
 {
 public:
     virtual const char* what() const noexcept override
     {
         return "Error!wrong array length";
     }
 };


class IntArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;
    IntArray(int length);
    ~IntArray();
    void erase();

    int& operator[](int index)
    {
        if (index < 0 && index > m_length)
        {
            throw Bad_range();
        }
        return m_data[index];
    }

    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int getLength() const;


};