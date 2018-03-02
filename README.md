# Parsec Benchmark

<http://parsec.cs.princeton.edu/> 3.0-beta-20150206 ported to Ubuntu 16.04 and with proper version control.

## Getting started

    ./configure

Build all:

    . env.sh
    parsecmgmt -a build -p all

Build just one to save time:

    parsecmgmt -a build -p splash2

Run all:

    parsecmgmt -a run -p all

TODO some tests are broken. We will maintain a list.

Run one benchmark with one input size, listed in by increasing size:

    parsecmgmt -a run -p splash2 -i simsmall
    parsecmgmt -a run -p splash2 -i simmedium
    parsecmgmt -a run -p splash2 -i simlarge
    parsecmgmt -a run -p splash2 -i native

`sim*` tests require `parsec-3.0-input-sim.tar.gz` which we install by default, and `native` requires `parsec-3.0-input-native.tar.gz`, which we don't install by default.

TODO runs all sizes, or just one default size:

    parsecmgmt -a run -p splash2

TODO how to read run output?

Run logs are stored under:

    ls logs/

## Ubuntu 17.10

gcc 7, x264 build fails with:

    /usr/bin/gcc -o x264 x264.o matroska.o muxers.o libx264.a -L/usr/lib64 -L/usr/lib -L/usr/lib64 -L/usr/lib  -lm -lpthread -s
    /usr/bin/ld: libx264.a(cabac-a.o): relocation R_X86_64_32 against symbol `x264_cabac_range_lps' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(dct-a.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(deblock-a.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(mc-a.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(mc-a2.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(pixel-a.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(predict-a.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(quant-a.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(sad-a.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: libx264.a(dct-64.o): relocation R_X86_64_32 against `.rodata' can not be used when making a shared object; recompile with -fPIC
    /usr/bin/ld: final link failed: Nonrepresentable section on output

## About

This repo was started from version 3.0-beta-20150206:

    $ md5sum parsec-3.0.tar.gz
    328a6b83dacd29f61be2f25dc0b5a053  parsec-3.0.tar.gz

We later learnt about `parsec-3.0-core.tar.gz`, which is in theory cleaner than the full tar, but even that still contains some tars, so it won't make much of a difference.

Why this fork: how can a project exist without Git those days? I need a way to track my patches sanely. And the thing didn't build on latest Ubuntu of course :-)

We can't track all the huge input blobs on GitHub or it will blow up the 1Gb max size, so let's try to track everything that is not humongous, and then let users download the missing blobs from Princeton directly.

Let's also remove the random output files that the researches forgot inside the messy tarball as we find them.

All that matters is that this should compile fine: runtime will then fail due to missing input data.

I feel like libs contains ancient versions of a bunch of well known third party libraries, so we are just re-porting them to newest Ubuntu, which has already been done upstream... and many of the problems are documentation generation related... at some point I want to just use Debian packages or git submodules or Buildroot packages.

Related:

- https://github.com/bamos/parsec-benchmark I would gladly merge with that repo, let's see if the owner is responsive: https://github.com/bamos/parsec-benchmark/issues/3
- https://yulistic.gitlab.io/2016/05/parsec-3.0-installation-issues/ documents some of the issues that needed to be solved, but I had many many more

TODO: after build some `./configure` and `config.h.in` files are modified. But removing them makes build fail. E.g.:

- `pkgs/apps/bodytrack/src/config.h.in`
- `pkgs/apps/bodytrack/src/configure`
