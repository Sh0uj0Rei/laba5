#include "entities.h"

class Bullet : public Entities {
public:
    Bullet(int x, int y);
    void update() override;
};