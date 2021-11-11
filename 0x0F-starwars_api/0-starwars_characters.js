#!/usr/bin/node

const request = require('request');

// Takes in user input - <Movie ID>
const episode = process.argv[2];

// Display one character name per line
// Characters in same order as /films/ endpoint
const url = 'https://swapi-api.hbtn.io/api/films/'.concat(episode);
request(url, function (error, response, body) {
  if (error) throw error;
  const people = JSON.parse(body).characters;
  const toSort = {};

  // Call each character endpoint, connect name with output
  people.forEach(character => {
    request(character, function (error, response, body) {
      if (error) throw error;
      toSort[character] = JSON.parse(body).name;

      if (Object.keys(toSort).length === people.length) {
        printSorted(people, toSort);
      }
    });
  });

  function printSorted (people, toSort) {
    // Sort by character number
    people.forEach(character => {
      console.log(toSort[character]);
    });
  }
});
