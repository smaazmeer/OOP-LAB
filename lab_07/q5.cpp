#include <iostream>
#include <string>
using namespace std;

class Character
{
    private:
        int characterID;
        string name;
        int level;
        int healthPoints;
        string weaponType;

    public:
        Character(int id, string n, int lvl, int hp, string weapon = "")
        {
            characterID = id;
            name = n;
            level = lvl;
            healthPoints = hp;
            weaponType = weapon;
        }

        virtual void attack()
        {
            cout << name << " performs a basic attack." << endl;
        }

        virtual void defend()
        {
            cout << name << " defends with basic defense." << endl;
        }

        virtual void displayStats()
        {
            cout << "Character ID: " << characterID << endl;
            cout << "Name: " << name << endl;
            cout << "Level: " << level << endl;
            cout << "Health Points: " << healthPoints << endl;
            if (weaponType != "")
            {
                cout << "Weapon Type: " << weaponType << endl;
            }
        }
};

class Warrior : public Character
{
    private:
        int armorStrength;
        int meleeDamage;

    public:
        Warrior(int id, string n, int lvl, int hp, int armor, int dmg, string weapon = "")
            : Character(id, n, lvl, hp, weapon)
        {
            armorStrength = armor;
            meleeDamage = dmg;
        }

        void attack()
        {
            cout << "Warrior strikes with melee damage: " << meleeDamage << endl;
        }
};

class Mage : public Character
{
    private:
        int manaPoints;
        int spellPower;

    public:
        Mage(int id, string n, int lvl, int hp, int mana, int spell, string weapon = "")
            : Character(id, n, lvl, hp, weapon)
        {
            manaPoints = mana;
            spellPower = spell;
        }

        void defend()
        {
            cout << "Mage casts a magical barrier using " << manaPoints << " mana points." << endl;
        }
};

class Archer : public Character
{
    private:
        int arrowCount;
        float rangedAccuracy;

    public:
        Archer(int id, string n, int lvl, int hp, int arrows, float acc, string weapon = "")
            : Character(id, n, lvl, hp, weapon)
        {
            arrowCount = arrows;
            rangedAccuracy = acc;
        }

        void attack()
        {
            cout << "Archer fires arrows with " << rangedAccuracy << "% accuracy." << endl;
        }
};

class Rogue : public Character
{
    private:
        int stealthLevel;
        int agility;

    public:
        Rogue(int id, string n, int lvl, int hp, int stealth, int agi, string weapon = "")
            : Character(id, n, lvl, hp, weapon)
        {
            stealthLevel = stealth;
            agility = agi;
        }

        void displayStats()
        {
            Character::displayStats();
            cout << "Stealth Level: " << stealthLevel << endl;
            cout << "Agility: " << agility << endl;
        }
};

int main()
{
    Warrior w1(1, "Aazmeer", 20, 180, 50, 75, "Sword");
    Mage m1(2, "Irfan", 18, 120, 200, 90, "Staff");
    Archer a1(3, "Rameel", 15, 140, 30, 85.5, "Bow");
    Rogue r1(4, "Talha", 22, 160, 70, 95, "Daggers");

    cout << "--- Warrior Attack ---" << endl;
    w1.attack();

    cout << endl << "--- Mage Defend ---" << endl;
    m1.defend();

    cout << endl << "--- Archer Attack ---" << endl;
    a1.attack();

    cout << endl << "--- Rogue Stats ---" << endl;
    r1.displayStats();

    return 0;
}
