const fetch = require('node-fetch');
const pexels = require('pexels')

// Weather key
const WEATHER_KEY = "61ab3fd4be174729c923900d9e0982ef";
// Pexels key
const PEXELS_KEY = "563492ad6f9170000100000176e097a6ffe14e7ba34c60b7f3543064";

const getCity = async city => {
    const weather_raw = await fetch(`http://api.weatherstack.com/current?access_key=${WEATHER_KEY}&query=${city}&units=m`)
    const weather_json = await weather_raw.json();
    console.dir(weather_json)
    return weather_json;
}

const storedBackgrounds = {}

const getBackground = async (weather, city) => {
    if(storedBackgrounds[city+'-'+weather]) return storedBackgrounds[city+'-'+weather];

    const client = pexels.createClient(PEXELS_KEY);
    const results = await client.photos.search({
        query: weather + ' weather', 
        size: 'medium', 
        orientation: 'landscape'
    })
    // TODO: Make random
    storedBackgrounds[city+'-'+weather] = results.photos[Math.floor(Math.random()*results.photos.length)];
    console.dir(storedBackgrounds[city+'-'+weather]);
    return storedBackgrounds[city+'-'+weather];
}

module.exports = {getCity, getBackground}