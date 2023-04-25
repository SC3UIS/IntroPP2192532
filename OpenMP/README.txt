Este código en C implementa el Método del Trapecio para aproximar la integral definida de una función en un intervalo dado.
El programa pide al usuario el número de subintervalos en los que se dividirá el intervalo de integración y los límites inferior y superior del intervalo. Luego, el programa calcula la anchura de cada subintervalo y los distribuye entre los hilos disponibles usando una directiva OpenMP.
Cada hilo realiza la suma de la función evaluada en los subintervalos asignados y los resultados parciales se combinan mediante una reducción. Finalmente, el programa utiliza la fórmula del método del trapecio para aproximar la integral y muestra el resultado al usuario.
La directiva #pragma omp parallel for se utiliza para ejecutar el bucle for en paralelo en varios hilos. La cláusula private(x) asegura que cada hilo tenga su propia copia de la variable x y la cláusula reduction(+:sum) indica que el resultado parcial de la suma de las evaluaciones de la función en cada subintervalo se suma al resultado final.

COMPLIACIÓN PARA LOS ARCHIVOS en guane

Para ingresar a la carpeta OpenMP antes creada en Guane utilizamos el siguiente código:
cd "/home/class/2023_1/jdaclarog/OpenMP/"

Una vez dentro de esa carpeta ejecutamos el siguiente código:
gcc -fopenmp trapezAreaSimple.C -o trapecio -lm

Esta línea de comando compila el código fuente trapezAreaSimple.C con soporte para OpenMP, enlaza la biblioteca matemática estándar y genera un archivo ejecutable llamado trapecio que puede ser ejecutado para aproximar la integral de una función utilizando el método del trapecio con paralelismo mediante OpenMP.

Después de compilar el código fuente trapezAreaSimple.C con soporte para OpenMP y enlazar la biblioteca matemática estándar,
 se genera un archivo ejecutable llamado "trapecio". Este archivo ejecutable puede ser utilizado para aproximar la integral 
 de una función utilizando el método del trapecio con paralelismo mediante OpenMP.

Para ejecutar el archivo "trapecio" y obtener la aproximación de la integral, se utiliza el siguiente comando:
./trapecio



