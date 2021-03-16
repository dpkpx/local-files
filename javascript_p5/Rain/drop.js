class drop {
   
    constructor() {
        this.x = random(width);
        this.y = random(-200, -50);
        this.yspeed = random(2, 4);
       
    }


    fall() {

        this.y = this.y + this.yspeed
        this.yspeed = this.yspeed + 0.005

        let y = this.y;
        if (y > width) {
            this.y = random(-200,0);
            this.yspeed = random(2, 4);
        }

    }




    show() {
        let alpha = map(this.yspeed, 2, 4, 50, 200)
        stroke(138, 43, 226, alpha);
        let size = map(this.yspeed, 2, 4, 2, 5)
        line(this.x, this.y, this.x, this.y + size);
       
    }




}