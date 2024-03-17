var express = require("express");

var path = require("path");
var bodyParser = require("body-parser");

const port = 3000;

var app = express();
var urlencodedParser = bodyParser.urlencoded({ extended: false });
app.use(express.static(path.join(__dirname, 'public')));

//setup template engine
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "pug");

app.get("/", function(request, response) {
    response.send("Let's start coding");
});

app.listen(port, () => {
    console.log(`server listening on ${port}`);
});