#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template<typename T>
void intersect(std::vector<T>& v);

int main()
{
    //Test numbers: 34, 5, 3, 5, 6, 4, 33, 2, 2, 4
    std::vector<int> tenIntegers{};
    int input;

    std::cout << "Enter ten integers:";
    while ((std::cin >> input))
    {
        tenIntegers.push_back(input);
        if (tenIntegers.size() == 10) {
            break;
        }
    }

    intersect(tenIntegers);
}

template<typename T>
void intersect(std::vector<T>& v)
{
    sort(v.begin(), v.end());
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());

    std::cout << "The distinct integers are ";
    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << ' ';
}