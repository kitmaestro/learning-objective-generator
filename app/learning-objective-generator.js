#!/usr/bin/env node
const lib = require('./index');
const process = require('process');
const pkg = require('../package.json');

if (['-h', '--help', '-?'].includes(process.argv[2].toLowerCase())) {
    console.log('Hello World!');
}

if (['-v', '--version'].includes(process.argv[2].toLowerCase())) {
    console.log(`leobgen v${pkg.version}. By kenliten at KitMaestro.`);
}