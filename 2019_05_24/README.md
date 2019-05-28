# Lenguaje C - 101

En esta clase se hizo una revisión muy rápida de un programa sencillo en C que imprime el mensaje ```hola mundo```.
Después se mostró la forma como se genera una librería de enlace estático y como funcionalidad implementada en esta es invocada desde un programa en C.

Se desarrollaron tres programas:

-[basico.c](basico.c)
-[libfun.c](libfun.c)
-[libfun.h](libfun.h)

Para compilar el programa se llevan a cabo los siguientes pasos:

-Generar la librería estatica

```
gcc -c libfun.c -o libfun.o
ar rcs libfun.a libfun.o
```

-Compilar el programa basico.c

```
gcc -c basico.c -o basico.o
```

-En un paso anterior se generó el archivo ```libfun.a``` . Ahora el codigo objeto ```basico.o``` con la librería ```libfun.a``` .

```
gcc -o basico basico.o -L. -libfun.a
```

-Finalmente, el programa se ejecuta:

```
./basico
```





