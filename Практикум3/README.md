Создать абстрактные классы Weapon (методы RangeDamage, MeleeDamage), Armor (методы RangeProtect, MeleeProtect), Race (метод MaxHealth)
Создать несколько классов-наследников от каждого из классов (например, Human, Orc, Elf - для Race).

Создать шаблонный класс Unit с 3 параметрами - W,A,R.
Реализовать методы Attack(Unit&), реализующий формулу
MaxHealth - min(max(RangeDamage - RangeProtect,0),0) - min(max(MeleeDamage - MeleeProtect,0),0).

Реализовать проверки с помощью type_traits и static_assert:
W - класс наследник Weapon
A - класс наследник Armor
R - класс наследник Race
