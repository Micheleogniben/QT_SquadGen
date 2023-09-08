#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include <character.h>
#include <move.h>
#include <squad.h>
#include <QMessageBox>
#include <boss.h>
#include <random>
#include <movesmanager.h>
#include <vector>

class BattleManager
{
private:
    Squad* team1, * team2;
    unsigned int turn;
public:
    BattleManager(Squad*,Squad*);
    bool setTeam(Squad*,int);
    void setBossBattle(MovesManager*);
    void attack(Move*);
    void ability();
    void removeDeadCharacter(QString);
    void endBattle();
    int getTurn() const;
    void updateTurn();
    Squad* getTeam(int) const;
    void update();
    void removeDeadCharacters(Squad*);
    void opponentKombatLogic();
    ~BattleManager();
};

#endif // BATTLEMANAGER_H
