#include <iostream>
#include "user.h"

int main ()
{
    try
    {
        User user ("John");
        std::cout << "Is user paid?: " << std::boolalpha << user.isPaid ();
    }
    catch (const User::UserCreationException & e)
    {
        std::cerr << e.what ();
        return 0;
    }
    return 0;
}
