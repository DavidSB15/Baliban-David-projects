<?php

//conn to db
  $conn = mysqli_connect('localhost', 'XMG', 'MicrosoftSQL', 'project');

  //check con
  if(!$conn)
  {
    echo 'Connection error: ' . mysqli_connect_error();
  }

  $sql = 'SELECT * FROM for_sale ORDER BY ID';

  $result = mysqli_query($conn, $sql);

  $angajati = mysqli_fetch_all($result, MYSQLI_ASSOC);

  mysqli_free_result($result);

  mysqli_close($conn);

  //print_r($angajati);

?>

<!DOCTYPE html>
<html>
<head><link rel="stylesheet" href="design.css">
  <style>
  .square{
	position:absolute;
  color: darkgreen;
	top:0%;
  left:0%;
	height: 100%;
	width:100%;
	background-color: lightgrey;
	border: 6px double;
	border-color:#282135;
	z-index: 1;
}
a:link, a:visited {
  background-color: #f44356;
  color: #F9E4D4;
  font-family: Garamond;
  padding: 15px 50%;
  max-width: 6px;
  left:0%;
  text-align: center;
  text-decoration: none;
  display: inline-block;
}

a:hover, a:active {
  background-color: #f44336;
}
table#demotable {
  table-layout: fixed ;
  width: 100% ;
  border-collapse: collapse ;
  border: 1px black solid ;
}
table#demotable td {
  width: 50% ;
  border: 1px black solid ;
  padding: 10px ;
}
table#demotable caption {
  font-style: italic ;
}
</style>
</head>

<div class="square">
  <center>
  <h1 class="center gray-text">!! De vanzare !!: </h1><br></center>
  <h1 style="font-family:Georgia">
  <table id="demotable">
  <tr>
    <td>ID</td>
    <td>Tip</td>
    <td>Marca</td>
    <td>Pret</td>
    <td>An</td>
    <td>Suprafata</td>
  </tr></h1>
  </table>
      <?php foreach($angajati as $angajat) {?>

            <h2 style="font-family:Georgia">
            <table id="demotable">
              <tr><td><?php echo htmlspecialchars($angajat['ID']); echo str_repeat('&nbsp;', 2); ?></td>
              <td><?php echo htmlspecialchars($angajat['Tip']); echo str_repeat('&nbsp;', 2);?></td>
              <td><?php echo htmlspecialchars($angajat['Marca']); echo str_repeat('&nbsp;', 2);?></td>
              <td><?php echo htmlspecialchars($angajat['Pret']); echo str_repeat('&nbsp;', 2);?></td>
              <td><?php echo htmlspecialchars($angajat['An']); echo str_repeat('&nbsp;', 2);?></td>
              <td><?php echo htmlspecialchars($angajat['Suprafata']); echo str_repeat('&nbsp;', 2);?></td></tr></h2>
            </table>
      <?php } ?>
<a href="https://www.olx.ro/oferte/user/1PM4z/">Pagina anunturilor detaliate pe OLX</a>
</div>

</html>
