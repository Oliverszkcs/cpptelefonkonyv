#ifndef LAKCIM_H_INCLUDED
#define LAKCIM_H_INCLUDED
#include <string>
using namespace std;

class Lakcim {
private:
    string lakcim;
public:
    Lakcim() { lakcim = ""; }
    Lakcim(const Lakcim& l) { this->lakcim = l.lakcim; }
    Lakcim(string cim) :lakcim(cim) {};
    string getcim()const {
        return lakcim;
    }
    Lakcim set(string cim) {
        this->lakcim = cim;
        return *this;
    }
    Lakcim operator=(const Lakcim& l) {
        this->lakcim = l.getcim();
        return *this;
    }
};

inline ostream& operator<<(ostream& os, const Lakcim& rhs) {        ///Kiir egy lakcim objektumot a megadott ostreamre
    os << rhs.getcim();
    return os;
}
#endif // LAKCIM_H_INCLUDED
