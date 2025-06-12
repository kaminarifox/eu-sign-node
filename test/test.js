const addon = require("../dist/binding.js");
const assert = require("node:assert");

const signedData = require('fs').readFileSync(__dirname + '/signed.txt.p7s')

const euSign = new addon.EuSignNode()

euSign.Initialize('/opt/iit/eu/sw')
euSign.SetSettings();

const obj = euSign.VerifyDataInternal(signedData);
const internalData = obj.internalData.toString()

console.log(obj);
console.log(internalData)

assert.match(internalData, /^\[\[.+\]\]$/);
