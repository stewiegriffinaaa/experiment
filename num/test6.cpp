#include<iostream>
#include<string>
using namespace std;
class Hero
{
protected:
  int HP,damage;
public:
  string name;
  Hero(string name = "",int HP = 100,int damage = 0):name(name),HP(HP),damage(damage){}
  virtual void Attack(Hero *hero) = 0;
  virtual void Attacked(int dmg,Hero *hero) = 0;
  virtual ~Hero(){}
};
class Magician:public Hero{
public:
  Magician(string name="",int HP = 100,int damage = 0):Hero(name,HP,damage){}
  void Attack(Hero* hero){
    cout << this->name << " attacks " << hero->name << endl;
    hero->Attacked(this->damage,this);
  }
  void Attacked(int dmg,Hero* hero){
    this->HP = this->HP - dmg;
    if(this->HP <= 0)
      this->HP = 0;
    cout << this->name << " is attacked by " << hero->name << " HP = " << this->HP << endl;
  }
  ~Magician(){
    cout << this->name << " is dead!" << endl;
  }
};
class Tank:public Hero
{
  int defence;
public:
  Tank(string name = "",int HP = 100,int damage = 0,int defence = 100):Hero(name,HP,damage),defence(defence){}
  void Attack(Hero *hero){
    cout << this->name << " can't be attacked " << endl;
  }
  void Attacked(int dmg,Hero *hero){
    cout << hero->name << "attacks" << this->name;
    cout << "invaild" << endl;
    cout << "damage come back to " << hero->name << endl;
    hero->Attacked(this->defence*0.3,this);
  }
  ~Tank(){
    cout << this->name << "end " << endl;
  }
};
class Warrior:public Hero
{
  int defence;
public:
  Warrior(string name = "",int HP = 100,int damage = 0,int defence = 100):Hero(name,HP,damage),defence(defence){}
  void Attack(Hero *hero){
    cout << this->name << " attacks " << hero->name << endl;
    hero->Attacked(this->damage,this);
  }
  void Attacked(int dmg,Hero* hero){
    this->HP -= dmg;
    if(this->HP <= 0)
      this->HP = 0;
    cout << this->name << " is attcked by " << hero->name << " HP = " << this->HP << endl;
    cout << "damage come back to " << hero->name << endl;
    hero->Attacked(this->defence*0.1,this);
  }
  ~Warrior(){
    cout << this->name << " end " << endl;
  }
};
int main(){
  Hero *magician = new Magician("magician",1000,200);
  Hero *tank = new Tank("tank",10000,0,100);
  Hero *warrior = new Warrior("warrior",5000,100,100);
  magician->Attack(tank);
  cout << endl;
  magician->Attack(warrior);
  cout << endl;
  tank->Attack(magician);
  cout << endl;
  warrior->Attack(magician);
  cout << endl;
  delete magician;
  delete tank;
  delete warrior;
  return 0;
}















