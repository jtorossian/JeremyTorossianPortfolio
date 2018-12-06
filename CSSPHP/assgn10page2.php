<html>
<!--
Name: Jeremy Torossian
Section: 1
Instructor: Georgia Brown
TA: Ishaan Mohammed
Semester: Spring
-->

<head>
		<title> Page 2 </Title>
		<h1 style="text-align: center"> Page 2 </h1>
</head>

<body>

<b>
<center>
<?php
	$dsn = 'mysql:host=students;dbname=z1821996';
        $username = 'z1821996';
        $password = '1997Jan01';
        $dbh =  new PDO($dsn, $username, $password); //Connects to database

	$sql = 'select * from Owner'; //Collects Query and stores it into $swl

	//Creates the dropdown form
	echo '<form action="assgn10page2.php" method="post">';
	echo '<select name = "owner">';


	foreach($dbh->query($sql) as $row)//Stores each "lastname" into the form
	{
	echo '<option value= ';
	echo $row["OwnerNum"];
	echo ' ">';
	echo $row["LastName"];
	echo '</option>';
	}

	//Creates the sumbit and rest boxes
	echo '</select>';
	echo '<br><input type= "submit" name= "submit" value= "Show">';
	echo '<br><input type= "reset" name= "reset" value= "Reset"> <br>';
	echo '</form>';

	echo "Boats Owned:";
	echo '<br>';
	echo '<br>';

	//When the user clicks submit it brings up a list of the boats that owner possesses.
	if($_SERVER['REQUEST_METHOD']=='POST')
	{
	$own = $_POST['owner'];
	$sql = "select BoatName from MarinaSlip where OwnerNum = '$own'"; //Collects the query based on the specific owner

	foreach($dbh->query($sql) as $row)//Prints out each boat owned.
	{
	echo $row['BoatName'].'<br>';
	}

	}

?>
</center>
<br/>
<br/>
<br/>

<!--Creates directory that connects to each peach-->
<center>
<a href="assgn10page1.php"> Page 1 </a> -
<a href="assgn10page3.php"> Page 3 </a>
<br/>

<table align="center"> <!--Creates the table-->
        <tr>
        <th> Name </th>
        <th> Section Number </th>
        <th> Due Date </th>
        </tr>

        <tr>
        <td> Jeremy Torossian </td>
        <td> 1 </td>
        <td> 4/18/18 </td>
</table>

</b>
</body>

</html>
