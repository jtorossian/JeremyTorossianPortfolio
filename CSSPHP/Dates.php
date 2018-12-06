<html>

<head>
		<title> Dates </Title>
		<h1 style="text-align: center"> Appointment Dates </h1>
</head>

<body>

<b>

<center>
<?php
	$dsn = 'mysql:host=students;dbname=cs566105';
        $username = 'cs566105';
        $password = 'QTYsQwScTf';
        $dbh =  new PDO($dsn, $username, $password);

	$sql = 'select * from appointment group by date';

	echo '<form action="Dates.php" method="post">';
	echo '<select name = "date">';

	foreach($dbh->query($sql) as $row)
	{
	echo '<option value= ';
	echo $row["date"];
	echo ' ">';
	echo $row["date"];
	echo '</option>';
	}

	echo '</select>';
	echo '<br><input type= "submit" name= "submit" value= "Show">';
	echo '<br><input type= "reset" name= "reset" value= "Reset"> <br>';
	echo '</form>';

	echo "The following patients have appointments on this day ";
	echo '<br>';
	echo '<br>';

	if($_SERVER['REQUEST_METHOD']=='POST')
	{
	$own = $_POST['date'];
	$sql = "select time, firstName, lastName from patient,appointment where appointment.patientID = patient.patientID and date = '$own'";

	foreach($dbh->query($sql) as $row)
	{
	echo $row['firstName'];
	echo  " ";
	echo $row['lastName'];
	echo " : ";
	echo $row['time'].'<br>';
	}

	}

?>
</center>

<br/>
<br/>
<br/>

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
