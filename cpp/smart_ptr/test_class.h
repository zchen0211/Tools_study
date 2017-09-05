#ifndef TEST_CLASS_H_
#define TEST_CLASS_H_

#include <string>

class Test
{
public:
    Test(std::string s)
    {
       str = s;
       std::cout << "Test create\n";
    }
    ~Test()
    {
        std::cout << "Test delete:" << str << std::endl;
    }
    std::string& getStr()
    {
        return str;
    }
    void setStr(std::string s)
    {
        str = s;
    }
    void print()
    {
        std::cout << str << std::endl;
    }
private:
    std::string str;
};

#endif
