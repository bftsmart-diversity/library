#!/bin/bash

[ $# -eq 0 ] && { echo "Usage: $0 config_folder id_replica"; exit 1; }


#sair imediatamente em caso de erro
set -e

BASEFOLDER=`pwd`/`dirname $0`

#caminhos relativos a seguir sempre em relacao a basefolder

# bibliotecas (bft smart, netty etc)
LIBCLSPTH=../../../lib
# intermediarios python
FACDCLSPTH=../../../diversity/python
# dll libbftsmr.so
DLLCLSPTH=../../../diversity/c/build
# mensagens compiladas
PROTOCLSPTH=../protobuf/build

#pasta onde o java esta instalado no sistema.
PASTAJAVA=$(../../../scripts/findjava.sh)

export LD_LIBRARY_PATH=$PASTAJAVA/jre/lib/amd64/server
export PYTHONPATH=$BASEFOLDER/$FACDCLSPTH:$BASEFOLDER:$BASEFOLDER/$PROTOCLSPTH:$BASEFOLDER/../../../protobuf/build/lib/python2.7/site-packages

echo 'Library path' $LD_LIBRARY_PATH
echo 'python path' $PYTHONPATH

cd $1

echo
echo java -cp "$BASEFOLDER/$LIBCLSPTH/*:"\
"$BASEFOLDER/../../../protobuf/build/protobuf-runtime.jar:"\
"$BASEFOLDER/../protobuf/build/lista-proto.jar:"\
"$BASEFOLDER/../../../diversity/java/build/bftsmart-diversity.jar:"\
"$BASEFOLDER/build/bench_server.jar" bftsmart.diversity.demos.list.ServerLaunch $2 10000



java -cp "$BASEFOLDER/$LIBCLSPTH/*:"\
"$BASEFOLDER/../../../protobuf/build/protobuf-runtime.jar:"\
"$BASEFOLDER/../protobuf/build/lista-proto.jar:"\
"$BASEFOLDER/../../../diversity/java/build/bftsmart-diversity.jar:"\
"$BASEFOLDER/build/bench_server.jar" bftsmart.diversity.demos.list.ServerLaunch $2 10000



