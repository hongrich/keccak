/*
Implementation by the Keccak, Keyak and Ketje Teams, namely, Guido Bertoni,
Joan Daemen, Michaël Peeters, Gilles Van Assche and Ronny Van Keer, hereby
denoted as "the implementer".

For more information, feedback or questions, please refer to our websites:
http://keccak.noekeon.org/
http://keyak.noekeon.org/
http://ketje.noekeon.org/

To the extent possible under law, the implementer has waived all copyright
and related or neighboring rights to the source code in this file.
http://creativecommons.org/publicdomain/zero/1.0/
*/

#ifdef KeccakReference
    #include "displayIntermediateValues.h"
#endif

#include "Ket.h"
#include "Ketjev2.h"

#ifndef KeccakP200_excluded
    #include "KeccakP-200-SnP.h"

    #define prefix                      KetjeJr
    #define prefixKet                   KetJr
    #define SnP                         KeccakP200
    #define SnP_width                   200
    #define SnP_PermuteRounds           KeccakP200_Permute_Nrounds
        #include "Ketjev2.inc"
    #undef prefix
    #undef prefixKet
    #undef SnP
    #undef SnP_width
    #undef SnP_PermuteRounds
#endif

#ifndef KeccakP400_excluded
    #include "KeccakP-400-SnP.h"

    #define prefix                      KetjeSr
    #define prefixKet                   KetSr
    #define SnP                         KeccakP400
    #define SnP_width                   400
    #define SnP_PermuteRounds           KeccakP400_Permute_Nrounds
        #include "Ketjev2.inc"
    #undef prefix
    #undef prefixKet
    #undef SnP
    #undef SnP_width
    #undef SnP_PermuteRounds
#endif

#ifndef KeccakP800_excluded
    #include "KeccakP-800-SnP.h"

    #define prefix                      KetjeMn
    #define prefixKet                   KetMn
    #define SnP                         KeccakP800
    #define SnP_width                   800
    #define SnP_PermuteRounds           KeccakP800_Permute_Nrounds
        #include "Ketjev2.inc"
    #undef prefix
    #undef prefixKet
    #undef SnP
    #undef SnP_width
    #undef SnP_PermuteRounds
#endif

#ifndef KeccakP1600_excluded
    #include "KeccakP-1600-SnP.h"

    #define prefix                      KetjeMj
    #define prefixKet                   KetMj
    #define SnP                         KeccakP1600
    #define SnP_width                   1600
    #define SnP_PermuteRounds           KeccakP1600_Permute_Nrounds
        #include "Ketjev2.inc"
    #undef prefix
    #undef prefixKet
    #undef SnP
    #undef SnP_width
    #undef SnP_PermuteRounds
#endif
