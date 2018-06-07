#!/bin/bash

set -e

SIP_VERSION=4.15.3

apt-get install -y python-dev build-essential

TMPDIR=`mktemp -d`

function atexit_func {
    if [ "$TMPDIR" != "" ]; then
        rm -rf $TMPDIR
    fi
}

trap "atexit_func" EXIT

cd $TMPDIR
wget --no-check-certificate -O - http://sourceforge.net/projects/pyqt/files/sip/sip-$SIP_VERSION/sip-$SIP_VERSION.tar.gz | tar -xz

cd sip-$SIP_VERSION
python configure.py
make && make install
