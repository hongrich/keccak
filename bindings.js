'use strict'
var createHash = require('./lib/api')(require('bindings')('keccak'))
createHash.tupleHash128 = require('bindings')('tupleHash').tupleHash128
module.exports = createHash
