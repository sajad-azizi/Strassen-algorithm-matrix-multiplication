#!/bin/bash -l

#############################
# OpenMP job #
# Sajjad Azizi #
#############################

#SBATCH --job-name="wavpakt_anish_T5"

# we ask for 1 task with 72 cores
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1

#              d-hh:mm:ss
#SBATCH --time=02-00:00:00

# 500MB memory per core
# this is a hard limit
#SBATCH --mem-per-cpu=30000MB

#SBATCH -p medium

# we set OMP_NUM_THREADS to the number of available cores
export OMP_NUM_THREADS=${SLURM_CPUS_PER_TASK}
time ./a.out > output
