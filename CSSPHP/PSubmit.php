<html>

<head>
		<title> Insert Patient </Title>
		<h1 style="text-align: center"> Please insert patient into database </h1>
</head>

<body>

<b>

<?php
	$dsn = 'mysql:host=courses;dbname=cs566105';
        $username = 'cs566105';
        $password = 'QTYsQwScTf';
        $dbh =  new PDO($dsn, $username, $password);
	$sql = "select * from therapist";

	echo '<form name="pat" id="pat" action="PSubmit.php" method="post">';
	echo "<label for='firstName'> First Name </label>";
	echo "<input type='text' name='firstName' id='firstName'>";
	echo "<label for='lastName'> Last Name </label>";
	echo "<input type='text' name='lastName' id='lastName'>";
	echo "<label for='address'> Address </label>";
	echo "<input type='text' name='address' id='address'>";
	echo "<label for='phoneNumber'> Phone Number </label>";
	echo "<input type='text' name='phoneNumber' id='phoneNumber'>";
	echo " ";

	echo '<select name = "therapistID">';
        foreach($dbh->query($sql) as $row)//Stores each boatname into the dropdown box
        {
        echo '<option value= ';
        echo $row["therapistID"];
        echo '">';
        echo $row["lastName"];
        echo '</option>';
        }

	echo '</select>';
	//echo "<label for='therapistID'> Therapist Id Number </label>";
	//echo "<input type='text' name='therapistID' id='therapistID'>";
	echo '<br><input type="submit" value="Insert Patient"> <input type="Reset" value="Clear"><br>';
	echo '<input type="hidden" name="which" value="pat">';
	echo "</form>";

	if($_SERVER['REQUEST_METHOD']=='POST')
	{
	 if($_POST['which']=='pat')
	{
	 $fname=$_POST['firstName'];
	 $lname=$_POST['lastName'];
	 $address=$_POST['address'];
	 $pnumber=$_POST['phoneNumber'];
	 $therapistID=$_POST['therapistID'];
	 $insertSQL="insert into patient (firstName, lastName, address, phoneNumber, therapistID) values (?,?,?,?,?)";
	 }
	 try
	 {
	  $stmt = $dbh->prepare($insertSQL);
	  $ok = $stmt->execute(array($fname, $lname, $address, $pnumber, $therapistID));
	  echo 'Patient '.$fname.' '.$lname.' added successfully!';
	 }

	 catch(PDOException $e)
	 {
	  echo 'Cannot add this patient.';
	  echo 'Error:' .$e->getMessage();
	 }
	}



?>

<br/>
<br/>
<br/>

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
