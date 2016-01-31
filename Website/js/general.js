$(document).ready(function() {
	navBar()
})

function navBar() {
	$.get("includes/navbar.html", function(data) {
	    $("body").prepend(data);
	});
}