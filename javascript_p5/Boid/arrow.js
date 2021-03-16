class arrow {

    constructor() {
        this.pos = createVector(random(width), random(height))
        this.acceleration = createVector(0, 0);
        this.velocity = createVector(0, -1);
        this.rfood = random(5, 100);
        this.rpoision = random(5, 100);
        this.health = 100;
        this.maxspeed =  random(1, 5);
        this.maxforce =  random(0.0000001, 1);
        this.lifespan=0;
        this.col = map(this.health, 0, 100, 0, 255);
        this.gen=1;
    }


    show() {
       
        let a = this.velocity.heading() + PI / 2;
        push();
        translate(this.pos.x, this.pos.y);
        rotate(a)
        fill(this.col)
        triangle(0, -10, 5, 10, -5, 10);
        noFill();
        stroke(0, 255, 0)
        ellipse(0, 0, 2 * this.rfood, 2 * this.rfood)
        stroke(255, 0, 0)
        ellipse(0, 0, 2 * this.rpoision, 2 * this.rpoision)
        pop();
    }
    update() {
        this.velocity.add(this.acceleration);
        this.velocity.limit(this.maxspeed)
        this.pos.add(this.velocity);
        this.acceleration.mult(0);
        if (this.pos.x > width || this.pos.x < 0) {//||
            this.velocity.x = this.velocity.x * (-1);
        } else if (this.pos.y > height || this.pos.y < 0) {
            this.velocity.y = this.velocity.y * (-1);
        }
        this.health -= 0.1;
        this.lifespan++;
    }

    seek(food, isfood) {
        let closest = Infinity;
        if (isfood) {
            for (let i = food.length - 1; i >= 0; i--) {
                let d = p5.Vector.dist(food[i], this.pos);

                if (d < this.rfood) {
                    if (d < closest) {
                        closest = food[i];
                    }
                }
                if (this.foodeaten(food[i])) {
                    food[i] = createVector(random(width), random(height))
                    this.health += 5;
                }
            }
            if (closest != Infinity) {
                let desire = p5.Vector.sub(closest, this.pos)
                desire.setMag(this.maxspeed)
                let steer = p5.Vector.sub(desire, this.velocity)
                steer.limit(this.maxforce);
                this.applyForce(steer);
            }
        }else{
            for (let i = food.length - 1; i >= 0; i--) {
                let d = p5.Vector.dist(food[i], this.pos);

                if (d < this.rpoision) {
                    if (d < closest) {
                        closest = food[i];
                    }
                }
                if (this.foodeaten(food[i])) {
                    food[i] = createVector(random(width), random(height))
                    this.health -= 5;
                }
            }
            if (closest != Infinity) {
                let desire = p5.Vector.sub(closest, this.pos)
                desire.setMag(this.maxspeed)
                let steer = p5.Vector.sub(desire, this.velocity)
                steer.setMag(2);
                // steer.limit(this.maxforce);
                steer.mult(-1);
                this.applyForce(steer);
            }
        }
    }
    foodeaten(food) {
        let d = p5.Vector.dist(food, this.pos);
        if (d < 5) {
            return true;
        } else {
            return false;
        }

    }
    applyForce(force) {
        this.acceleration.add(force);
    }
    isdead() {
        if (this.health < 1) {
            return true;
        } else {
            return false;
        }
    }
}