# Parsec Benchmark

http://parsec.cs.princeton.edu/

    sudo apt-get install build-essential m4 x11proto-xext-dev libglu1-mesa-dev libxi-dev libxmu-dev libtbb-dev
    . env.sh
    parsecmgmt -a build -p all

3.0-beta-20150206:

    $ md5sum parsec-3.0.tar.gz
    328a6b83dacd29f61be2f25dc0b5a053  parsec-3.0.tar.gz

Why this fork: how can a project exist without Git those days? I need a way to track my patches sanely. And the thing didn't build on latest Ubuntu of course :-)

We can't track all the huge input blobs on GitHub or it will blow up the 1Gb max size, so let's try to track everything that is not humongous, and then let users download the missing blobs from Princeton directly.

Let's also remove the random output files that the researches forgot inside the messy tarball as we find them.

All that matters is that this should compile fine: runtime will then fail due to missing input data.

I feel like libs contains ancient versions of a bunch of well known third party libraries, so we are just re-porting them to newest Ubuntu, which has already been done upstream... and many of the problems are documentation generation related... at some point I want to just use Debian packages or git submodules or Buildroot packages.

Related:

- https://github.com/bamos/parsec-benchmark I would gladly merge with that repo, let's see if the owner is responsive: https://github.com/bamos/parsec-benchmark/issues/3
- https://yulistic.gitlab.io/2016/05/parsec-3.0-installation-issues/ documents some of the issues that needed to be solved, but I had many many more
