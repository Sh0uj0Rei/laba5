#include "entities.h"

Entities::Entities(int x, int y, char symbol) : x(x), y(y), symbol(symbol), direction(1) {}

int Entities::getX() const { return x; }
int Entities::getY() const { return y; }
char Entities::getSymbol() const { return symbol; }
