#!/usr/bin/node

const request = require('request');
const episode = process.argv[2];
console.log(input);

// Takes in user input - <Movie ID>
// Display one character name per line
// Characters in same order as /films/ endpoint

const url = "https://swapi-api.hbtn.io/api/films/";

// Films response is JSON, parse until key == characters