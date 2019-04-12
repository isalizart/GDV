Coding-Style
------------------------------------------------------------------------------

* Klassen groß, z.B. Matrix oder Quaternion
* Funktionen und Methoden _klein_, z.B. Quaternion.toAxisAngle()
* Bei Benennungen möglichst CamelCase
* Einrücken mit 4 Spaces (keine Tabs)
* Pro Zeile möglichst weniger als 80 Zeichen


Hinweis für Mac-User
------------------------------------------------------------------------------

* qmake auf Pro-File ausführen (falls nicht im Pfad, z.B. wie folgt, falls Qt
  direkt in Home installiert wurde - sicherheitshalber erst Pfad überprüfen):
  ~/Qt5.8.0/5.8/clang_64/bin/qmake -spec macx-xcode Sinus.pro
* Alternativ in ~/.bash_profile z.B. folgendes angeben, um qmake direkt von
  Kommandozeile aufrufen zu können (dazu vorher wieder Qt-Pfad überprüfen):
  export QTDIR=~/Qt5.8.0/5.8/clang_64/
  export PATH=$PATH:$QTDIR/bin
* Liegt Qt dann im Pfad, können zugehörige Apps aufgerufen werden, Bsp.:
  open -a Designer
  

Hinweis für Windows-User
------------------------------------------------------------------------------

* Project-Files alternativ auf Kommandozeile im Ordner mit Pro-File erzeugbar:
  qmake -spec win32-msvc2015 -tp vc
