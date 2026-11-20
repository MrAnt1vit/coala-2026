# Программы к занятию XVI

Каждый файл — самостоятельная программа C++17. Из этого каталога её можно собрать, заменив имя файла в команде:

```sh
g++ -std=c++17 -O2 -Wall -Wextra -pedantic grasshopper.cpp -o grasshopper
./grasshopper
```

| Файл | Что демонстрирует |
| --- | --- |
| [grasshopper.cpp](grasshopper.cpp) | число способов и база `dp[1] = 1` |
| [staircase.cpp](staircase.cpp) | максимум суммы, включая отрицательные числа |
| [rabbit.cpp](rabbit.cpp) | недостижимые клетки и три длины прыжка |
| [calculator.cpp](calculator.cpp) | минимум операций и восстановление пути |
| [containers.cpp](containers.cpp) | подсчёт двоичных строк без соседних единиц |

[Вернуться к конспекту](../README.md).
