#!/bin/bash

cd data/D=4/Bo=3.5/viscos_rat=1

export INPUT=${HOME}/sinking_bim/trunk/data/D=4/Bo=3.5/viscos_rat=1/dimensionless_input.dat

export RUNDIR=${HOME}/sinking_bim/trunk/data/D=4/Bo=3.5/viscos_rat=1

qsub -V ../../../../param_sweep.sh

sleep 10

cd ../viscos_rat=10

export INPUT=${HOME}/sinking_bim/trunk/data/D=4/Bo=3.5/viscos_rat=10/dimensionless_input.dat

export RUNDIR=${HOME}/sinking_bim/trunk/data/D=4/Bo=3.5/viscos_rat=10

qsub -V ../../../../param_sweep.sh

cd ../../../..

