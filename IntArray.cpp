#include<iostream>
#include"IntArray.h"
#include <exception>
#pragma once


inline IntArray::IntArray(int length) :m_length(length)
 {
    if (length < 0)
      {
        throw Bad_length();
      }


    if (length > 0)
      {
         m_data = new int[length] {};
      }
 }


inline IntArray::~IntArray()
{

    delete[] m_data;

}

inline void IntArray::erase()
{

    delete[] m_data;
    m_data = nullptr;
    m_length = 0;

}

inline void IntArray::reallocate(int newLength)
{

    erase();
    if (newLength <= 0)
        return;

    m_data = new int[newLength];
    m_length = newLength;

}

inline void IntArray::resize(int newLength)
{
    if (newLength < 0)
    {
        throw Bad_length();
    }

    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    delete[] m_data;
    m_data = data;
    m_length = newLength;

}

inline void IntArray::insertBefore(int value, int index)
{
    if (index > m_length)
    {
        throw Bad_range();
    }
    
    
        int* data{ new int[m_length + 1] };
        for (int before{ 0 }; before < index; ++before)
            data[before] = m_data[before];
        data[index] = value;
        for (int after{ index }; after < m_length; ++after)
            data[after + 1] = m_data[after];
        delete[] m_data;
        m_data = data;
        ++m_length;
    
}

inline void IntArray::remove(int index)
{
    if (index > m_length)
    {
        throw Bad_range();
    }


    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data{ new int[m_length - 1] };
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];
    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];
    delete[] m_data;
    m_data = data;
    --m_length;

}

inline void IntArray::insertAtBeginning(int value)
{

    insertBefore(value, 0);

}

inline void IntArray::insertAtEnd(int value)
{

    insertBefore(value, m_length);

}

inline int IntArray::getLength() const
{
    return m_length;

}


