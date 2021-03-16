let vehical = [];
let food = [];
let poision = [];
let count = 0;
let show = true;
let currentgen = 1;
let val = 1; 
function setup() {
    createCanvas(400, 400);

    for (let i = 0; i < 100; i++) {
        food[i] = createVector(random(width), random(height))

    }
    for (let i = 0; i < 50; i++) {
        poision[i] = createVector(random(width), random(height))

    }
    for (let j = 0; j < 10; j++) {
        vehical[j] = new arrow;
    }
}

function draw() {
    for (let l = 0; l < val; l++) {

        background(51);
        for (let i = 0; i < food.length; i++) {
            fill(0, 255, 0)
            ellipse(food[i].x, food[i].y, 10, 10)

        }
        for (let i = 0; i < poision.length; i++) {
            fill(255, 0, 0);
            ellipse(poision[i].x, poision[i].y, 10, 10)
        }

        let fit = null;
        let temp = 0;
        for (let j = 0; j < vehical.length; j++) {

            vehical[j].update();
            vehical[j].show();
            if (show) {
                val = 1;
            }
            for (let k = 0; k < vehical.length; k++) {
                if(k!=j){
                    vehical[j].seek(vehical[k].pos, false);

                }

            }
            vehical[j].seek(poision, false);
            vehical[j].seek(food, true);

            if (vehical[j].health > temp) {
                temp = vehical[j].health;
                fit = j;
            }
            if (vehical[j].isdead()) {
                vehical.splice(j, 1);
            }
        }
        if (!show && vehical[fit]) {
            // vehical[fit].show();
            val = 1000;
        }
        for (let k = 0; k < vehical.length; k++) {
            if (k == fit) {
               vehical[fit].col = color(0,255,0);
            } else {
               vehical[k].col = color(map(vehical[k].health, 0,100, 255,0),0,0);
               // console.log(map(vehical[k].health, 0,100, 0,255));
            }
        }
       // if (vehical[fit]) { console.log(vehical[fit].health, "gen-", vehical[fit].gen, "current gen", currentgen); }
        if (count == 1000 && vehical[fit]) {
            console.log("reproduced");
            vehical.push(new arrow);
            vehical[vehical.length - 1].rfood = vehical[fit].rfood + random(-1, 1)
            vehical[vehical.length - 1].rpoision = vehical[fit].rpoision + random(-1, 1)
            vehical[vehical.length - 1].maxspeed = vehical[fit].maxspeed + random(-1, 1);
            vehical[vehical.length - 1].maxforce = vehical[fit].maxforce + random(-0.2, 0.2)
            vehical[vehical.length - 1].gen = vehical[fit].gen + 1;
            currentgen++;
             vehical[fit].health =100;
            count = 0;
        }
        count++;
    }
}
function mouseClicked() {
    if (show) {
        show = false;
    } else {
        show = true;
    }

}