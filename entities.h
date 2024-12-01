#ifndef ENTITIES_H
#define ENTITIES_H

class Entities {
protected:
    int x, y;
    char symbol;
    int direction; // 1 - вправо, -1 - влево
    int speed;

public:
    Entities(int x, int y, char symbol, int speed);
    virtual void update() = 0;
    int getX() const;
    int getY() const;
    char getSymbol() const;
};

#endif // ENTITIES_H