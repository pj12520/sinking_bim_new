#!/bin/bash

cd highBo_term_data

for i in $(ls -d */); do

    cd ${i}

    for j in $(ls -d */); do

	cd ${j}

	for k in $(ls -d */); do

	    cd ${k}

	    export INPUT=${HOME}/sinking_bim/trunk/highBo_term_data/${i}/${j}/${k}/dimensionless_input.dat

	    export RUNDIR=${HOME}/sinking_bim/trunk/highBo_term_data/${i}/${j}/${k}

	    qsub -V ../../../../param_sweep.sh

	    sleep 10

	    cd ..

	done

	cd ..

    done

    cd ..

done

cd ..
