<html>

<head>
		<title> Insert Owner </Title>
		<h1 style="text-align: center"> Please insert owner into database </h1>
</head>

<body>

<b>

<?php
	$dsn = 'mysql:host=students;dbname=z1821996';
        $username = 'z1821996';
        $password = '1997Jan01';
        $dbh =  new PDO($dsn, $username, $password);

	//Creates the text box for each submission
	echo '<form name="own" id="own" action="assgn11page1.php" method="post">';
	echo "<label for='FirstName'> First Name </label>";
	echo "<input type='text' name='FirstName' id='FirstName'>";
	echo "<label for='LastName'> Last Name </label>";
	echo "<input type='text' name='LastName' id='LastName'>";
	echo "<label for='Address'> Address </label>";
	echo "<input type='text' name='Address' id='Address'>";
	echo "<label for='City'> City </label>";
	echo "<input type='text' name='City' id='City'>";
	echo "<label for='State'> State </label>";
	echo "<input type='text' name='State' id='State'>";
	echo "<label for='Zip'> Zip Code </label>";
        echo "<input type='text' name='Zip' id='Zip'>";
	echo '<br><input type="submit" value="Insert Owner"> <input type="Reset" value="Clear"><br>';
	echo '<input type="hidden" name="which" value="own">';
	echo "</form>";


	if($_SERVER['REQUEST_METHOD']=='POST')
	{
	//Takes each text box that was filled, and makes a query based on what was entered
	 if($_POST['which']=='own')
	{
	 $fname=$_POST['FirstName'];//Creates the variable that will be inserted into FirstName
	 $lname=$_POST['LastName'];//Creates the variable that will be inserted into LastName
	 $address=$_POST['Address'];//Creates the variable that will be inserted into Address
	 $city=$_POST['City'];//Creates the variable that will be inserted into City
	 $state=$_POST['State'];//Creates the variable that will be inserted into State
	 $zip=$_POST['Zip']; //Creates the variable that will be inserted into zip

	 $insertSQL="insert into Owner(FirstName, LastName, Address, City, State, Zip) values (?,?,?,?,?,?)"; //Creates the query
	 }

	 try
	 {
	  $stmt = $dbh->prepare($insertSQL);
	  $ok = $stmt->execute(array($fname, $lname, $address, $city, $state, $zip)); //Executes the query
	  echo 'Owner '.$fname.' '.$lname.' added successfully!';
	 }

	 catch(PDOException $e)
	 {
	  echo 'Cannot add this owner.';
	  echo 'Error:' .$e->getMessage();
	 }
	}



?>

<br/>
<br/>
<br/>

<center>
<a href="assgn11page2.php"> Page 2 </a>
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
        <td> 4/25/18 </td>
</table>

</b>
</body>

</html>
