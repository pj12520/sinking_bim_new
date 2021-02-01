#!/bin/bash
#SBATCH --job-name=impact
#SBATCH --ntasks=1
#SBATCH --time=12:00:00
#SBATCH --partition=shared-cpu

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

# Run application
srun $APPLICATION $INPUT

# Return to original directory
cd $CURR_DIR
