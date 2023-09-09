#include "statisticmove.h"
#include "character.h"

StatisticMove::StatisticMove(QString name, QString description, StatisticChanges statChange, CharType chTp)
    : Move(name, description, Type::Nill, chTp, 0, 0), changes(statChange) {}

StatisticMove::StatisticMove(QString name, QString description, StatisticChanges statChange, Type type)
    : Move(name, description, type, CharType::Nill, 0, 0), changes(statChange) {}


unsigned short StatisticMove::useMove(Character* attacker, Character* defender) const {
    unsigned short magAtk = attacker->getMagAtk(),
            magDef = defender->getMagDef(),
            coeff = magAtk / magDef;

    defender->setMagAtk(defender->getMagAtk() - changes.magicAtkChange * coeff);
    defender->setPhyAtk(defender->getPhyAtk() - changes.physicalAtkChange * coeff);
    defender->setMagDef(defender->getMagDef() - changes.magicDefChange * coeff);
    defender->setPhyDef(defender->getPhyDef() - changes.physicalDefChange * coeff);
    defender->setSpeed(defender->getSpeed() - changes.speedChange * coeff);
    return 0;
}
