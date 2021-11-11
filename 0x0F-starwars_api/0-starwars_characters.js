#!/usr/bin/node

const request = require('request');

// Takes in user input - <Movie ID>
const episode = process.argv[2];

// Display one character name per line
// Characters in same order as /films/ endpoint
const url = 'https://swapi-api.hbtn.io/api/films/'.concat(episode);
request(url, function(error, response, body) {
    if (error) throw error;
    const people = JSON.parse(body).characters;

    people.forEach(character => {
        request(character, function(error, response, body) {
            if (error) throw error;
            console.log(JSON.parse(body).name);
        });
    });
});
