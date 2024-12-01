#include "entities.h"

Entities::Entities(int x, int y, char symbol, int speed)
    : x(x), y(y), symbol(symbol), speed(speed), direction(1) {}

int Entities::getX() const { return x; }
int Entities::getY() const { return y; }
char Entities::getSymbol() const { return symbol; }

