#!/bin/bash

set -e

cd /usr/src/app \
  && npm install --ignore-scripts \
  && node-gyp clean \
  && node-gyp configure \
  && node-gyp build --debug

# gdb --args node test/test.js
node test/test.js

exec "$@"