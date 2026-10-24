# Примеры решений тестирования 3

Каждый файл — самостоятельная программа на C++17, читающая данные из стандартного ввода и печатающая ответ в формате соответствующей задачи [контеста 726770](https://codeforces.com/group/ByhdE7NWBK/contest/726770). Из каталога `12-testing-3` компиляция и запуск в PowerShell выглядят так:

```powershell
g++ -std=c++17 -O2 examples/a_protect_sheep.cpp -o solution.exe
Get-Content input.txt | .\solution.exe
```

Замените имя исходного файла для другой задачи. `input.txt` должен содержать входные данные из условия. На Linux или macOS можно использовать `./solution < input.txt`.

| Задача | Файл | Вывод |
| --- | --- | --- |
| A. Защитить овец | [`a_protect_sheep.cpp`](a_protect_sheep.cpp) | `No` или `Yes` и итоговое поле. |
| B. Метро | [`b_metro.cpp`](b_metro.cpp) | `YES` или `NO`. |
| C. Свяжите графа | [`c_connect_graph.cpp`](c_connect_graph.cpp) | Число и список новых рёбер. |
| D. Катание на коньках | [`d_ice_skating.cpp`](d_ice_skating.cpp) | Минимальное число новых сугробов. |
| E. Озёра | [`e_lakes.cpp`](e_lakes.cpp) | Максимальный объём для каждого набора данных. |
| F. Кратчайший путь | [`f_shortest_path.cpp`](f_shortest_path.cpp) | `-1` либо длина и вершины пути. |
| ZA. Венеция | [`za_venice.cpp`](za_venice.cpp) | Год потери связности. |
| ZA. Венеция, вариант из прошлогоднего разбора | [`za_venice_binary_search.cpp`](za_venice_binary_search.cpp) | Тот же ответ через бинарный поиск и BFS. |
| ZB. Рождественские деревья | [`zb_christmas_trees.cpp`](zb_christmas_trees.cpp) | Сумма расстояний и позиции людей. |
| ZC. Система навигации | [`zc_navigation.cpp`](zc_navigation.cpp) | Минимум и максимум перестроений. |
