'use strict'
var createHash = require('./lib/api')(require('bindings')('keccak'))
createHash.tupleHash128 = require('bindings')('sp800_185').tupleHash128
module.exports = createHash
