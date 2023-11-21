function initBMICalculator() {
    update_bmi();
}


function update_bmi() {
    var weight = Number(document.getElementById("input_field_weight").value);
    var height = Number(document.getElementById("input_field_height").value);
    let result_container = document.getElementById("bmi_result_value");
    let result_text = document.getElementById("bmi_result_text");

    result_text.style.color = "black";
    result_container.innerText = "/";
    result_text.innerText = "-";
    if (weight <= 0 || height <= 0 || isNaN(weight) || isNaN(height)) { // || weight.length == 0 || height.length == 0) {
        return
    }
    
    
    let result = calculate_bmi(weight, height);
    update_html_content(result,result_text,result_container);
    
}

function update_html_content(result,result_text,result_container) {
    var new_result_text_color;
    var new_result_text_content;

    if (result < 18.5) {
        new_result_text_content = "You have underweight!";
        new_result_text_color = "rgba(206, 206, 18, 1)";
    }
    if (result >= 18.5 && result <= 24.9) {
        new_result_text_content = "You have an optimum weight";
        new_result_text_color = "rgba(70, 237, 77, 1)";
    }
    if (result > 24.9 && result <= 29.9) {
        new_result_text_content = "You have overweight!";
        new_result_text_color = "rgba(206, 206, 18, 1)";
    }
    if (result > 29.9 && result <= 34.9) {
        new_result_text_content = "You have Class I obesity!";
        new_result_text_color = "rgba(245, 138, 39, 1)";
    }
    if (result > 34.9 && result <= 39.9) {
        new_result_text_content = "You have Class II obesity!";
        new_result_text_color = "rgba(239, 112, 112, 1)";
    }
    if (result > 39.9) {
        new_result_text_content = "HUh?";
        new_result_text_color = "rgba(255, 0, 0, 1)";
    }

    result_text.style.color = new_result_text_color;
    result_text.innerText = new_result_text_content;
    result_container.innerText = Number((result).toFixed(2));
}

function calculate_bmi(weight, height) {
    return weight/((height/100)**2);
}