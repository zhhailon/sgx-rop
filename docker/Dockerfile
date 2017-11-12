FROM ubuntu:12.04

RUN apt-get update \
 && apt-get install -y python-software-properties automake \
 && add-apt-repository ppa:avsm/ppa \
 && apt-get update \
 && apt-get install -y git-core ocaml ocaml-native-compilers camlp4-extra opam

RUN useradd -s /bin/bash -m sgxrop
RUN su - sgxrop -c "opam init -y && eval `opam config env` && opam install deriving.0.7 ocamlfind.1.5.5 parmap.1.0-rc6 batteries.2.3.1"
RUN su - sgxrop -c "git clone https://github.com/s3team/uroboros.git && cd uroboros/src && ./build"
CMD su - sgxrop
