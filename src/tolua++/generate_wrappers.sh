#!/usr/bin/env bash

ROOT=$1
# PACKAGES=("Hax" "Ogre" "CEGUI" "OIS")
PACKAGES=("Hax" "Ogre" "OIS")

cd $ROOT/packages

for pkg in "${PACKAGES[@]}"; do
  echo "Exporting packages/${pkg}.pkg to ${ROOT}/wrappers/${pkg}_wrap.cxx"
  tolua++ -n ${pkg} -o ${ROOT}/wrappers/${pkg}_wrap.cxx ${pkg}.pkg
done

cd $ROOT