# Development

## Preconditions
Several submodules are need to build this project. There are two ways to checkout submodules:
> Make ensure that all the submodules files have been synchronized locally
1.  Clone with option `--recursive`
    ```
    git clone git@github.com:stafiprotocol/ledger-stafi.git --recursive
    ```

2. checkout submodules after cloning the project:
    ```
    git clone git@github.com:stafiprotocol/ledger-stafi.git
    git submodule update --init --recursive
    ```

- Install Docker CE
    - Instructions can be found here: https://docs.docker.com/install/

- We only officially support Ubuntu. Install the following packages:
   ```
   sudo apt update && apt-get -y install build-essential git wget cmake \
  libssl-dev libgmp-dev autoconf libtool
   ```
   > For Mac Os, `brew` is useful.

- Install `node > v14.0`. We typically recommend using `n`.
> Version 16.0.0 is Ok.

- You will need python 3 and then run
    - `make deps`

    - The current repository keeps track of Ledger's SDK but it is possible to override it by changing the git submodule.

*Warning*: 
1. `python` may be python2, but python3 is needed. Find python3 and set `python` as python3 like this in the bash file:
```bash
alias python="/usr/local/bin/python3.9"
alias pip="/usr/local/bin/pip3"
```
2. If you see conan is not found, check that you installed the package in the same interpreter as the one that launches `cmake`.

## How to build ?

> We like clion or vscode but let's have some reproducible command line steps
>

- Building the app itself

  If you installed what is described above, just run:
    ```bash
    make
    ```

## Running tests

- Running rust tests (x64)

  If you installed what is described above, just run:
    ```bash
    make rust_test
    ```

- Running C/C++ tests (x64)

  If you installed what is described above, just run:
    ```bash
    make cpp_test
    ```

## How to test with Zemu?
```bash
make zemu_install
```

**The lib `neon` is usually built with NODE_MODULE_VERSION 72, if your node version is 16.0.0, the NODE_MODULE_VERSION will be 93**
```
export NEON_NODE_ABI=93 // Optional. This may help solving the issue that NODE_MODULE_VERSION do not match.
```


Then you can run JS tests:
> It's better to pull the docker image first.
```
docker pull zondax/builder-zemu
```

```bash
make zemu_test
```
