//
// Created by ZhuoYuan Chen on 6/29/17.
//

#include "review3.h"

#include <iostream>
#include <cstring>

using namespace std;

TableTennisPlayer::TableTennisPlayer (const char * fn, const char * ln, bool ht)
{
    std::strncpy(firstname, fn, LIM - 1);
    firstname[LIM - 1] = '\0';
    std::strncpy(lastname, ln, LIM - 1);
    lastname[LIM - 1] = '\0';
    hasTable = ht;
}


void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const char * fn,
                         const char * ln, bool ht) : TableTennisPlayer(fn, ln, ht)
{
    // base class constructor will call first
    rating = r;
}


RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r)
{}

/* 2nd Case Study of Derived Class */
// Abstract Base Class
AcctABC::AcctABC(const char *s, long an, double bal) {
    std::strncpy(fullName, s, MAX - 1);
    fullName[MAX - 1] = '\0';
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt) {
    if (amt < 0)
        cout << "Negative deposit not allowed; "
             << "deposit is cancelled.\n";
    balance += amt;
}
void AcctABC::Withdraw(double amt) {
    balance -= amt;
}

// protected method
ios_base::fmtflags AcctABC::SetFormat() const {
    // set up ###.## format
    ios_base::fmtflags initialState =
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    return initialState;
}

/*Brass::Brass(const char *s, long an, double bal) {
    std::strncpy(fullName, s, MAX - 1);
    fullName[MAX - 1] = '\0';
    acctNum = an;
    balance = bal;
}
*/

void Brass::Deposit(double amt) {
    if (amt < 0)
        std::cout << "Negative deposit not allowed; "
                  << "deposit is cancelled.\n";
    balance += amt;
}

void Brass::Withdraw(double amt) {
    if (amt < 0)
        std::cout << "Withdrawal amount must be positive; "
                  << "withdrawal canceled.\n";
    else if (amt <= balance)
        AcctABC::Withdraw(amt); // call base class: balance -= amt;
    else
        std::cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n"
                  << "Withdrawal canceled.\n";
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    // set up ###.## format
    std::ios_base::fmtflags initialState =
        std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.setf(std::ios_base::showpoint);
    std::cout.precision(2);
    std::cout << "Client: " << fullName << std::endl;
    std::cout << "Account Number: " << acctNum << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    std::cout.setf(initialState); // restore original format
}

// BrassPlus Methods
BrassPlus::BrassPlus(const char *s, long an, double bal,
                     double ml, double r) : Brass(s, an, bal) {
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
        : Brass(ba) // uses implicit copy constructor
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// redefine how ViewAcct() works
void BrassPlus::ViewAcct() const {
    // set up ###.## format
    ios_base::fmtflags initialState =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout.precision(2);
    Brass::ViewAcct(); // display base portion
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";
    cout.setf(initialState);
}

// redefine how Withdraw() works
void BrassPlus::Withdraw(double amt) {
    ios_base::fmtflags initialState = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if ( amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    cout.setf(initialState);
}

void test_derived1() {
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn’t a table.\n";
    player2.Name();
    if (player2.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn’t a table.\n";
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    rplayer1.Name(); // derived object uses base method
    if (rplayer1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn’t a table.\n";
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
}

void test_derived2() {
    Brass dom("Dominic Banker", 11224, 4183.45);
    BrassPlus dot("Dorothy Banker", 12118, 2592.00);
    dom.ViewAcct(); // use Brass::ViewAcct()
    dot.ViewAcct(); // use BrassPlus::ViewAcct()

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "Depositing $1000 into the Hogg Account:\n";
    Hoggy.Deposit(1000.00);
    cout << "New balance: $" << Hoggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Pigg Account:\n";
    Piggy.Withdraw(4200.00);
    cout << "Pigg account balance: $" << Piggy.Balance() << endl;
    cout << "Withdrawing $4200 from the Hogg Account:\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();
}

void test_derived3() {
    Brass * p_clients[2];
    p_clients[0] = new Brass("Name1", 121213, 30.0);
    p_clients[1] = new BrassPlus("Name2", 121314, 30.0, 500, .1);
    p_clients[0]->ViewAcct();
    p_clients[1]->ViewAcct();
}