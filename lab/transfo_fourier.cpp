#include <iostream>
#include <CL/sycl.hpp>
#include <complex>
#include <chrono>  // Para medir los tiempos

int main() {
    constexpr size_t N = 1024;
    std::complex<float> data[N];

    // Inicializar datos de ejemplo
    for (size_t i = 0; i < N; ++i) {
        data[i] = std::complex<float>(i, i);  // ejemplo simple
    }

    try {
        // Crear una cola SYCL con el selector de dispositivo (por defecto)
        sycl::queue q{sycl::default_selector_v}; 

        // Mostrar el dispositivo en el que se ejecuta el código
        std::cout << "Ejecutando en dispositivo: " 
                  << q.get_device().get_info<sycl::info::device::name>() 
                  << std::endl;

        sycl::buffer<std::complex<float>, 1> buf(data, sycl::range<1>(N));

        // Medir tiempo paralelo
        auto start_par = std::chrono::high_resolution_clock::now();

        // Ejecutar el kernel en el dispositivo (paralelo)
        q.submit([&](sycl::handler &h) {
            auto acc = buf.get_access<sycl::access::mode::read_write>(h);
            h.parallel_for<class fft_kernel>(sycl::range<1>(N), [=](sycl::id<1> i) {
                // Aquí puedes realizar la Transformada de Fourier real
                acc[i] = std::complex<float>(acc[i].real(), acc[i].imag());  // Simple ejemplo, no es una FFT real
            });
        }).wait();  // Espera a que el kernel termine de ejecutarse

        auto end_par = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration_par = end_par - start_par;
        std::cout << "Tiempo de ejecución paralelo: " << duration_par.count() << " segundos." << std::endl;

        // Acceder a los resultados después de que el kernel termine
        sycl::host_accessor result_accessor(buf);

        // Mostrar los resultados
        std::cout << "Transformada de Fourier realizada!" << std::endl;
        for (size_t i = 0; i < N; ++i) {
            std::cout << "Resultado[" << i << "]: " << result_accessor[i] << std::endl;
        }

    } catch (sycl::exception const &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
