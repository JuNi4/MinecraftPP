#!/bin/bash

g++ getAssets.cpp -lcurl -lzip -Iinclude -std=c++20 -o getAssets.out
mv getAssets.out ..