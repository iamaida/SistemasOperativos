# Tarea 1: Sistemas Operativos

La tarea tiene como propósito poner en prática diversas habilidades que deben desarrollarse a partir de lo visto en clase, por medio de la modificación y creación de programas en el C.

## Desarrollo de actividades


* [mem.c](mem.c)

La actividad permitio evidenciar el proceso de virtualización de memoria, por medio de la ejecución de dos procesos concurrentes que, aparentemente, modifican de manera independiente, el valor una variable que se encuentra en la misma dirección de memoria. Lo anterior pone de manifiesto que cada proceso cuenta con su propio espacio privado de memoria virtual asignado por el Sistema Operativo.  

### Procedimiento

* Compilación y ejecución del programa [mem.c](mem.c).
```
gcc mem.c -o mem && ./mem “ ”
```
* Ejecución de dos programas [mem.c](mem.c) de manera concurrente.
```
./mem “ ”& ./mem “”&
```

Durante la ejecución del comando anterior a cada proceso se le asigna una dirección de memoria diferente. Para conseguir que los procesos apunten a la misma dirección de memoria se debe deshabilitar la asignación dinamica de direcciones de memoria.

* Desactivación asignación dinamica de direcciones de memoria [[link fuente]](https://superuser.com/questions/127238/how-to-turn-off-aslr-in-ubuntu-9-10/127240)

```
sudo sh -c "echo 0> /proc/sys/kernel/randomize_va_space"
```

* Ejecución de dos programas mem.c de manera concurrente (apuntan a la misma dirección de memoria)
```
./mem “ ”& ./mem “”&

```
### Programas auxiliares: 
El programa [mem.c](mem.c) hace uso de la libreria [common.h](common.h).
