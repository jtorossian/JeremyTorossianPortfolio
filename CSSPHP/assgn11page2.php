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
        $dbh =  new PDO($dsn, $username, $password);//Connects to the database

	$sql = 'select * from MarinaSlip';//Collects the query
	$sql2 = 'select * from ServiceCategory';

	//Creats the dropdown box
	echo '<form action="assgn11page2.php" method="post">';
	echo '<select name = "boatname">';

	foreach($dbh->query($sql) as $row)//Stores each boatname into the dropdown box
	{
	echo '<option value= ';
	echo $row["SlipID"];
	echo '">';
	echo $row["BoatName"];
	echo '</option>';
	}
	echo '</select>';
	echo '<br>';

	echo '<select name = "category">';
	foreach($dbh->query($sql2) as $row)//Stores each service description
        {
        echo '<option value= ';
        echo $row["CategoryNum"];
        echo '">';
        echo $row["CategoryDescription"];
        echo '</option>';
        }


	//Creates the submit and reset box.
	echo '</select>';
	echo '<br><input type= "submit" name= "submit" value= "Add">';
	echo '<br><input type= "reset" name= "reset" value= "Reset"> <br>';
	echo '</form>';

	//When the user hits the submit button, it will create a new service request for that boat
	if($_SERVER['REQUEST_METHOD']=='POST')
	{
	$boat = $_POST['boatname']; //Assigns the selected boat to $own
	$cat = $_POST['category']; //Assigns the selected service request
	$sqlinsert = "insert into ServiceRequest(SlipID, CategoryNum) values (?,?)";//Creates the query"
	 try
         {
          $stmt = $dbh->prepare($sqlinsert);
          $ok = $stmt->execute(array($boat, $cat)); //Executes the query
          echo 'Service was added successfully!';
         }

         catch(PDOException $e)
         {
          echo 'Cannot add this service.';
          echo 'Error:' .$e->getMessage();
         }
	}

?>
</center>
<br/>
<br/>
<br/>

<!--Creates the directory that connects to each page-->
<center>
<a href="assgn11page1.php"> Page 1 </a>
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
