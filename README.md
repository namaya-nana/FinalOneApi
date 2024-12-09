Proyecto OneAPI: Implementación de la Transformada de Fourier Rápida (FFT) en DPC++

Este proyecto demuestra cómo implementar la Transformada Rápida de Fourier (FFT) utilizando DPC++ (Data Parallel C++), 
un modelo de programación paralela de OneAPI que permite ejecutar cálculos de alto rendimiento en dispositivos como CPU, 
GPU y FPGA. Incluye también scripts para facilitar la ejecución del código en Intel DevCloud, un entorno de cómputo optimizado 
para experimentar con OneAPI.

Contenido del Proyecto
transfo_fourier.cpp: Este archivo implementa una versión simplificada de la Transformada de Fourier Rápida en paralelo. En el código se destacan los siguientes puntos clave:
  Generación de datos: Se crea una señal de ejemplo (un arreglo de números complejos) que será transformada.
  Paralelización: Utiliza SYCL para distribuir el trabajo de cálculo de la FFT en paralelo a través de una función parallel_for.
  Dispositivos de cómputo: Se utiliza una cola SYCL (queue q) que selecciona automáticamente el dispositivo más adecuado (CPU o GPU).
  Optimización: Aprovecha las capacidades de paralelización intrínsecas de OneAPI para mejorar el tiempo de ejecución.

run_gpu.sh: Un script de Bash que compila y ejecuta el código en un entorno Intel DevCloud, donde se ejecuta el código aprovechando la infraestructura de cómputo de alto rendimiento disponible.

q: Un script de Bash que envía el trabajo a la cola de trabajos de Intel DevCloud y realiza un seguimiento del progreso del trabajo, esperando la generación del archivo de salida con los resultados.

README.md: Un archivo que proporciona información detallada sobre el proyecto.
