
#include "entities.h"

class Player : public Entities {
private:
    int lives;

public:
    Player(int x, int y);
    void update() override;
    void shoot();
    int getLives() const;
    void loseLife();
};


