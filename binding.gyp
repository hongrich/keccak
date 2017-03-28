{
  "targets": [{
    "target_name": "keccak",
    "sources": [
      "./src/addon.cc",
      "./src/libkeccak/KeccakSponge.c",
      "./src/libkeccak/KeccakP-1600-reference.c"
    ],
    "include_dirs": [
      "<!(node -e \"require('nan')\")"
    ],
    "defines": [
      "KeccakP200_excluded=1",
      "KeccakP400_excluded=1",
      "KeccakP800_excluded=1"
    ],
    "cflags": [
      "-Wall",
      "-Wno-maybe-uninitialized",
      "-Wno-uninitialized",
      "-Wno-unused-function",
      "-Wextra"
    ]
  },{
    "target_name": "tupleHash",
    "sources": [
      "./src/tupleHash.cc",
      "./src/libkeccak/SP800-185.c",
      "./src/libkeccak/KeccakSponge.c",
      "./src/libkeccak/KeccakP-1600-reference.c",
      "./src/libkeccak/KeccakP-1600-times2-on1.c",
      "./src/libkeccak/KeccakP-1600-times4-on1.c",
      "./src/libkeccak/KeccakP-1600-times8-on1.c"
    ],
    "include_dirs": [
      "<!(node -e \"require('nan')\")"
    ],
    "defines": [
      "KeccakP200_excluded=1",
      "KeccakP400_excluded=1",
      "KeccakP800_excluded=1"
    ],
    "cflags": [
      "-Wall",
      "-Wno-maybe-uninitialized",
      "-Wno-uninitialized",
      "-Wno-unused-function",
      "-Wextra"
    ]
  }]
}
