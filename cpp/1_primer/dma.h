//
// Created by ZhuoYuan Chen on 6/29/17.
//

#ifndef HELLO_WORLD_DMA_H
#define HELLO_WORLD_DMA_H

#include <iostream>

using std::cout;
using std::endl;

// Base Class Using DMA
class baseDMA {
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public baseDMA {
private:
    enum { COL_LEN = 40};
    char color[COL_LEN]; public:
    lacksDMA(const char *c = "blank", const char * l = "null",
            int r = 0);
    lacksDMA(const char *c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const lacksDMA & rs);
};

// derived class with DMA
class hasDMA :public baseDMA {
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
            int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

void test_friend();

#endif //HELLO_WORLD_DMA_H
