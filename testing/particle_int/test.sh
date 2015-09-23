#!/bin/bash                                                                                                                                     

for i in $(ls -d */); do

    cd ${i}

    for j in $(ls input*); do

	../../../impact ${j} 

    done

    cd ..

done