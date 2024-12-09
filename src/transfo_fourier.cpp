#include <CL/sycl.hpp>
#include <iostream>

int main() {
    try {
        queue q(gpu_selector_v);
       

        std::cout << "Usando dispositivo: " 
                  << q.get_device().get_info<sycl::info::device::name>() 
                  << "\n";
        std::cout << "Memoria global: " 
                  << q.get_device().get_info<sycl::info::device::global_mem_size>() / (1024 * 1024) 
                  << " MB\n";
    } catch (sycl::exception const &e) {
        std::cerr << "SYCL error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
