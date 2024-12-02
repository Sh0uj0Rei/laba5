#ifndef ALIEN_H
#define ALIEN_H

#include "entities.h"

class Alien : public Entities {
public:
    Alien(int x, int y);
    void update() override;
};

#endif // ALIEN_H
