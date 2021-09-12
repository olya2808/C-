Данные: data.txt
Счета (для проверки):scores.txt
Веса (для проверки):loadings.txt
Описание и графики данных - https://rcs.chemometrics.ru/ru/books/metod-glavnykh-komponent/lyudi-i-strany/

Создать класс "PCA".
В нем, используя математическую библиотеку, разработанную в заданиях ЛР1-ЛР4, реализовать методы:
1. Предобработки данных (центрирование и шкалирование) (https://rcs.chemometrics.ru/ru/books/metod-glavnykh-komponent/metod-glavnykh-component/#103). Для шкалирования использовать формулу, где деление производится на n-1.
2. Разложения матрицы алгоритмом NIPALS разложения матрицы (https://rcs.chemometrics.ru/ru/books/metod-glavnykh-komponent/metod-glavnykh-component/#93).
Вход - матрица X, выход - матрица счетов T (scores) , матрица весов P (loadings), матрица остатков E
3. Вычисления размахов и отклонений - считаются для каждого образца (строки в матрице) (https://rcs.chemometrics.ru/ru/books/metod-glavnykh-komponent/metod-glavnykh-component/#104)
4. Вычисления полной и объясненной дисперсий остатков в обучении (https://rcs.chemometrics.ru/ru/books/metod-glavnykh-komponent/lyudi-i-strany/#112)

Проверить свои расчеты по примеру
https://rcs.chemometrics.ru/ru/books/metod-glavnykh-komponent/lyudi-i-strany/

Описание алгоритма (по шагам):
Обозначения:
X' (штрих) - транспонирование
norm(x) - норма вектора
center(X) - центрирование матрицы
scaling(X) - нормирование (шкалирование) матрицы

Пусть дана матрица X

PC - число главных компонент (>= 1, <= минимальной из размерностей матрицы Х)
eps = 1e-8 (= 0.00000001) , критерий сходимости - norm(d) <= eps

Алгоритм:

D = X
D = center(D)
D = scaling(D)

E = D;

for h = 1 to PC


t = E(:,h); // h-ый столбец E


do

p= ((t'*E)/(t'*t))';

p = p/norm(p);



t_old = t;

t = (E*p)/(p'*p);

d = t_old - t;

while norm(d) > eps

E = E - t*p';

P = [P,p];// добавить вектор-столбец p в матрицу P

T = [T,t];// добавить вектор-столбец t в матрицу T

end
