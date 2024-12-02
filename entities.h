#ifndef ENTITIES_H
#define ENTITIES_H

class Entities {
public:
    int x, y;
    char symbol;
    int direction; // Направление движения (вправо или влево)

    Entities(int x, int y, char symbol);
    virtual void update() = 0; // Чисто виртуальная функция для обновления состояния
    int getX() const;
    int getY() const;
    char getSymbol() const;
};

#endif // ENTITIES_H
