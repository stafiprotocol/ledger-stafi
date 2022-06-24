#### 1. Is there another way to checkout submodules?
    git clone git@github.com:stafiprotocol/ledger-stafi.git --recursive


#### 2. What are submodules useful for？
To set up the [BOLOS](https://developers.ledger.com/docs/nano-app/introduction/) development environment.
The environment is all set in a Docker image, that's why Docker CE needs to be installed.

#### 3. Is it able to build the app on MAC?
Yes, make sure cmake is installed.

#### 4. How to fix the issue `Python 3 is not installed` after installing python3? 
The default python may be python2, you may add this to your bash file:
 ```bash
 alias python="/usr/local/bin/python3.9"
 alias pip="/usr/local/bin/pip3"
 ```
 
#### 5. The lib `neon` is usually built with NODE_MODULE_VERSION 72, however, my node version is 16.0.0, and the NODE_MODULE_VERSION is 93, How to fix the 'NODE_MODULE_VERSION do not match' issue？
    export NEON_NODE_ABI=93

#### 6. All zemu_tests timeout, how to fix?
    docker pull zondax/builder-zemu
 

 
 
 
