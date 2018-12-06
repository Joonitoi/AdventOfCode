#include <iostream>
#include <vector>
#include "../Utils/Benchmark.h"
#include "../Utils/Reader.h"

void partOne()
{
    char abc[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};  

    std::ifstream inpt;
    Reader inptReader(inpt);
    std::vector<std::string> stringVec;
    inptReader.read("input.txt", stringVec);

    for(auto i : stringVec)
    {
        for(auto j : i)
        {

        }
    }
}



int main()
{
    
}