#!/bin/bash

# Set current directory
export CURR_DIR="${HOME}/sinking_bim_new/baobabScripts"
# Set working directory
export RUNDIR="${HOME}/impactTest/run1"

sbatch baobabTest.sh

# Set working directory
export RUNDIR="${HOME}/impactTest/run2"

sbatch baobabTest.sh
