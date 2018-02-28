# Parsec Benchmark

http://parsec.cs.princeton.edu/

Why this fork: how can a project exist without Git those days? I need a way to track my patches sanely.

We can't track all the huge input blobs on GitHub or it will blow up the 1Gb max size, so let's try to track everything that is not humongous, and then let users download the missing blobs from Princeton directly.

Let's also remove the random output files that the researches forgot inside the messy tarball.

All that matters is that this should compile fine.

Related:

- https://yulistic.gitlab.io/2016/05/parsec-3.0-installation-issues/
