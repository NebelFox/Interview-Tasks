//
// Created by NebelFox on 15.06.2021.
//

#include "user.h"

const char* User::UserCreationException::what () const noexcept
{
    return "The name is empty or contains inappropriate characters";
}

const size_t User::_s_xpToNextLevel = 500;
const std::regex User::_s_userNamePattern ("[a-zA-Z0-9\\-._]+");

User::User (std::string && name, const size_t paidDays)
{
    if (name.empty () || !std::regex_match (name, User::_s_userNamePattern))
    {
        throw UserCreationException ();
    }
    this->_name = name;
    this->_paidDaysLeft = paidDays;
}

const std::string& User::name () const
{
    // Assuming that username shouldn't be modified via getter,
    // const reference fits nicely
    return this->_name;
}

size_t User::level () const
{
    return this->_level;
}

size_t User::xp () const
{
    return this->_xp;
}

size_t User::paidDaysLeft () const
{
    return this->_paidDaysLeft;
}

bool User::isPaid () const
{
    // automatically converts to bool
    return this->_paidDaysLeft;
}

void User::act (size_t xpAmount)
{
    // branchless way
    this->_xp += xpAmount * (this->_paidDaysLeft || this->_actionsLeft);
    // to avoid underflow as _actionsLeft is unsigned int type
    this->_actionsLeft -= (this->_actionsLeft > 0);
/*    if (this->_paidDaysLeft || this->_actionsLeft)
    {
        this->_xp += xpAmount;
        // to avoid underflow, as _actionsLeft is unsigned type
        this->_actionsLeft -= (this->_actionsLeft > 0);
    }*/
}

void User::_levelUpdate ()
{
    if (this->_xp >= User::_s_xpToNextLevel)
    {
        this->_xp -= User::_s_xpToNextLevel;
        ++this->_level;
    }
}

void User::_paidDaysUpdate ()
{
    // branchless way
    // to avoid underflow
    this->_paidDaysLeft -= (this->_paidDaysLeft > 0);
}

void User::nextDayUpdate ()
{
    this->_actionsLeft = 3;
    this->_levelUpdate ();
    this->_paidDaysUpdate ();
}