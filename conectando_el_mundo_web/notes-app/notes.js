const fs = require('fs')
const chalk = require('chalk');

/**
 * @typedef {Object} Note
 * @property {String} title - Title and unique identifier of note
 * @property {String} body - Text contents of note
 */


/**============================================================
 * Filesystem utils
 * ============================================================*/

/**
 * Opens JSON file to get its contents
 * @returns {Array<Note>}
 */
const open = () => {
    try{
        const data = fs.readFileSync('./notes.json').toString();
        return JSON.parse(data);
    } catch(e){
        throw "Could not open file"
    }
}
/**
 * 
 * @param {Array<Note>} data 
 */
const save = (data) => {
    try{
        fs.writeFileSync('./notes.json', JSON.stringify(data));
    } catch(e){
        throw "Could not save data to file"
    }
}

const createNote = (title, body, preventUpdate = false) => {
    try{
        const file = open();
        if(file.find(note => note.title == title)){
            if(preventUpdate) throw "A note with this title already exists"
            console.log(chalk.italic('A note with this title already exists, so its contents will be updated. Use the --prevent-correction flag to prevent this'))
            return updateNote(title, body);
        }
        file.push({title, body});
        save(file);
        console.log(chalk.bgGreen('Sucess'))
    } catch(e){
        console.error(chalk.bgRed(`Error: ${e}`))
    }
}

const readAllNotes = () => {
    try{
        const file = open();
        console.log(chalk.inverse('All notes'))
        for(let note of file){
            console.log()
            console.log(chalk.bold(note.title));
            console.log(note.body);
        }
    } catch(e){
        console.error(chalk.bgRed(`Error: ${e}`))
    }
}

const readOneNote = (title) => {
    try{
        const file = open();
        let note = file.find(note => note.title === title);
        if(note == undefined) throw "Could not find note"
        console.log()
        console.log(chalk.bold(note.title));
        console.log(note.body);
    } catch(e){
        console.error(chalk.bgRed(`Error: ${e}`))
    }
}

const updateNote = (title, body, preventAdd = false) => {
    try{
        const file = open();
        let note = file.find(note => note.title === title);
        if(note == undefined){
            if(preventUpdate) throw "Could not find note"
            console.log(chalk.italic('No note with this title exists, so a new one will be created. Use the --prevent-correction flag to prevent this'))
            return updateNote(title, body);
        }
        note.body = body;
        save(file);
    } catch(e){
        console.error(chalk.bgRed(`Error: ${e}`))
    }
}

const deleteNote = (title) => {
    try{
        const file = open();
        let nodeIndex = file.findIndex(note => note.title === title);
        file.splice(nodeIndex, 1);
        save(file);
        console.log(chalk.bgGreen('Sucess'))
    } catch(e){
        console.error(chalk.bgRed(`Error: ${e}`))
    }
}

module.exports = {createNote, readAllNotes, readOneNote, updateNote, deleteNote}