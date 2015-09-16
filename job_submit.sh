#!/bin/bash

cd interv_sweep

for i in $(ls -d */); do

    cd ${i}

    for j in $(ls -d */); do

	cd ${j}

	for k in $(ls -d */); do

	    cd ${k}

	    for l in $(ls -d */); do

		cd ${l}

		export INPUT=${HOME}/sinking_bim/trunk/interv_sweep/${i}/${j}/${k}/${l}/dimensionless_input.dat

		export RUNDIR=${HOME}/sinking_bim/trunk/interv_sweep/${i}/${j}/${k}/${l}

		qsub -V ../../../../../param_sweep.sh

		sleep 10

		cd ..

	    done

	    cd ..

	done

	cd ..

    done

    cd ..
   
done