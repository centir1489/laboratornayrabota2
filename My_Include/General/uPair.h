#pragma once
#ifndef U_PAIR
#define U_PAIR
#include<ostream>

template<typename Fgen_t, typename Sgen_t>
struct uPair{
    Fgen_t first;
    Sgen_t second;
    uPair() : first(), second(){}
    uPair(Fgen_t once, Sgen_t secnce) : first(once), second(secnce) {}

    uPair(const uPair& othrPair){
        first = othrPair.first;
        second = othrPair.second;
    }

    // uPair<Fgen_t, Sgen_t>& operator=(const uPair<Fgen_t, Sgen_t> othrPair){
    //     if(this != othrPair){
    //         first = othrPair.first;
    //         second = othrPair.second;
    //     }
    //     return *this;
    // }
    

    friend std::ostream& operator<<(std::ostream& os, uPair<Fgen_t, Sgen_t> pair){
        os << '{' << pair.first << " : " << pair.second << '}';
        return os;
    }
};

#endif