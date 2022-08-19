#include <iostream>
#include "IntArray.h"
#include"IntArray.cpp"
#include <exception>



int main()
{

        IntArray array(12);
        
        for (int i{ 0 }; i < 10; ++i)
            array[i] = i + 1;

        try
        {
            array.resize(8);
        }

        catch (exception& e)
        {
            cout << e.what() << endl;
        }
       
        
        try
        {
            array.insertBefore(20, 3);
        }

        catch (exception& e)
        {
            cout << e.what() << endl;
        }
     
        
        try
        {
            array.remove(3);
        }

        catch (exception& e)
        {
            cout << e.what() << endl;
        }
        
        array.insertAtEnd(30);
        array.insertAtBeginning(40);

       
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';

        std::cout << '\n';

        return 0;
    
   
   
}