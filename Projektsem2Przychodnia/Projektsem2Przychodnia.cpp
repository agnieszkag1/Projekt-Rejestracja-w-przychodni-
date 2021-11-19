#include "Konsola.h"

int main() {
    auto konsola = new Konsola();
    konsola->start();
    delete konsola;

    return 0;
}
