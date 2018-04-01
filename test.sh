#!/bin/sh

set -ex

ncpus="${1:-1}"

## parsec

# Working. Only commented out while we wait to get all non-splash working.
#( cd pkgs/apps/blackscholes/run && ../inst/*/bin/blackscholes 1 in_4.txt prices.txt )

# TODO aarch64 segfault: unhandled level * translation fault
#( cd pkgs/apps/bodytrack/run && ../inst/*/bin/bodytrack sequenceB_1 4 1 5 1 0 1 )
#( cd pkgs/apps/facesim/run && ../inst/*/bin/facesim -h )
#( cd pkgs/apps/ferret/run && ../inst/*/bin/ferret corel lsh queries 5 5 1 output.txt )
#( cd pkgs/apps/x264/run && ../inst/*/bin/x264 --quiet --qp 20 --partitions b8x8,i4x4 --ref 5 --direct auto --b-pyramid --weightb --mixed-refs --no-fast-pskip --me umh --subme 7 --analyse b8x8,i4x4 --threads 1 -o eledream.264 eledream_32x18_1.y4m )

## splash2x

### apps

# TODO arm segfault
#( cd ext/splash2x/apps/barnes/run && ../inst/*/bin/barnes 1 < input_1 )

# TODO x86_64 host segfault
#( cd ext/splash2x/apps/fmm/run && ../inst/*/bin/fmm "$ncpus" < input_1 )
( cd ext/splash2x/apps/ocean_cp/run && ../inst/*/bin/ocean_cp -n258 -p"$ncpus" -e1e-07 -r20000 -t28800 )

# TODO arm segfault
# cd /parsec/ext/splash2x/apps/ocean_ncp/run
#../inst/*/bin/ocean_ncp -n258 -p"$ncpus" -e1e-07 -r20000 -t28800

( cd ext/splash2x/apps/radiosity/run && ../inst/*/bin/radiosity -bf 1.5e-1 -batch -room -p "$ncpus" )
( cd ext/splash2x/apps/raytrace/run && ../inst/*/bin/raytrace -s -p"$ncpus" -a4 teapot.env )
( cd ext/splash2x/apps/volrend/run && ../inst/*/bin/volrend "$ncpus" head-scaleddown4 4 )
( cd ext/splash2x/apps/water_nsquared/run && ../inst/*/bin/water_nsquared "$ncpus" < input_1 )
( cd ext/splash2x/apps/water_spatial/run && ../inst/*/bin/water_spatial "$ncpus" < input_1 )

### kernels

( cd ext/splash2x/kernels/cholesky/run && ../inst/*/bin/cholesky -p"$ncpus" < tk14.O )
( cd ext/splash2x/kernels/cholesky/run && ../inst/*/bin/cholesky "$ncpus" test )
( cd ext/splash2x/kernels/fft/run && ../inst/*/bin/fft -m18 -p"$ncpus" )
( cd ext/splash2x/kernels/lu_cb/run && ../inst/*/bin/lu_cb -p"$ncpus" -n512 -b16 )
( cd ext/splash2x/kernels/lu_ncb/run && ../inst/*/bin/lu_ncb -p"$ncpus" -n512 -b16 )

# TODO arm ERROR: Cannot malloc enough memory for global
#( cd ext/splash2x/kernels/radix/run &&  ../inst/*/bin/radix -p"$ncpus" -r4096 -n262144 -m524288 )
