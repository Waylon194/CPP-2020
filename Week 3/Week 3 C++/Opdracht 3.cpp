#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<typename T>
std::vector<T> intersect(const std::vector<T>& v1, const std::vector<T>& v2);

int main()
{
    std::vector<std::string> v1{};
    std::vector<std::string> v2{};
    std::string input;

    std::cout << "Enter five strings for vector1:";
    while ((std::cin >> input))
    {
        v1.push_back(input);
        if (v1.size() == 5)
        {
            break;
        }
    }

    std::cout << "Enter five strings for vector2:";
    while ((std::cin >> input))
    {
        v2.push_back(input);
        if (v2.size() == 5)
        {
            break;
        }
    }

    std::vector<std::string> duplicates = intersect(v1, v2);
    for (auto elem : duplicates)
    {
        std::cout << elem << '\n';
    }
}

template<typename T>
std::vector<T> intersect(const std::vector<T>& v1, const std::vector<T>& v2)
{
    std::vector<T> duplicates;

    for (T elem1 : v1)
    {
        for (T elem2 : v2)
        {
            if (elem1.compare(elem2) == 0 && !(std::find(duplicates.begin(), duplicates.end(), elem1) != duplicates.end()))
            {
                duplicates.push_back(elem1);
            }
        }
    }
    return duplicates;
}