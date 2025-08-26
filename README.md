# Introducción a la Programación Paralela TP1

## Introducción

En este código se puso a prueba 2 problemas clásicos de programación (Fibonnaci y el problema de las N-Reinas) y se buscó optimizarlos aplicando técnicas de programación paralela. 

Este fue el [enunciado](docs/Enunciado%20TP1.pdf).

## Instalación
Se requiere tener OpenMP instalado. Se puede instalar utilizando el siguiente comando:
```bash
sudo apt install libomp-dev
```

## Compilación y Ejecución

Se compila el código usando:
```bash
gcc -fopenmp <archivo .c deseado> -o <nombre_output>
```

Finalmente se ejecuta usando:
```bash
./<nombre_output> <args>
```

Para los códigos en la carpeta fibonacci se requiere poner el número N del N-ésimo número de la serie que se desea obtener.
Mientras que en los códigos de la carpeta queensPuzzle se requiere poner el número N de reinas que se quiere tener en el tablero NxN. Adicionalmente para el main donde se varía la cantidad de threads se requiere un segundo argumento con dicha cantidad deseada.


## Análisis

Se necesitará tener UV instalado para el entorno virtual con las dependencias, podés seguir el [tutorial oficial](https://docs.astral.sh/uv/getting-started/installation) para instalarlo en tu sistema operativo.

Luego, correr:
```bash
uv run jupyter lab analysisFibonacci.ipynb
```
Para crear el entorno virtual con las dependencias necesarias y visualizar los datos dentro del notebook.
