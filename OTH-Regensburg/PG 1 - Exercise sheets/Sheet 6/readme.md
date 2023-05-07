# Tests und Fehler

> see: 'task_1.c'

- Ohne Überprüfung würde ein Fehler ausgeworfen werden, wenn für die Variable *Münzen* (bzw. *coins*) eine **0** eingesetzt werden würde. Die dazugehörige Fehlermeldung würde dementsprechend ausgeworfen werden: "Floating point exception (core dumped)". Diese Fehlermeldung wird in der Regel ausgeworfen, wenn durch Null geteilt wird, der Logarithmus von Null ausgerechnet werden soll oder die Quadratwurzel einer negativen Zahl gezogen werden soll.

    - Eine relativ einfache Lösung wäre das vorherige Überprüfen der Variablen *coins*: `if (coins != 0)`

- Da mit **int** gearbeitet wird, sind Zahlen mit sehr großen Beträgen nicht möglich verrechnet zu werden. 

- Außerdem waren in der **Übung 3 - Aufgabe 1** nur bestimmte Münzen erlaubt. Demnach sollte hierfür ebenfalls eine Überprüfung durchgeführt werden, ob die angegebene Münze auch im Array ist: `int valid_coins[] = {5,10,20,50};`

# Kniffel für Arme

> see: 'task_2.c'