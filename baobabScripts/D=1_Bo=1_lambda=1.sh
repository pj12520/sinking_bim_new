#!/bin/bash

# Set current directory
export CURR_DIR="${HOME}/sinking_bim_new/baobabScripts"

# Set working directory
export RUNDIR="${HOME}/scratch/impactResults/D=1_Bo=1_Lambda=1"

# set input file
export INPUT="${HOME}/scratch/impactResults/D=1_Bo=1_Lambda=1/dimensionless_input.dat"

sbatch oneJob.sh
