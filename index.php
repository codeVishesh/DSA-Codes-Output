<?php include "inc/header.php"; ?>


<?php
spl_autoload_register(function($className){
  include 'classes/'.$className.'.php';
});
?>

<?php $user = new Student(); ?>



<section class="mainleft">

  <?php
  //for inserting...
  if(isset($_POST['submit'])){
    $name = $_POST['name'];
    $dept = $_POST['dept'];
    $age  = $_POST['age'];

    $user->setName($name);
    $user->setDept($dept);
    $user->setAge($age);

    if($user->insert()){
      echo "<span class='insert'>Data Inserted Successfully...</span>";
    }

  }
  ?>

  <?php
  // for data update
  if(isset($_POST['update'])){
    $name = $_POST['name'];
    $dept = $_POST['dept'];
    $age  = $_POST['age'];
    $id  = $_POST['id'];

    $user->setName($name);
    $user->setDept($dept);
    $user->setAge($age);

    if($user->update($id)){
      echo "<span class='insert'>Data Updated Successfully...</span>";
    }

  }

  ?>

  <?php
  //for data edit
  if(isset($_GET['action']) && $_GET['action']=='update') {
    $id = (int)$_GET['id'];
    $result = $user->readById($id);
    ?>

    <form action="" method="post">
      <table>
        <input type="hidden" name="id" value="<?php echo $result['id']; ?>" />
        <tr>
          <td>Name: </td>
          <td><input type="text" name="name" value="<?php echo $result['name']; ?>" required="1"/></td>
        </tr>

        <tr>
          <td>Department: </td>
          <td><input type="text" name="dept"  value="<?php echo $result['department']; ?>" required="1"/></td>
        </tr>

        <tr>
          <td>Age: </td>
          <td><input type="text" name="age"  value="<?php echo $result['age']; ?>" required="1"/></td>
        </tr>
        <tr>
          <td></td>
          <td>
            <input type="submit" name="update" value="Update"/>
            <input type="reset" value="Clear"/>
          </td>
        </tr>
      </table>
    </form>
  </section>
  <?php


} else{
  ?>

  <form action="" method="post">
    <table>
      <tr>
        <td>Name: </td>
        <td><input type="text" name="name" required="1"/></td>
      </tr>

      <tr>
        <td>Department: </td>
        <td><input type="text" name="dept" required="1"/></td>
      </tr>

      <tr>
        <td>Age: </td>
        <td><input type="text" name="age" required="1"/></td>
      </tr>
      <tr>
        <td></td>
        <td>
          <input type="submit" name="submit" value="Submit"/>
          <input type="reset" value="Clear"/>
        </td>
      </tr>
    </table>
  </form>
</section>

<?php
}

?>

<section class="mainright">
  <?php
  // for delete data
  if(isset($_GET['action']) && $_GET['action'] == 'delete'){
    $id = (int)$_GET['id'];

    if($user->delete($id)){
      echo "<span class='delete'> Data deleted succesfully...</span>";
    }
  }

  ?>
  <table class="tblone">
    <tr>
      <th>No</th>
      <th>Name</th>
      <th>Department</th>
      <th>Age</th>
      <th>Action</th>
    </tr>

    <?php
    $i= 0;
    if(is_array($user->readAll()) || is_object($user->readAll())){
      foreach($user->readAll() as $value){
        $i++;
        ?>
        <tr>
          <td><?php echo $i; ?></td>
          <td><?php echo $value['name'];  ?></td>
          <td><?php echo $value['department'];  ?></td>
          <td><?php echo $value['age'];  ?></td>
          <td>
            <a href="index.php?action=update&id=<?php echo $value['id']; ?>">Edit</a> ||
            <a href="index.php?action=delete&id=<?php echo $value['id']; ?>">Delete</a>
          </td>
        </tr>
        <?php
      }
    } else {
      echo "There no RECORD found in the Table !!!";
    }
    ?>

  </table>
</section>










<?php include "inc/footer.php"; ?>
