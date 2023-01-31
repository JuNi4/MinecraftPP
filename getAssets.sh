#!/bin/bash

cd assets/getAssets
bash compile.sh
cd ..
./getAssets.out
rm getAssets.out
cd ..
