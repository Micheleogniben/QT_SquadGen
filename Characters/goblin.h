#ifndef GOBLIN_H
#define GOBLIN_H

#include "character.h"


class Goblin : public Character
{
private:
    unsigned short amount;
public:
    Goblin(QString, unsigned short);
    Goblin(const Goblin&);
    bool useAbility(Character*) override;
    void setLifePoints(const unsigned short) override;
    unsigned short getWeight() const override;

    unsigned short getAmount() const;
    void setAmount(unsigned short);

    QJsonObject toJsonObj() const override;
};

#endif // GOBLIN_H
