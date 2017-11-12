FROM ubuntu:14.04

RUN apt-get update && \
    apt-get install -y python-software-properties software-properties-common \
    automake make git-core ocaml ocaml-native-compilers camlp4-extra && \
    add-apt-repository ppa:avsm/ppa && apt-get update && apt-get install -y opam

RUN useradd -s /bin/bash -m sgxrop
RUN su - sgxrop -c "opam init -y"
RUN su - sgxrop -c "opam install deriving.0.7 ocamlfind.1.5.5 parmap.1.0-rc6 batteries.2.3.1"
RUN su - sgxrop -c "echo '. /home/sgxrop/.opam/opam-init/init.sh > /dev/null 2> /dev/null || true' >> .profile"
RUN su - sgxrop -c "echo 'let () = try Topdirs.dir_directory (Sys.getenv \"OCAML_TOPLEVEL_PATH\") with Not_found -> () ;;' >> .ocamlinit"
RUN su - sgxrop -c "git clone https://github.com/s3team/uroboros.git && cd uroboros/src && ./build"
CMD su - sgxrop

