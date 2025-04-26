// Variant 3

#include <iostream>
#include <vector>

// 3 % 3 = 0 (Bubble sorting)
// Exercise 1 function
void bubbleSort(std::vector<int>& v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        for (size_t j = 0; j < v.size() - i - 1; ++j)
        {
            if (v[j] > v[j + 1])
            {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
            }
        }
    }
    // for (size_t i = 0; i < v.size(); ++i)
    // {
    //     std::cout << v[i] << " ";
    // }
    // std::cout << std::endl;
}


// Exercise 2 function




int main()
{
    // Exercise 1
    std::vector<int> v1 = {3, 5, 2, 7, 1, 8, 1, 15, 3};
    bubbleSort(v1);
    
    // Exercise 2
    // ex2();

    return 0;
}