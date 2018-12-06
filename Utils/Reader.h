#include <iostream>
#include <fstream>
#include <vector>
#include <string>



class Reader 
{
    public:
    Reader(std::ifstream &inptFile)
    :m_inpt(inptFile)
    {

    }

void read(const char* fName, std::vector<int> &callback)
    {
        std::string bfr;
        m_inpt.open(fName);
        while(std::getline(m_inpt, bfr))
        {
            if(bfr.size() > 0 )
            {
               callback.push_back(std::stoi(bfr));
            }
        }
        m_inpt.close();

    }
void read(const char* fName, std::vector<std::string> &callback)
    {
        std::string bfr;
        m_inpt.open(fName);
        while(std::getline(m_inpt, bfr))
        {
            if(bfr.size() > 0 )
            {
               callback.push_back(bfr);
            }
        }
        m_inpt.close();

    }   


    private:
    std::ifstream & m_inpt;
};