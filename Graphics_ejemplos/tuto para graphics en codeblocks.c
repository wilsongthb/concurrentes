copiar graphics.h para el directorio
C:\Program Files (x86)\CodeBlocks\MinGW\include

copiar libbgi.a para el directorio
C:\Program Files (x86)\CodeBlocks\MinGW\lib

configurar el compilador c++ en codeblocks, ir
al menu
settings -> compiler
pestaña "linker", luego en lado derecho colocar
-lbgi
-lgdi32
-lcomdlg32
-loleaut32
-lole32
-luuid

