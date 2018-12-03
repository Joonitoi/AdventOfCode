#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../Utils/Benchmark.h"

void firstPart()
{
    std::ifstream inpt;
    inpt.open("input.txt");
    std::string bfr;
    std::vector<std::string> stringVec;
    while(std::getline(inpt, bfr))
    {
        if(bfr.size() > 0)
        {
            stringVec.push_back(bfr);
        }
    }
    inpt.close();
int sum = 0;
for(std::string line : stringVec)
{
  int val = std::stoi(line);
  sum += val;
}
std::cout << sum << std::endl;
}




int main()
{
Benchmark<100> fPbm("First part: ", &firstPart);
fPbm.outputTimes();
std::cin.get();
}