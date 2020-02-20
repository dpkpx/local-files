const ctx = document.getElementById("canvas").getContext("2d");
setInterval(draw, 1000/30);


let x = 0;


function draw() {
    ctx.fillStyle = "rgb(150,255,150)";
    ctx.fillRect(0, 0, 400, 400);
    ctx.fillStyle = "black";
    ctx.beginPath();
    ctx.moveTo(75, 50);
    ctx.lineTo(100, 75);
    ctx.lineTo(100, 25);
    ctx.lineTo(75,50);
    ctx.fill();
    ctx.strokeStyle = "red";
    ctx.stroke();

    

    //console.log("alpha");

}
