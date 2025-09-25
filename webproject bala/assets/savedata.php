<?php
    error_reporting(E_ALL);
    ini_set('display_errors', 1);

    //getting data from form
    $email=$_POST['email'];
    $password=$_POST['password'];

    //creating/opening a file
    $file=fopen("data.txt","a");

    //writing the details
    fwrite($file, "Email Id: $email, Passsword: $password\n");

    //closing file to ensure that the details are saved
    fclose($file);

    //to announce that the details are saved
    echo "Your Details are saved!";
?>