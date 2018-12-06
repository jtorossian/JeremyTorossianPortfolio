<html>

<!--
Name: Jeremy Torossian
Section: 1
Instructor: Georgia Brown
TA: Ishaan Mohammed
Semester: Spring
-->


<head>
		<title> Page 1 </Title>
		<h1 style="text-align: center"> Page 1 </h1>
</head>

<body>

<b>
<center>
<?php
	$dsn = 'mysql:host=students;dbname=z1821996';
	$username = 'z1821996';
	$password = '1997Jan01';
	$dbh =  new PDO($dsn, $username, $password); //Connects to the database

	$query = $dbh->query("select BoatName, Firstname, Lastname,  Name, SlipNum  from Owner, MarinaSlip, Marina where Owner.Ownernum = MarinaSlip.Ownernum and Marina.MarinaNum = MarinaSlip.MarinaNum;");
	//Collects the query
	//Creates the table
	echo '<table>
	<tr>
        <th> Boat Name </th>
        <th> First Name </th>
        <th> Last Name </th>
	<th> Marina Name </th>
	<th> Slip Number </th>
        </tr>';

	while($row = $query->fetch(PDO::FETCH_ASSOC)) //Stores the query into the table
	{
		echo '<tr> 
			<td> '.$row["BoatName"].'</td>
			<td> '.$row["Firstname"].'</td>
			<td> '.$row["Lastname"].'</td>
			<td> '.$row["Name"].'</td>
			<td> '.$row["SlipNum"].'</td>
		</td>';
	}
echo '</table>'; //Closes the table
?>
</center>
<br/>
<br/>
<br/>

<center> <!--Creates directory that connects to the other pages-->
<a href="assgn10page2.php"> Page 2 </a> -
<a href="assgn10page3.php"> Page 3 </a> 
<br/>

<!--Creates the table-->
</center>
<table align="center"> 
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
