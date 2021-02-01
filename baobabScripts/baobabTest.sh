#!/bin/bash
#SBATCH --job-name=impact
#SBATCH --ntasks=1
#SBATCH --time=00:01:00
#SBATCH --partition=debug-cpu

# Add path to librabry functions
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/ebsofts/GSL/2.6-GCC-9.3.0/lib/
export LD_LIBRARY_PATH

#Load modules
module load GCC/9.3.0
module load GSL/2.6

# Set working directory
# export RUNDIR="${HOME}/impactTest"
cd $RUNDIR

# Name of application----------------------------
export APPLICATION="${HOME}/sinking_bim_new/impact"

# Name of input file
export INPUT="${HOME}/sinking_bim_new/dimensionless_input.dat"

srun $APPLICATION $INPUT

cd $CURR_DIR
