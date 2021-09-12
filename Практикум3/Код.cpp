#include <iostream>
#include<algorithm>
#include<type_traits>
using namespace std;

class Weapon
{
public:
	virtual int RangeDamage() const = 0;
	virtual int MeleeDamage() const = 0;
};
class Armor
{
public:
	virtual int RangeProtect() const = 0;
	virtual int MeleeProtect() const = 0;
};
class Race
{
public:
	virtual int MaxHealth() const = 0;
};
class Sword : public Weapon
{
public:
	 int RangeDamage() const override
	{
		return 1;
	}
	 int MeleeDamage() const override
	{
		return 20;
	}
};
class Shotgun : public Weapon
{
public:
	 int RangeDamage() const override
	{
		return 30;
	}
	 int MeleeDamage() const override
	{
		return 40;
	}
};
class Bow : public Weapon
{
public:
	 int RangeDamage() const override
	{
		return 10;
	}
	 int MeleeDamage() const override
	{
		return 3;
	}
};
class Helmet : public Armor
{
public:
	 int RangeProtect() const override
	{
		return  8;
	}
	 int MeleeProtect() const override
	{
		return 15;
	}
};
class Chain_Mail : public Armor
{
public:
	 int RangeProtect() const override
	{
		return  10;
	}
	 int MeleeProtect() const override
	{
		return 18;
	}
};
class Shield : public Armor
{
public:
	int RangeProtect() const override
	{
		return  7;
	}
	 int MeleeProtect() const override
	{
		return 10;
	}
};
class Orc : public Race
{
public:
	 int MaxHealth() const override
	{
		return 100;
	}
};
class Human : public Race
{
public:
	 int MaxHealth() const override
	{
		return 80;
	}
};
class Elf : public Race
{
public:
	 int MaxHealth() const override
	{
		return 90;
	}
};
template <class W, class A, class R>
class Unit
{
private:
	static_assert(is_base_of<Weapon, W>::value, "not in Weapons");
	static_assert(is_base_of<Armor, A>::value, "not in Armor");
	static_assert(is_base_of<Race, R>::value, "not in Race");
	W weapon;
	A armor;
	R race;
public:
	W getWeapon()
	{
		return weapon;
	}
	A getArmor()
	{
		return armor;
	}
	R getRace()
	{
		return race;
	}
	template <class W1, class A1, class R1>
	int Attak(Unit<W1, A1, R1>& unit)
	{
		return unit.getRace().MaxHealth() - max(weapon.RangeDamage() - unit.getArmor().RangeProtect(), 0) - max(weapon.MeleeDamage() - unit.getArmor().MeleeProtect(), 0);
	}
};

int main()
{
	int ans;
	Unit<Shotgun, Helmet, Orc> a;
	Unit<Sword, Shield, Elf> b;
	ans = a.Attak(b);
	cout <<"Health after the attack: "<< ans << endl;
	return 0;
}
