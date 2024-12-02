#ifndef BULLET_H
#define BULLET_H

#include "entities.h"

class Bullet : public Entities {
public:
    Bullet(int x, int y);
    void update() override;
};

#endif // BULLET_H
