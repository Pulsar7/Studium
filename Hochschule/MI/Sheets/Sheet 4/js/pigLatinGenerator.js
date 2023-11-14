let vocals = [
    "a","e","i","o","u"
];

let special_chars = [
    "!","-",":",".","?","=","+","*","~","#","/","`","@","#","_",",",";",'"',"'"
];



function init() {
    console.log("Hello World");    
}


function generate_pig_latin() {
    var input_text = document.getElementById("input_sentence").value;
    let words = input_text.split(" ");
    let new_pig_latin_text = "";
    for (let i = 0; i < words.length; i++) {
        if (no_special_chars(words[i])) {
            if (vocals.includes(words[i][0].toLowerCase())) {
                words[i] += "yay";
            } else {
                // if (vocals.includes(words[i][1].toLowerCase()) || anywhere_vocal(words[i].toLowerCase())) {
                words[i] += words[i][0];
                words[i] = words[i].slice(0,0)+words[i].slice(1,words[i].length);
                words[i] += "ay";
                // }
            }
        }
        if (i > 0) {
            new_pig_latin_text += " ";
        }
        new_pig_latin_text += words[i];
    }

    document.getElementById("pig_latin_output").innerText = new_pig_latin_text;
}

function anywhere_vocal(word) {
    /*
        Search for vocal in the word
        
        # Probably not required
    */
    for (let i = 0; i < vocals.length; i++) {
        if (word.includes(vocals[i])) {
            return true;
        }
    }
    return false;
}

function no_special_chars(word) {
    /*
        Search for special character in word
    */
    for (let i = 0; i < special_chars.length; i++) {
        if (word.includes(special_chars[i])) {
            return false;
        }
    }
    return true;
}