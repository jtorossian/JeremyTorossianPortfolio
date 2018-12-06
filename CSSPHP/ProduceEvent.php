<html>

<style type="text/css">
label.firstColumn{
	float: left;
	width: 15%;
	text-align: right;
	padding-right: 12px;
	font-size: 25px;
	clear: left;
}


</style>

<head>
		<title> Insert Artist </Title>
		<link rel="stylesheet" href="style.css">
</head>

<body>

<b>


<?php

	$dsn = 'mysql:host=students;dbname=z1821996';
        $username = 'z1821996';
        $password = '1997Jan01';
        $dbh =  new PDO($dsn, $username, $password);
	$sql = "select * from event group by eventID";

	echo'<img src="GEMBanner.jpg"  width="100%" />';
 

	echo '<div class="topnav">
 	<a href="#home">Home</a>
  	<div class="adropdown">
		<button class="adropbtn">Artist 
		<i class="fa fa-caret-down"></i>
		</button>
		<div class="adropdown-content">
      			<a href="#">Create Artist</a>
			<a href="#">Update Artist</a>
        		</div>
  		</div>

	<div class="bdropdown">
		<button class="bdropbtn">Band 
		<i class="fa fa-caret-down"></i>
		</button>
		<div class="bdropdown-content">
      			<a href="#">Create Band</a>
			<a href="#">Update Band</a>
        		</div>
  		</div>

	<div class="cdropdown">
		<button class="cdropbtn">Agent 
		<i class="fa fa-caret-down"></i>
		</button>
		<div class="cdropdown-content">
      			<a href="#">Create Agent</a>
			<a href="#">Update Agent</a>
        		</div>
  		</div>

	<div class="ddropdown">
		<button class="ddropbtn">Vendor 
		<i class="fa fa-caret-down"></i>
		</button>
		<div class="ddropdown-content">
      			<a href="#">Create Vendor</a>
			<a href="#">Update Vendor</a>
        		</div>
  		</div>


	<div class="edropdown">
		<button class="edropbtn">Event 
		<i class="fa fa-caret-down"></i>
		</button>
		<div class="edropdown-content">
      			<a href="#">Create Event</a>
			<a href="#">Approve Event</a>
			<a href="#">Update Event</a>
		        <a href="#">Check Event Status</a>
        		</div>
  		</div>



	<div class="fdropdown">
		<button class="fdropbtn">Report 
		<i class="fa fa-caret-down"></i>
		</button>
		<div class="fdropdown-content">
      			<a href="#">Link 1</a>
			<a href="#">Link 2</a>
			<a href="#">Link 3</a>
        		</div>
  		</div>
</div>';


	echo'<div class="signon">
	<p><b><a href="default.asp" target="_blank">Sign-On</a></b></p>
	</div>';


	echo '<div class="titles">';
	echo '<h2 style="float: left; width: 34%; text-align: left;">Event Information</h2>';
	echo '<p style="float: left; width: 10%; text-align: center;">Text Middle</p>';
	echo '<p style="float: left; width: 30%; text-align: right;">Text Right</p>';
	echo '<div class="clear">';
	echo '</div>';
	echo '</div>';
	echo '<div class="seperator">';
	echo '</div>';
	echo '<form id="reportForm">';
	echo '<div>';
	echo '<br>';
	echo "<label for='firstColumn' class='firstColumn'> Event Name:  </label>";
	echo '<output id="out" class="firstColumn"><font size="5">This is the output.</font></output>';
	echo '</div>';
	echo '<br>';
	echo '<div>';
	echo "<label for='firstColumn' class='firstColumn'> Date:  </label>";
	echo '<output id="out"> <font size="5">This is the output.</font></output>';
	echo '</div>';
	echo '<br>';
	echo '<div>';
	echo "<label for='firstColumn' class='firstColumn'> Time:  </label>";
	echo '<output id="out"><font size="5">This is the output.</font></output>';
	echo '</div>';

	echo '<div class = "vline">';
	echo '</div>';
	echo '<div class = "vline2">';
	echo '</div>';
	echo '<div class="seperator2">';
	echo '</div>';


	if($_SERVER['REQUEST_METHOD']=='POST')
	{
	$own = $_POST['event'];
	$sql = "select * from event where eventID = '$own'";

		 foreach($dbh->query($sql) as $row)
		{
		echo "Event Name";			

		}

	}

?>

</body>


</html>
