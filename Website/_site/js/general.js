$(document).ready(function() {
	navBar()
})

function navBar() {
	$.get("includes/navbar.html", function(data) {
		$("body").prepend(data);
		
		if(location.pathname.includes("index")) $("#indTab").addClass("active")
		else if(location.pathname.includes("secondary")) $("#sTab").addClass("active")
	});
}