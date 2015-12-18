* En QT creator hay que abrir directamente el proyecto tomando
CMakeList.txt como el archivo de proyecto
Hay que indicarle el directorio donde construira todo

* Ejecutar cmake con el parámetro -DCMAKE_BUILD_TYPE=Debug para que lo configure como debug.
Eso se declara en qt en proyecto

================================================================================
* 18/DIC/2015-VICTOR
* This is a fork of the software:
http://http://moka-modeller.sourceforge.net/

* It adds an embedding to ORBIT_SELF which is a multi-vector of a Clifford Algebra G4
used to represent an oriented projective space.

* After compiling it, if it is run from a console, the outputs of the length, area and volume are shown in the console ( std output).
* In order to build the Clifford embedding, the program needs to import a geometry in OFF format.
  NOTE: If the first line from the file is OFF the importation is the original one.
  If the first line indicates OFFVIC then the new embedding is used.
  The original embedding using ORBIT_0 ( vertices ) is still there in parallel.
