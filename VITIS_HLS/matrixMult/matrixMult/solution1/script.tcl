############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
############################################################
open_project matrixMult
set_top matrixMul
add_files maxMul.cpp
open_solution "solution1" -flow_target vitis
set_part {xczu9eg-ffvb1156-2-e}
create_clock -period 10 -name default
#source "./matrixMult/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -format ip_catalog
