#!/bin/bash
#SBATCH --job-name=trapezAreaSimple
#SBATCH -n 4
#SBATCH --output=output_trapezAreaSimple.txt
hostname
gcc -fopenmp omp_trapezAreaSimple.C -o omp_trapecio
./omp_trapecio