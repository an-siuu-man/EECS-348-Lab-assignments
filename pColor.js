function changeParagraphColor() {
    var border_R = document.getElementById("redValue").value;
    var border_G = document.getElementById("greenValue").value;
    var border_B = document.getElementById("blueValue").value;
    var border_width = document.getElementById("widthOfBorder").value;
    var bg_R = document.getElementById("rBG").value;
    var bg_G = document.getElementById("gBG").value;
    var bg_B = document.getElementById("bBG").value;

    var tag = document.getElementById("paragraph");
    tag.style.borderColor = `rgb(${border_R},${border_G},${border_B})`;
    tag.style.borderWidth = `${border_width}px`;
    tag.style.backgroundColor = `rgb(${bg_R},${bg_G},${bg_B})`;
   
}