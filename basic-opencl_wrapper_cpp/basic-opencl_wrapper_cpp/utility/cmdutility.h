#ifndef CMD_UTILITY_H
#define CMD_UTILITY_H
#include <ostream>

namespace utility {

namespace color {
enum Code {
    FG_RED      = 31,
    FG_GREEN    = 32,
    FG_BLUE     = 34,
    FG_DEFAULT  = 39,
    BG_RED      = 41,
    BG_GREEN    = 42,
    BG_BLUE     = 44,
    BG_DEFAULT  = 49
};
}

class Modifier {
private:
    color::Code code;
public:
    Modifier(color::Code code) : code(code) {}
    friend std::ostream& operator << (std::ostream& os, const Modifier& mod) {
        return os << "\033[" << mod.code << "m";
    }
};

}

#endif
