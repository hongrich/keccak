#!/usr/bin/env bash
set -x

IMPL=reference
FILES=(
	"align.h"
	"brg_endian.h"
	"KangarooTwelve.c"
	"KangarooTwelve.h"
	"KeccakCodePackage.h"
	"KeccakDuplex.c"
	"KeccakDuplex.h"
	"KeccakDuplex.inc"
	"KeccakHash.c"
	"KeccakHash.h"
	"KeccakP-1600-reference.c"
	"KeccakP-1600-reference.h"
	"KeccakP-1600-SnP.h"
	"KeccakP-1600-times2-on1.c"
	"KeccakP-1600-times2-SnP.h"
	"KeccakP-1600-times4-on1.c"
	"KeccakP-1600-times4-SnP.h"
	"KeccakP-1600-times8-on1.c"
	"KeccakP-1600-times8-SnP.h"
	"KeccakSponge.c"
	"KeccakSponge.h"
	"KeccakSponge.inc"
	"Ketjev2.c"
	"Ketjev2.h"
	"Ketjev2.inc"
	"Keyakv2.c"
	"Keyakv2.h"
	"Keyakv2.inc"
	"Motorist.c"
	"Motorist.h"
	"Motorist.inc"
	"Phases.h"
	"PlSnP-Fallback.inc"
	"SimpleFIPS202.c"
	"SimpleFIPS202.h"
	"SP800-185.c"
	"SP800-185.h"
	"SP800-185.inc"
)

rm -rf ./src/libkeccak

make --directory=./util/KeccakCodePackage ${IMPL}/libkeccak.a.pack
tar -xf ./util/KeccakCodePackage/bin/${IMPL}_libkeccak.a.tar.gz

mkdir ./src/libkeccak
for FILE in "${FILES[@]}"
do
	mv ./${IMPL}/libkeccak.a/${FILE} ./src/libkeccak
done

rm -rf ./${IMPL}
