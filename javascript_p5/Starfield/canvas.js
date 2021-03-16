let stars = [];

function setup() {
    createCanvas(600, 600);
    
    for (let i = 0; i < 100; i++) {
        stars[i] = new star;
    }
}

function draw() {
    translate(width/2,height/2)
    background(0);
    for (let i = 0; i < 100; i++) {
        stars[i].show();
        stars[i].update();
    }
  //  print(stars[1].pos);
}
