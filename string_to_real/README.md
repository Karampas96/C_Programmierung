# String to Real

## 1 Einleitung

Sicher haben Sie auch schon festgestellt, dass ein Programm abstürzt, wenn anstatt einer Zahl ein Buchstabe eingegeben wird. In dieser Aufgabe wollen wir nun ein Programm entwickeln, dass einen String einliest und dann in eine Fliesskommazahl umwandelt. Auf diese Weise kann ein Programm nicht mehr "abstürzen", da jetzt immer Zeichen eingelesen werden.

## 2 Aufgabenstellung

Entwickeln Sie eine Funktion, mit dem ein String mit den Zeichenmöglichkeiten: `0` ... `9`, `.`, `,`, `E`, `+`, `-` und Leerzeichen, in eine Realzahl umgewandelt werden kann. Als Parameter wird der String (call by value) und die zu berechnende Fliesskommazahl (call by reference) übergeben. Über `return()` wird dem Benutzer mitgeteilt, ob die Zahl gewandelt werden konnte oder nicht. Dabei bedeutet:

`0`: kein Fehler aufgetreten und
`-1`: Fehler bei der Umwandlung.

So soll die Zeichenfolge: `369.45 E2` der Zahl `36945` entsprechen. Gehen Sie bei der Problemlösung davon aus, dass die Zahl über die Tastatur als String eingelesen werden muss und dann erst zur Funktion weitergeleitet wird.

Diese Funktion ersetzt mehr oder weniger den Befehl `atof` von C und darf deswegen auch nicht verwendet werden!

## 3 Schwerpunktgebiete dieser Aufgabe

* Stringauswertung
* Verwendung formatierter Ausgaben

## 4 Geforderte Lösungsbereiche

* Struktogramm des Programms
* Programmcode
* Bemerkungen zu eigenen Programm
