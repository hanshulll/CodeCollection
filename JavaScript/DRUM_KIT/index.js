var color = ['#9400D3','#4B0082','#0000FF','#00FF00',
             '#FFFF00', '#FF0000', '#FF7F00'];

document.addEventListener("keypress", function () {
    pickColor()
});

function pickColor() {
    document.getElementById("w").style.color = color[Math.floor(Math.random() * color.length)];
    document.getElementById("a").style.color = color[Math.floor(Math.random() * color.length)];
    document.getElementById("s").style.color = color[Math.floor(Math.random() * color.length)];
    document.getElementById("d").style.color = color[Math.floor(Math.random() * color.length)];
    document.getElementById("j").style.color = color[Math.floor(Math.random() * color.length)];
    document.getElementById("k").style.color = color[Math.floor(Math.random() * color.length)];
    document.getElementById("l").style.color = color[Math.floor(Math.random() * color.length)];
}



