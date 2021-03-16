let d = [];

function setup() {
    createCanvas(400, 400);
    for (let i = 0; i < 1000; i++) {

        d[i] = new drop;

    }

}

function draw() {
    background(230, 230, 250);
    for (let i = 0; i < d.length; i++) {

        d[i].fall();
        d[i].show();
       
        d[i].mem ="j";
    }




}




