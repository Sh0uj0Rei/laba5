#include "entities.h"

class Alien : public Entities {
public:
    Alien(int x, int y, char type);
    void update() override;
};