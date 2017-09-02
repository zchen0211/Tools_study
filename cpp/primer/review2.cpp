//
// Created by ZhuoYuan Chen on 6/28/17.
//
#include "review2.h"


// constructor definition
Stock::Stock() {
    std::cout << "Default constructor called\n";
    std::strcpy(company, "no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char * co, int n, double pr) {
    std::strncpy(company, co, 29); company[29] = '\0';
    if (n < 0) {
        std::cerr << "Number of shares can’t be negative; " << company << "shares set to 0.\n";
        shares = 0; }
    else
        shares = n;
    share_val = pr;
    set_tot(); }

// class destructor
Stock::~Stock() {
    // verbose class destructor
    std::cout << "Bye, " << company << "!\n";
}

//more stocks.cpp -- implementing the class member functions
void Stock::acquire(const char * co, int n, double pr)
{
    std::strncpy(company, co, 29); // truncate co to fit company company[29] = ‘\0’;
    if (n < 0) {
    std::cerr << "Number of shares can’t be negative; " << company << " shares set to 0.\n";
    shares = 0; }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(int num, double price) {
    if (num < 0) {
        std::cerr << "Number of shares purchased can’t be negative. "
                  << "Transaction is aborted.\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price) {
    using std::cerr;
    if (num < 0) {
        cerr << "Number of shares sold can’t be negative. " << "Transaction is aborted.\n";
    } else if (num > shares) {
        cerr << "You can’t sell more than you have! " << "Transaction is aborted.\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() {
    using std::cout;
    using std::endl;
    cout << "Company: " << company
         << " Shares: " << shares << endl
         << " Share Price: $" << share_val
         << " Total Worth: $" << total_val << endl;
}

Stock::Stock(const Stock & s) {
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;
}


Stock & Stock::operator=(const Stock & s) {
    if (this==&s)
        return *this;
    strcpy(company, s.company);
    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;

    return *this;
}

bool operator<(const Stock &st1, const Stock &st2) {
    if (std::strcmp(st1.company, st2.company) > 0) return true;
    else
        return false;
}

bool operator>(const Stock &st1, const Stock &st2) {
    if (std::strcmp(st1.company, st2.company) < 0) return true;
    else
        return false;
}

bool operator==(const Stock &st1, const Stock &st2) {
    if (std::strcmp(st1.company, st2.company) == 0) return true;
    else
        return false;
}

std::ostream & operator<<(std::ostream & os, const Stock & st) {
    os << st.company;
    return os;
}

std::istream & operator>>(std::istream & is, Stock & st) {
    is >> st.company;
    return is;
}

void test_class1() {
    Stock sally;
    Stock solly;
    // create an array of initialized objects
    Stock stocks[STKS] = {
            Stock("NanoSmart", 12, 20.0),
            Stock("Boffo Objects", 200, 2.0),
            Stock("Monolithic Obelisks", 130, 3.25),
            Stock("Fleep Enterprises", 60, 6.5)
    };
}

void test_class2() {
    const int BUF = 512;
    char * buffer = new char[BUF];
    JustTesting *pc1, *pc2;
    pc1 = new (buffer) JustTesting;
    pc2 = new JustTesting("Heap1", 20); // place object on heap
    cout << "Memory block addresses:\n" << "buffer: "
         << (void *) buffer << "heap: " << pc2 << endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();
    delete pc2;
    delete [] buffer;
}