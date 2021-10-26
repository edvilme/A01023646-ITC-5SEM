const yargs = require('yargs');
const notes = require('./notes');

yargs.version('0.0.1')

// Add (create) note
yargs.command({
    command: 'add', 
    describe: 'Create a new note and save to document', 
    builder: {
        title: {
            describe: 'Note title (must be unique)', 
            demandOption: true, 
            type: 'string'
        }, 
        body: {
            describe: 'Note body', 
            demandOption: true, 
            type: 'string'
        },
        'prevent-correction': {
            describe: 'Prevents a note from being updated if it already exists', 
            demandOption: false, 
            type: 'boolean'
        }
    }, 
    handler: argv => {
        notes.createNote(argv.title, argv.body, argv['prevent-update'])
    }
})

// List (read all) notes
yargs.command({
    command: 'list', 
    describe: 'Lists all stored notes', 
    handler: notes.readAllNotes
})

// Read note
yargs.command({
    command: 'read', 
    describe: 'Read the contents from a specific note', 
    builder: {
        title: {
            describe: 'Note title used as an identifier', 
            demandOption: true, 
            type: 'string'
        }
    }, 
    handler: argv => {
        notes.readOneNote(argv.title)
    }
})

// Remove (delete) note
yargs.command({
    command: 'remove', 
    describe: 'Deletes a note and its contents from the file', 
    builder: {
        title: {
            describe: 'Note title used as an identifier', 
            demandOption: true,
            type: 'string'
        }
    }, 
    handler: argv => {
        notes.deleteNote(argv.title)
    }
})

yargs.parse()