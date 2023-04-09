/*
Challenge time! The following quiz question is more difficult and lengthy.
We’re going to write a simple game where you fight monsters.
The goal of the game is to collect as much gold as you can before you die or get
to level 20.

Our program is going to consist of 3 classes: a Creature class,
a Player class, and a Monster class. Player and Monster both inherit from
Creature.

a) First create the Creature class. Creatures have 5 attributes:
A name (std::string), a symbol (a char), an amount of health (int),
the amount of damage they do per attack (int), and the amount of gold they are
carrying (int). Implement these as class members. Write a full set of getters (a
get function for each member). Add three other functions: void reduceHealth(int)
reduces the Creature’s health by an integer amount. bool isDead() returns true
when the Creature’s health is 0 or less. void addGold(int) adds gold to the
Creature.
*/
#include <iostream>
#include <string>
#include <string_view>

class Creature {
private:
  std::string m_name{};
  char m_symbol{};
  int m_health{};
  int m_attackDamage{};
  int m_gold;

public:
  Creature(std::string_view name, char symbol, int health, int attackDamage,
           int gold)
      : m_name{name}, m_symbol{symbol}, m_health{health},
        m_attackDamage{attackDamage}, m_gold{gold} {}

  const std::string &getName() { return m_name; }
  char getSymbol() { return m_symbol; }
  int getHealth() { return m_health; }
  int getAttackDamage() { return m_attackDamage; }
  int getGold() { return m_gold; }

  void reduceHealth(int amount) { m_health -= amount; }
  bool isDead() { return m_health <= 0; }
  void addGold(int amount) { m_gold += amount; }
};

int main() {
  Creature o{"orc", 'o', 4, 2, 10};
  o.addGold(5);
  o.reduceHealth(1);
  std::cout << "The " << o.getName() << " has " << o.getHealth()
            << " health and is carrying " << o.getGold() << " gold.\n ";

  return 0;
}
