#include <iostream>

#include "macros/progressive.hpp"

class assignment_proxy
{
};

template <typename type> void operator << (type &, assignment_proxy)
{
}

class transaction
{
public:
  
    int entrypoint = 0;
    
    virtual void run() = 0;
    
    assignment_proxy receive()
    {
        return assignment_proxy {};
    }
    
    void wake()
    {
        this->run();
    }
};

#define entry case 0

#define async \
bool __skip__ = false;\
switch(this->entrypoint)

#define await \
this->entrypoint = __LINE__;\
__skip__ = true;\
case __LINE__:\
if(__skip__) return

class my_transaction : public transaction
{
public:
    
    int my_int;
    int my_other_int;
    
    void run()
    {
        async
        {
        entry:
            
            std :: cout << "Prima" << std :: endl;
            await my_int << receive();
            std :: cout << "Dopo" << std :: endl;
            
            for(my_other_int = 0; my_other_int < 10; my_other_int++)
            {
                std :: cout << my_other_int << std :: endl;
                await my_int << receive();
            }
        }
    }
};

int g()
{
    return 3;
}

void non_ritoro_niente()
{
}

void devo_ritornare_void()
{
    return  /**/ g();
}

int main()
{
}
