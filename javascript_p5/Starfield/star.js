class star {

    constructor() {
        this.x = random(-width / 2, width / 2);
        this.y = random(-height / 2, height / 2);
        this.z = random(-width / 2, width / 2);
        this.pos = createVector(this.x, this.y);
        this.origin = createVector(0, 0);
        this.dir = p5.Vector.sub(this.pos, this.origin);
    }
    show() {

        let alpha = map(this.pos.mag(), 0, 282, 200, 255)
        let diameter = map(this.pos.mag(), 0, 282, 0, 6)
        fill(255, alpha);
        noStroke();
        ellipse(this.pos.x, this.pos.y, diameter, diameter);
        stroke(255)
       // line(this.temp.x, this.temp.y, this.pos.x, this.pos.y);
       

    }
    update() {
        let mag = map(this.pos.mag(), 0, 282, 0, 4)
        this.dir.setMag(mag)
        this.pos.add(this.dir);
        if (abs(this.pos.x) > width / 2 || abs(this.pos.y) > height) {
            this.pos.x = random(-150, 150);
            this.pos.y = random(-150,150);
            this.dir = p5.Vector.sub(this.pos, this.origin);
        }
    }
}