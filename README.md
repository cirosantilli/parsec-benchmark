# PARSEC Benchmark

PARSEC <http://parsec.cs.princeton.edu/> 3.0-beta-20150206 ported to Ubuntu 16.04 and SPLASH2 ported to Buildroot 2017.08 cross compilation (ARM, MIPS, etc.).

## Getting started Buildroot cross compilation

See the instructions at: <https://github.com/cirosantilli/linux-kernel-module-cheat#parsec-benchmark> The Buildroot package is in that repo at: <https://github.com/cirosantilli/linux-kernel-module-cheat/tree/2c12b21b304178a81c9912817b782ead0286d282/parsec-benchmark>

Only SPLASH2 was ported currently, not the other benchmarks.

PARSEC's build was designed for multiple archs, this can be seen at [bin/parsecmgmt](bin/parsecmgmt), but not for cross compilation. Some of the changes we've had to make:

- use `CC` everywhere instead of hardcoded `gcc`
- use `HOST_CC` for `.c` utilities used during compilation
- remove absolute paths, e.g. `-I /usr/include`

## Getting started Ubuntu 16.04

    ./configure

Before doing anything else, you must get the `parecmgmt` command with:

    . env.sh

Build all:

    parsecmgmt -a build -p all

Build all SPLASH2 benchmarks:

    parsecmgmt -a build -p splash2x

Build just one SPLASH2 benchmark:

    parsecmgmt -a build -p splash2x.barnes

Run one benchmark with one input size, listed in by increasing size:

    parsecmgmt -a run -p splash2x.barnes -i test
    parsecmgmt -a run -p splash2x.barnes -i simdev
    parsecmgmt -a run -p splash2x.barnes -i simsmall
    parsecmgmt -a run -p splash2x.barnes -i simmedium
    parsecmgmt -a run -p splash2x.barnes -i simlarge
    parsecmgmt -a run -p splash2x.barnes -i native

For some reason, the `splash2` version (without the X) does not have any test data besides `-i test`, making it basically useless. So just use the X version instead. TODO why? Can we just remove it then? When running `splash2`, it says:

    NOTE: SPLASH-2 only supports "test" input sets.

so likely not a bug.

The tests are distributed separately as:

* `test` tests come with the smallest possible distribution `core`, and are tiny sanity checks as the name suggests. We have however removed them from this repo, since they are still blobs, and blobs are evil.
* `sim*` tests require `parsec-3.0-input-sim.tar.gz` which we install by default
* `native` requires `parsec-3.0-input-native.tar.gz`, which we don't install by default because it is huge. These huge instances are intended for real silicon.

Run all packages with the default `test` input size:

    parsecmgmt -a run -p all

TODO some tests are broken. We will maintain a list.

Not every benchmark has every input size, e.g. `splash2.barnes` only has `test` input inside of `core` and `input-sim`

TODO runs all sizes, or just one default size:

    parsecmgmt -a run -p splash2x

TODO how to read run output?

Run logs are stored under:

    ls logs/

One of the most valuable things parsec adds is that it instruments the region of interest of all benchmarks with:

    __parsec_roi_begin

so you will likely want to override that to some simulator magic instruction. TODO link to the GEM5 one.

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

We try to keep this as close to mainline functionality as possible to be able to compare results, except that it should build and run.

We can't track all the huge input blobs on GitHub or it will blow up the 1Gb max size, so let's try to track everything that is not humongous, and then let users download the missing blobs from Princeton directly.

Let's also remove the random output files that the researches forgot inside the messy tarball as we find them.

All that matters is that this should compile fine: runtime will then fail due to missing input data.

I feel like libs contains ancient versions of a bunch of well known third party libraries, so we are just re-porting them to newest Ubuntu, which has already been done upstream... and many of the problems are documentation generation related... at some point I want to just use Debian packages or git submodules or Buildroot packages.

Related:

- https://github.com/bamos/parsec-benchmark I would gladly merge with that repo, let's see if the owner is responsive: https://github.com/bamos/parsec-benchmark/issues/3
- https://yulistic.gitlab.io/2016/05/parsec-3.0-installation-issues/ documents some of the issues that needed to be solved, but I had many many more
- https://github.com/anthonygego/gem5-parsec3 Apparently focuses on image generation via QEMU native compilation.

TODO: after build some `./configure` and `config.h.in` files are modified. But removing them makes build fail. E.g.:

- `pkgs/apps/bodytrack/src/config.h.in`
- `pkgs/apps/bodytrack/src/configure`
