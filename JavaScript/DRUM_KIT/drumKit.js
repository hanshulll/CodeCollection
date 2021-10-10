var numberOfButtons =
	document.querySelectorAll(".child").length;

for (var j = 0; j < numberOfButtons; j++) {

document.querySelectorAll(".child")[j]
.addEventListener("click", function() {

	var buttonStyle = this.innerHTML;
	sound(buttonStyle);
});
}

document.addEventListener("keypress", function(event) {
sound(event.key);
});

function sound(key) {
switch (key) {
	case "w":
	var sound1 = new Audio("assets/hihat.mp3");
	sound1.play();
	break;

	case "a":
	var sound2 = new Audio("assets/bass.mp3");
	sound2.play();
	break;

	case "s":
	var sound3 = new Audio('assets/snare.mp3');
	sound3.play();
	break;

	case "d":
	var sound4 = new Audio('assets/highTom.mp3');
	sound4.play();
	break;

	case "j":
	var sound5 = new Audio('assets/lowTom1.mp3');
	sound5.play();
	break;

	case "k":
	var sound6 = new Audio('assets/lowTom2.mp3');
	sound6.play();
	break;

	case "l":
	var sound7 = new Audio('assets/lowTom3.mp3');
	sound7.play();
	break;

	default: console.log(key);
} }

