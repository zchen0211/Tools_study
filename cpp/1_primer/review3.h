//
// Created by ZhuoYuan Chen on 6/29/17.
//

#ifndef HELLO_WORLD_REVIEW3_H
#define HELLO_WORLD_REVIEW3_H

#include <iostream>

class TableTennisPlayer {
private:
    enum{LIM = 20};
    char firstname[LIM];
    char lastname[LIM];
    bool hasTable;
public:
    TableTennisPlayer (const char * fn = "none",
                       const char * ln = "none", bool ht = false);
    void Name() const;
    bool HasTable() const { return hasTable; };
    void ResetTable(bool v) { hasTable = v; };
};

class RatedPlayer : public TableTennisPlayer {

private:
    unsigned int rating; // add a data member

public:
    RatedPlayer (unsigned int r = 0, const char * fn = "none",
                 const char * ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
    unsigned int Rating() { return rating; } // add a method
    void ResetRating (unsigned int r) {rating = r;} // add a method
};

// Brass Account Class
// Abstract Base Class
class AcctABC {
private:
    enum {MAX = 35};
    char fullName[MAX];
    long acctNum;
    double balance;

protected:
    const char * FullName() const {return fullName;}
    long AcctNum() const {return acctNum;}
    std::ios_base::fmtflags SetFormat() const;

public:
    AcctABC(const char *s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt) = 0; // pure virtual function
    double Balance() const {return balance;};
    virtual void ViewAcct() const = 0; // pure virtual function
    virtual ~AcctABC() {}
};

class Brass : public AcctABC
{
private:
    enum {MAX = 35};
    char fullName[MAX];
    long acctNum;
    double balance;
public:
    Brass(const char *s = "Nullbody", long an = -1,
         double bal = 0.0) : AcctABC(s, an, bal) {}
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass() {}
};

//Brass Plus Account Class
class BrassPlus : public Brass {
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus (const char *s = "Nullbody", long an = -1,
               double bal = 0.0, double ml = 500, double r = 0.10);
    BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; };
    void ResetOwes() { owesBank = 0; }
};

// Abstract Base Class (ABC)
class BaseEllipse { // abstract base class
// When a class declaration contains a pure virtual function, you can’t create an object of that
private:
    double x;   // x-coordinate of center
    double y;   // y-coordinate of center
    //...
public:
    BaseEllipse(double x0 = 0, double y0 = 0) : x(x0),y(y0) {}
    virtual ~BaseEllipse() {}
    void Move(int nx, int ny) { x = nx; y = ny;}
    virtual double Area() const = 0; // a pure virtual function by "=0"
    // ...
};

void test_derived1();
void test_derived2();
void test_derived3();

#endif //HELLO_WORLD_REVIEW3_H
