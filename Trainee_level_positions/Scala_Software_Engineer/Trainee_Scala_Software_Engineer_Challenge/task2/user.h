//
// Created by NebelFox on 15.06.2021.
//

#ifndef TASK2_USER_H
#define TASK2_USER_H

#include <string>
#include "regex"

class User
{
private:
    std::string _name;
    size_t _paidDaysLeft;

    size_t _level = 0;
    size_t _xp = 0;
    unsigned short _actionsLeft = 3;

    static const size_t _s_xpToNextLevel;
    static const std::regex _s_userNamePattern;

public:
    struct UserCreationException : public std::exception
    {
        const char* what () const noexcept override;
    };
    // constructors
    explicit User (std::string && name, size_t paidDays=0);

    // getters
    const std::string& name () const;
    size_t level () const;
    size_t xp () const;
    size_t paidDaysLeft () const;
    bool isPaid () const;

    // interaction methods
    void act (size_t xpAmount);
    void nextDayUpdate ();

private:
    // state update methods
    void _levelUpdate ();
    void _paidDaysUpdate ();

};


#endif //TASK2_USER_H
