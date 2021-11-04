#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <sstream>
#include "base.hpp"

class Rand : public Base {
    private:
        double value;
    public:
        Rand(): Base() {
            this->value = rand() % 100;
        }
        virtual double evaluate() {
            return value;
        }
        virtual std::string stringify() {
            std::ostringstream sstream;
            sstream << value;
            return sstream.str();
        }
};

#endif //__RAND_HPP__
