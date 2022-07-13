#include <iostream>

using namespace std;class A
{
  public:
    virtual int getTotal() const { return getMoney() * getPeople(); };
    virtual int getMoney() const { return 50; };
  private:
    virtual int getPeople() const { return 4; };
};

class B : public A
{
  private:
    virtual int getPeople() const override { return 5; };
};

int main()
{
  A a.getTotal();    // 200;
  B b.getTotal();    // 250;
};