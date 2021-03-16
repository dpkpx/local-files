
let x = 0;
let Switch = true;
function setup() {
    createCanvas(400, 400);

}

function draw() {

    background(0, 55, 222, 65);
    noStroke();
    fill(255);
    rect(x, map(noise(x * 0.015), 0, 1, 0, 400), 100, 20, 14);
    fill(0);
    rect((width - 100 - x), map(noise(7 + x * 0.015), 0, 1, 0, 400), 100, 20, 14);



    if (Switch == true) {
        x++;
    }
    else {
        x--;
    }
    if (x == width - 100) {
        Switch = false;
    } else if (x == 0) {
        Switch = true;
    }

}
