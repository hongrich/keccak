'use strict'
var createHash = require('./lib/api')(require('bindings')('keccak'))
createHash.tupleHash128 = require('bindings')('tupleHash').tupleHash128
createHash.tupleHash256 = require('bindings')('tupleHash').tupleHash256
module.exports = createHash
