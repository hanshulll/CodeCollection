document.onkeydown = function(e) {
	if(event.keyCode == 123) {
		return false;
	}
	if (event.button == 2) {
		return false;
	}
	if(e.ctrlKey && e.shiftKey && e.keyCode == 'I'.charCodeAt(0)) {
		return false;
	}
	if(e.ctrlKey && e.shiftKey && e.keyCode == 'C'.charCodeAt(0)) {
		return false;
	}
	if(e.ctrlKey && e.shiftKey && e.keyCode == 'V'.charCodeAt(0)) {
		return false;
	}
	if(e.ctrlKey && e.shiftKey && e.keyCode == 'J'.charCodeAt(0)) {
		return false;
	}
	if(e.ctrlKey && e.keyCode == 'U'.charCodeAt(0)) {
		return false;
	}
	if(e.ctrlKey && e.keyCode == 'V'.charCodeAt(0)) {
		return false;
	}
}
