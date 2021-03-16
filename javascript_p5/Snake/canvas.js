let x = 0;
let y = 0;
let direction = 1;
let snake;
let foodX;
let foodY;
let row;
let temp;
let col;
let gameOver = false;

function setup() {
    createCanvas(400, 400);
    x = width / 2;
    y = height / 2;
    row = width / 10;
    col = height / 10;

    frameRate(5);
    foodX = floor(random(1, row)) * 10;
    foodY = floor(random(1, col)) * 10;
    snake = [[x, y], [x - 10, y], [x - 20, y]];
}


function draw() {
    background(50);
    stroke(255)
    //noStroke();
    //  rectMode(CENTER);
    fill(0, 255, 0)

    rect(foodX, foodY, 10, 10);


    if (gameOver == true) {
        fill(255, 0, 0);
        textAlign(CENTER);
        stroke(0, 150, 150);
        strokeWeight(4);
        textSize(34);
        text("Game Over!", width / 2, height / 2);
        text(`Score : ${snake.length}`, width / 2, height / 2 + 40);


    }



    if (dist(foodX, foodY, x, y) <= 0) {
        snake.push([(snake[snake.length - 1][0]), (snake[snake.length - 1][1])]);

        foodX = floor(random(1, row)) * 10;
        foodY = floor(random(1, col)) * 10;
    }
    stroke(255)
    strokeWeight(1)
    for (let i = 0; i < snake.length; i++) {
        if (i == 0) {
            fill(255, 0, 0);
        } else {

            fill(0);
            // if(i>){

            if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1]) {
                gameOver = true;

            }
        }

        rect(snake[i][0], snake[i][1], 10, 10);

    }


    if (x < -10) {
        gameOver = true;

    } else if (x > width - 10) {
        gameOver = true;


    }
    if (y < -10) {
        gameOver = true;


    } else if (y > height - 10) {
        gameOver = true;


    }

    if (!gameOver) {
        if (direction == 0) {
            x -= 10;

        } else if (direction == 1) {
            x += 10;


        } else if (direction == 2) {
            y -= 10;



        } else if (direction == 3) {
            y += 10;

        }
        snake.unshift([x, y]);
        snake.pop();
    }

    textSize(16);
    fill(0);
    noStroke();
    textAlign(CENTER);
    text(`Score : ${snake.length}`, width - 42, 15);


}





function keyPressed() {
    if (keyCode === LEFT_ARROW) {
        if (direction == 1) {
            direction = 1;
        } else {
            direction = 0;
        }
    } else if (keyCode === RIGHT_ARROW) {
        if (direction == 0) {
            direction = 0;
        } else {
            direction = 1;
        }
    }
    else if (keyCode === UP_ARROW) {
        if (direction == 3) {
            direction = 3;
        } else {
            direction = 2;
        }
    }
    else if (keyCode === DOWN_ARROW) {
        if (direction == 2) {
            direction = 2;
        } else {
            direction = 3;
        }
    } else if (keyCode === 32) {

        if (gameOver == true) {
            gameOver = false;
        } else {
            snake.push([(snake[snake.length - 1][0]), (snake[snake.length - 1][1])]);
        }
    }
}

