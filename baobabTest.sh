#!/bin/bash
#SBATCH --job-name=impact
#SBATCH --ntasks=1
#SBATCH --time=00:01:00
#SBATCH --partition=debug-cpu

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/ebsofts/GSL/2.6-GCC-9.3.0/lib/
export LD_LIBRARY_PATH

module load GCC/9.3.0
module load GSL/2.6

srun impact dimensionless_input.dat
