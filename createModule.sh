#!/bin/bash

############################################################################################################
## Constant Block

############################################################################################################
## Description Function Block
function usage() {
    cat <<EOF

Usage: $0 <arguments>

Arguments:
    -h | --help         : print the help description

    -b | --build        : build the python package
            parameter: module name

EOF
}

function createModuleDirectory() {
    moduleName=$1

    if [ ! -d $moduleName ]; then
        echo "Directory $moduleName DOES NOT exists."
        mkdir $moduleName
    else
        echo "Directory $moduleName exists."
    fi
}

function createModuleHeaderFile() {
    moduleName=$1
    cat >${moduleName}/${moduleName}.hpp <<EOF
/*
 * ${moduleName}.hpp
 *
 *  Created on: ${date}
 *      Author: roder
 */
#ifndef ${moduleName^^}_HPP
#define ${moduleName^^}_HPP

#include <set>
#include <string>

#include "../Utils/Logging/Logger.hpp"

using namespace std;

class ${moduleName} {
  private:
    const string logtag = "${moduleName}";

  public:
    ${moduleName}();
    ~${moduleName}();
};

#endif /* ${moduleName^^}_HPP */
EOF
}

function createModuleSourceFile() {
    moduleName=$1
    cat >${moduleName}/${moduleName}.cpp <<EOF

#include "${moduleName}.hpp"

${moduleName}::${moduleName}() {
}

${moduleName}::~${moduleName}() {
}
EOF
}

############################################################################################################
## Start Function Block
function build() {
    moduleName=$1

    createModuleDirectory $moduleName
    createModuleHeaderFile $moduleName
    createModuleSourceFile $moduleName
}

############################################################################################################
## Start Main Block
case "$1" in
-b | --build)
    echo "build the python package"
    build ${@:2}
    exit $?
    ;;

-h | --help)
    echo "Help Page for : $IMAGE_NAME"
    usage
    exit $?
    ;;

*)
    usage
    exit $?
    ;;
esac
## End Main Block
############################################################################################################
