#!/bin/bash

for i in `seq 1076 1336`; do
    qdel '301'$i
    echo '301'$i
done