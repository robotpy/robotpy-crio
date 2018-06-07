#!/bin/bash

set -e

echo "deb http://debian.repo.frc.s3.amazonaws.com jessie main" > /etc/apt/sources.list.d/frc.list

wget -O - http://debian.repo.frc.s3.amazonaws.com/rbmj.gpg.key | apt-key add -

apt-get update
apt-get install -y gcc-powerpc-wrs-vxworks frc-buildscripts wpilib
