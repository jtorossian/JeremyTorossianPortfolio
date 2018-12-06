<html>
<!--
Name: Jeremy Torossian
Section: 1
Instructor: Georgia Brown
TA: Ishaan Mohammed
Semester: Spring
-->

<head>
		<title> Page 3 </Title>
		<h1 style="text-align: center"> Page 3 </h1>
</head>

<body>

<b>
<center>
<?php
	$dsn = 'mysql:host=students;dbname=z1821996';
        $username = 'z1821996';
        $password = '1997Jan01';
        $dbh =  new PDO($dsn, $username, $password);//Connects to the database

	$sql = 'select * from MarinaSlip';//Collects the query

	//Creats the dropdown box
	echo '<form action="assgn10page3.php" method="post">';
	echo '<select name = "boatname">';

	foreach($dbh->query($sql) as $row)//Stores each boatname into the dropdown box
	{
	echo '<option value= ';
	echo $row["SlipID"];
	echo '">';
	echo $row["BoatName"];
	echo '</option>';
	}

	//Creates the submit and reset box.
	echo '</select>';
	echo '<br><input type= "submit" name= "submit" value= "Show">';
	echo '<br><input type= "reset" name= "reset" value= "Reset"> <br>';
	echo '</form>';

	echo "Service Done: ";

	//When the user hits the submit button, it will bring up the services done on the boat
	if($_SERVER['REQUEST_METHOD']=='POST')
	{
	$own = $_POST['boatname']; //Assigns the selected boat to $own
	$sql = "select Description from ServiceRequest where SlipId = '$own'";//Creates the query
	$query = $dbh->query($sql);//Loads the query
	$row_count = $query->rowCount();//Gets the row count
	if($row_count == 0)//If there was no maintenance done, it brings up with message
	 {
	  echo "No service maintenance done.";
	 }


	foreach($dbh->query($sql) as $row)//Prints all the maitenance done to the boat
	{
	  echo $row['Description'].'<br>';
	}

	}

?>
</center>
<br/>
<br/>
<br/>

<!--Creates the directory that connects to each page-->
<center>
<a href="assgn10page1.php"> Page 1 </a> -
<a href="assgn10page2.php"> Page 2 </a>
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
