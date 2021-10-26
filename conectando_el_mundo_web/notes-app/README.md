**Conectando el mundo web** (Day 1)
---
# CLI Notes App
This basic utility allows to create, read, update and delete nodes from a JSON file. 

## Usage
This is a CLI utility
```bash
node index.js [command]
```
Available commands are:
- `add` Creates a new note into the document (or updates an existing one)
- `list` Lists all stored nodes in the document
- `read` Reads the content of a specidic note
- `remove` Deletes a note from the file 

You can use the `--help` command to get more info. 

## Improvements
Improvements could be made to increase the efficiency and usability of the utility, such as storing notes as key-value pairs inside an object instead of an array of objects, but this is only a proof of concept. 