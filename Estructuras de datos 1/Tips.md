---- COMPILACIONES ----

- Compilación normal: gcc archivo1 archivo2 -o nombre_ejecutable
- Compilación con warnings: gcc -Wall -Wextra archivo

-Wall: Habilita un conjunto estándar de advertencias. Esta opción activa varias advertencias que son útiles para detectar posibles errores o prácticas no recomendadas en el código fuente. Sin embargo, no activa todas las advertencias disponibles.

-Wextra: Habilita un conjunto adicional de advertencias. Esta opción activa un conjunto más amplio de advertencias en comparación con -Wall. Incluye advertencias adicionales que no están activadas por -Wall pero que también pueden ser útiles para mejorar la calidad y la seguridad del código. 


---- VALGRIND (MANEJO DE MEMORIA) ----

- Compilar con flag -g
- valgrind ./nombre_ejecutable

--leak-check=<yes|no|summary|full>: Controla la detección de fugas de memoria. Por ejemplo, --leak-check=full proporcionará detalles sobre las fugas de memoria detectadas.

--show-leak-kinds=<all|definite|indirect|possible|reachable>: Controla qué tipos de fugas de memoria mostrar. Por ejemplo, --show-leak-kinds=all mostrará todos los tipos.
