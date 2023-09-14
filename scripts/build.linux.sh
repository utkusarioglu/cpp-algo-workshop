#!/bin/bash

source .repo.config
source scripts/utils.sh

# clean 'linux' $@
# install 'linux' $@
build 'linux' $@
run_test 'linux' $@
