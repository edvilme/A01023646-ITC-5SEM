const express = require('express');
const path = require('path');
const handlebars = require('express-handlebars');
const _weather = require('./weather.js')
const app = express();

app.use(express.static('public'));

app.set('view engine', 'hbs')
app.engine('hbs', handlebars({
    layoutsDir: path.join(__dirname, '../views/layouts'), 
    partialsDir: path.join(__dirname, '../views/partials'),
    extname: 'hbs'
}))

app.get('/city/:city', async (req, res) => {
    const weather = await _weather.getCity(req.params.city);
    const background = await _weather.getBackground(weather.current.weather_descriptions[0])

    res.render('index', {
        city: req.params.city,
        weather, 
        background
    })
})

app.listen(process.env.PORT || '8080', ()=>{
    console.log('App listening at port ' + (process.env.PORT || '8080'))
})