#!/bin/sh
#PBS -q cpa
#PBS -l nodes=1,walltime=00:10:00
#PBS -o compara.txt
#PBS -d .
OMP_NUM_THREADS=8 ./Pimagenes1i
OMP_NUM_THREADS=8 ./Pimagenes2j
OMP_NUM_THREADS=8 ./Pimagenes3k
OMP_NUM_THREADS=8 ./Pimagenes4l
