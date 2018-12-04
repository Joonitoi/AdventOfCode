#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include "../Utils/Benchmark.h"

void firstPart()
{
    std::ifstream inpt;
    inpt.open("input.txt");
    std::string bfr;
    std::vector<int> freq;
    while(std::getline(inpt, bfr))
    {
        if(bfr.size() > 0)
        {
            freq.push_back(std::stoi(bfr));
        }
    }
    inpt.close();
int sum = 0;
for(auto line : freq)
{
  sum += line;
}
std::cout << "The result of the first part is: " << sum << std::endl;
}
void secondPart()
{
    int temp = 0;
    std::ifstream inpt;
    inpt.open("input.txt");
    std::string bfr;
    std::vector<int> freq;
    while(std::getline(inpt, bfr))
    {
        if(bfr.size() > 0)
        {
            freq.push_back(std::stoi(bfr));
        }
    }
    std::unordered_set<int> match;
while(true)
{
    for(auto i : freq)
    {
        temp += i;
        if(match.find(temp) != match.end())
        {
            std::cout << "The result of the second part is: "<< temp << std::endl;
            return;
        }
        else 
        {
            match.insert(temp);
        }   
    }
}
}

int main()
{
Benchmark<100> fPbm("First part: ", &firstPart);
Benchmark<100> sPbm("Second part: ", &secondPart);
Benchmark<100> allbm("Both parts: ", []{  firstPart();secondPart(); });
fPbm.outputTimes();
sPbm.outputTimes();
allbm.outputTimes();

std::cin.get();
}