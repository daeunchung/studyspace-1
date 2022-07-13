var mysql      = require('mysql');
var connection = mysql.createConnection({
  host     : 'localhost',
  port     : '3307',
  user     : 'nodejs',
  password : 'mx9caj',
  database : 'opentutorials'
});
 
connection.connect();
 
connection.query('SELECT * FROM topic', function (error, results, fields) {
  if (error) {
    console.log(error);
  }
  console.log(results);
});
 
connection.end();