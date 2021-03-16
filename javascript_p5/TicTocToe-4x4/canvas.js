let board = [['1', '2', '3', '4'],
['5', '6', '7', '8'],
['9', '10', '11', '12'],
['13', '14', '15', '16']];
let sclX;
let sclY;
let positions = [0, 1, 2, 3];
let currentPlayer = 'x';


function setup() {
    createCanvas(400, 400);
    sclX = width / 4;
    sclY = height / 4;

}


//minMax algorithm
function minMax(isMax, depth) {
    if (result() == 'x') {
        return +10;
    } else if (result() == 'o') {
        return -10;
    } else if (result() == 't') {
        return 0;
    }
    if (depth > 4) {
        return 0;
    }

    //Maximizer's move
    if (isMax) {
        let bestscore = -1000;
        for (let i = 0; i < 4; i++) {
            for (let j = 0; j < 4; j++) {
                if (board[i][j] != 'x' && board[i][j] != 'o') {
                    let temp = board[i][j];
                    board[i][j] = 'x';
                    bestscore = max(minMax(false, depth + 1), bestscore);
                    board[i][j] = temp;


                }
            }

        }
        return bestscore;
    } else {
        //Minimizer's move
        let bestscore = 1000;
        for (let i = 0; i < 4; i++) {
            for (let j = 0; j < 4; j++) {
                if (board[i][j] != 'x' && board[i][j] != 'o') {
                    let temp = board[i][j];
                    board[i][j] = 'o';
                    bestscore = min(minMax(true, depth + 1), bestscore);
                    board[i][j] = temp;


                }
            }

        }
        return bestscore;

    }

}

// returns best move
function move() {
    let bestscore = -1000;
    let bestmove = {
        x: 0,
        y: 0,
    };

    for (let i = 0; i < 4; i++) {
        for (let j = 0; j < 4; j++) {
            if (board[i][j] != 'x' && board[i][j] != 'o') {
                let temp = board[i][j];
                board[i][j] = 'x';
                let score = minMax(false, 1);
                board[i][j] = temp;
                if (score > bestscore) {
                    bestscore = score;
                    bestmove.x = i;
                    bestmove.y = j;
                }

            }
        }

    }
    return bestmove;
}

// //Result checking
function result() {
    let space = 0;

    //checking horizontaly
    for (let i = 0; i < 4; i++) {
        if (board[i][0] === board[i][1] && board[i][1] === board[i][2] && board[i][2] === board[i][3]) {
            return board[i][0];
        }
    }

    //checking vertically
    for (let i = 0; i < 4; i++) {
        if (board[0][i] === board[1][i] && board[1][i] === board[2][i] && board[2][i] === board[3][i]) {
            return board[0][i];
        }
    }

    //digonally
    if (board[0][0] === board[1][1] && board[1][1] === board[2][2] && board[2][2] === board[3][3]) {
        return board[0][0];
    } else if (board[0][3] === board[1][2] && board[1][2] === board[2][1] && board[2][1] === board[3][0]) {
        return board[0][3];
    }

    // checking available position
    for (let i = 0; i < 4; i++) {
        for (let j = 0; j < 4; j++) {
            if (board[i][j] != 'x' && board[i][j] != 'o') {

                space++;

            }
        }
    }
    if (space == 0) {
        return 't';
    }
}

function draw() {



    let off = 20;

    background(100);

    strokeWeight(4);
    stroke(0);
    //grid
    line(sclX, 0, sclX, height);
    line(2 * sclX, 0, 2 * sclX, height);
    line(3 * sclX, 0, 3 * sclX, height);
    line(0, sclY, width, sclY);
    line(0, 2 * sclY, width, 2 * sclY);
    line(0, 3 * sclY, width, 3 * sclY);

    //drawing players
    for (let i = 0; i < 4; i++) {
        for (let j = 0; j < 4; j++) {


            if (board[j][i] == 'x') {

                //drawing x
                stroke(255, 0, 0);
                line(i * sclX + off, j * sclY + off, (i * sclX) + sclX - off, (j * sclY) + sclY - off);
                line((i * sclX) + sclX - off, (j * sclY) + off, i * sclX + off, (j * sclY) + sclY - off);
            } else if (board[j][i] == 'o') {

                //drawing o
                stroke(255);
                noFill();
                ellipse((i * sclX) + sclX / 2, (j * sclY) + sclY / 2, sclX - off, sclY - off);
            }


        }
    }


    textSize(32);
    rectMode(CENTER);
    textAlign(CENTER, CENTER);
    //Result declaration
    if (result() == 'x' || result() == 'o') {

        currentPlayer = 'z';

        fill(0, 102, 153);
        stroke(255, 0, 0);
        text('Winner  is  ' + result(), width / 2, height / 2, width - 100, 100);

        noLoop();
    } else if (result() == 't') {

        fill(0, 102, 153);
        text('Its a Tie', width / 2, height / 2, width - 100, 100);
        noLoop();
    }

    // Algo playing
    if (currentPlayer == 'x') {
        let mo1 = move();
        let row = mo1.x;
        let col = mo1.y;
        

        if (board[row][col] != 'x' && board[row][col] != 'o') {

            board[row][col] = 'x';

            switchPlayer();
        }
    }

}

//player playing

function mousePressed() {
    let i = floor(mouseX / sclX);
    let j = floor(mouseY / sclY);
    if (i < 4 && i >= 0 && j < 4 && j >= 0) {
        if (board[j][i] != 'x' && board[j][i] != 'o') {
            board[j][i] = currentPlayer;

            switchPlayer();
        }
    }
   
}




// Switching players
function switchPlayer() {
    if (currentPlayer == 'x') {
        currentPlayer = 'o';

    } else if (currentPlayer == 'o') {
        currentPlayer = 'x';

    }

}