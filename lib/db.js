var mysql = require('mysql');
var db = mysql.createConnection({
    host     : 'localhost',
    port     : '3307',
    user     : 'nodejs',
    password : 'mx9caj',
    database : 'opentutorials' 
  });
  db.connect();
  module.exports = db;