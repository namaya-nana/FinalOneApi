#!/bin/bash
source /opt/intel/oneapi/setvars.sh > /dev/null 2>&1
/bin/echo "##" $(whoami) Se está compilando Transformada de Fourier en paralelo
icpx -fsycl lab/transfo_fourier.cpp
if [ $? -eq 0 ]; then ./a.out; fi


