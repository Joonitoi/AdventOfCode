#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "../Utils/Benchmark.h"
#include "../Utils/Reader.h"



//Day 1 Part 1
void firstPart()
{
    std::ifstream inpt;
    Reader inptReader(inpt);
    std::vector<int> freq;
    inptReader.read("input.txt", freq);
int sum = 0;
for(auto line : freq)
{
  sum += line;
}
std::cout << "The result of the first part is: " << sum << std::endl;
}




//Day 1 Part 2
void secondPart()
{
    int temp = 0;
    std::ifstream inpt;
   Reader inptReader(inpt);
    std::vector<int> freq;
    inptReader.read("input.txt", freq);
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


//Main function, this is where we do the benchmarks
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