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
    "target_name": "sp800_185",
    "sources": [
      "./src/SP800-185.cc",
      "./src/libkeccak/SP800-185.c"
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
