#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CharacterActions
{
public:
    virtual void attack() = 0;
    virtual void defend(int damage) = 0;
    virtual void useSpecialAbility() = 0;
    virtual void displayStats() const = 0;
    virtual bool isAlive() const = 0;
    virtual ~CharacterActions() = default;
};

class BaseCharacter : public CharacterActions
{
public:
    string name;
    int health;
    int mana;

    int attackPower;
    int specialAbilityPower;

    BaseCharacter(string n, int h, int m, int a, int s)
        : name(n), health(h), mana(m), attackPower(a), specialAbilityPower(s) {}

    void attack()
    {
        cout << name << "attacks with power" << attackPower << "!\n";
        mana += 50;
    }

    void defend(int damage)
    {
        health -= damage;

        cout << name << " takes " << damage << " damage! Health now: " << health << "\n";
    }

    virtual void useSpecialAbility() = 0;

    void displayStats() const
    {
        cout << "Name: " << name << ", Health: " << health << ", Mana: " << mana << "\n";
    }

    bool isAlive() const
    {
        return health > 0;
    }
};

class Warrior : public BaseCharacter
{
public:
    Warrior() : BaseCharacter("Warrior", 100, 0, 25, 35) {}

    void useSpecialAbility()
    {
        if (mana >= 100)
        {
            cout << name << " uses Berserk Rage with power " << specialAbilityPower << "!\n";
            mana = 0;
        }
        else
        {
            cout << name << " does not have enough mana to use Berserk Rage.\n";
        }
    }
};

class Mage : public BaseCharacter
{
public:
    Mage() : BaseCharacter("Mage", 120, 0, 20, 30) {}

    void useSpecialAbility()
    {
        if (mana >= 100)
        {
            cout << name << " uses Arcane Blast with power " << specialAbilityPower << "!\n";
            mana = 0;
        }
        else
        {
            cout << name << " does not have enough mana to use Arcane Blast.\n";
        }
    }
};

class Archer : public BaseCharacter
{
public:
    Archer() : BaseCharacter("Archer", 90, 0, 20, 35) {}

    void useSpecialAbility()
    {
        if (mana >= 100)
        {
            cout << name << " uses Fire Arrow with power " << specialAbilityPower << "!\n";
            mana = 0;
        }
        else
        {
            cout << name << " does not have enough mana to use Fire Arrow.\n";
        }
    }
};

class BossEnemy
{
public:
    string name;
    int health;
    int attackPower;

public:
    BossEnemy(string n, int h, int a) : name(n), health(h), attackPower(a) {}

    void attack(BaseCharacter &character)
    {
        cout << name << " attacks " << character.name << " with power " << attackPower << "!\n";
        character.defend(attackPower);
    }

    void defend(int damage)
    {
        health -= damage;
        cout << name << " takes " << damage << " damage! Health now: " << health << "\n";
        if(health<0){
            return;
        }
    }

    bool isAlive() const
    {
        return health > 0;
    }
};

class GameEngine
{

public:
    void playGame()
    {
        Warrior warrior;
        Mage mage;
        Archer archer;

        BossEnemy boss("Boss", 150, 30);
        cout << "Game begins! Players vs. Boss" << endl;

        while ((warrior.isAlive() && mage.isAlive() && archer.isAlive()) && boss.isAlive())
        {
            
            if (warrior.isAlive())
            {   warrior.attack();
                boss.defend(warrior.attackPower);
                if(warrior.mana >= 100){
                warrior.useSpecialAbility();
                boss.defend(warrior.specialAbilityPower);
                }
            }
            if (mage.isAlive())
            {
                mage.attack();
                boss.defend(mage.attackPower);
                if(mage.mana >= 100){
                mage.useSpecialAbility();
                boss.defend(mage.specialAbilityPower);
                }
            }
            if (archer.isAlive())
            {
                archer.attack();
                boss.defend(archer.attackPower);
                if(archer.mana >= 100){
                archer.useSpecialAbility();
                boss.defend(archer.specialAbilityPower);
                }
            }

            if (boss.isAlive())
            {
                if (warrior.isAlive())
                {
                    boss.attack(warrior);
                    
                }
                if (mage.isAlive())
                {
                    boss.attack(mage);
                    
                }
                if (archer.isAlive())
                {
                    boss.attack(archer);
                    
                }
            }

            
        }

        if (!boss.isAlive())
        {
            cout << "Boss defeated! Players win!" << endl;
        }
        else
        {
            cout << "Players defeated! Boss wins!" << endl;
        }
    }
};

int main()
{
    GameEngine game;
    game.playGame();
    return 0;
}