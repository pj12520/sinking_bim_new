#!/bin/bash                                                                                                                                     
export INPUT=${HOME}/sinking_bim/trunk/dimensionless_input.dat

export RUNDIR=${HOME}/sinking_bim/trunk

		qsub -V param_sweep.sh


