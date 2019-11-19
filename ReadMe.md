# Linux Daemon Template

## Description

This is a logging server for Linux.. The clients can be connected to the server about ips socket file. All log message come in the Client log file under the path : /var/log/loggingServer. This path can you change with the loggingDeamon.config file in the /etc/loggingServer

## Needed tools

-   CMake
-   Make
-   C++ compiler
-   GTest (https://github.com/google/googletest.git)

### Install GTest

-   checkout this repo "https://github.com/google/googletest.git" and install all with cmake
-   install this lib with following command "sudo apt-get install libgtest-dev"

### Install ProtocolBuffer

```bash
    # On ubuntu 18.04
    sudo apt-get install build-essential autoconf libtool pkg-config automake curl

    git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc
    cd grpc
    git submodule update --init --recursive

    # Build and install protobuf
    cd ./third_party/protobuf
    ./autogen.sh
    ./configure
     make -j6
     make check
     sudo make install
     sudo ldconfig # refresh shared library cache.
```

### Install GRPC

````bash
    git clone -b $(curl -L https://grpc.io/release) https://github.com/grpc/grpc
    cd grpc
    git submodule update --init --recursive

    # Build and install gRPC
    make -j `nproc` PROTOC=/opt/protobuf/bin/protoc
    su

## Start Development

Checkout this project

```bash
    git clone git@github.com:grobbles/linux-daemon-template.git
    cd linux-daemon-template
````

Run the main script to initialize the project

```bash
     ./rund.sh -i
```

To build the project run the scpript with following command

```bash
     ./rund.sh -b
```

To install the daemon in your system and start the daemon run the main script. This command build also the daemon.

```bash
     sudo ./rund.sh -s
```

To create a debain package run the main script with the following command

```bash
     ./rund.sh -p
```

## IDE

The daemon template project is optimized for visual studio code IDE.

## Git Workflow

-   master branch
-   feature branch
-   bugfix branch

If you want to add a new feature than create a new branch from master branch and commit your stuff to the branch. If you think you are done than create a merge request.

## Troubleshooting

### Get more log from grpc interface

```bash
     export GRPC_TRACE=all && ./build/loggingDaemon/main/loggingDaemon
     export GRPC_TRACE=all && ./build/Client/Client
```

## Software versioning

It give three segments. "Major version"."Minor version"."Patch version"

1. Major version - incremented for backwards-incompatible changes
    - Major version must be incremented manually in the 'setup.py' file.
    - It will be read only the Major version from the file. The other version numbers will be ignore and will be override from script.
2. Minor version - incremented for new, backwards-compatible functionality is introduced to the API
    - Minor version will be incremented automatically if a feature branch merged in the master branch.
3. Patch version - incremented for backwards-compatible bug fixes
    - Patch version will be incremented automatically if a bugfix branch merged in the master branch.

Example:

```python
    0.9.0 # merge a bugfix branch
    0.9.1 # merge a bugfix branch
    0.9.2 # merge a bugfix branch
    ...
    0.9.10
    0.9.11
    1.0.0 # the project is in a stable state and can be release.
    1.0.1 # merge a bugfix branch
    1.1.0 # merge a feature branch
    2.0.0 # merge a feature branch with a incompatible API change
    2.0.1 # merge a bugfix branch
```

## LICENSE

MIT License
