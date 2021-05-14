<?php
// Check if $ip passes the giver filter
$ip = "112277....00....00....1";
$ip = htmlspecialchars($ip);
$ip = str_replace("..",".",$ip);
$ip = str_replace("12","",$ip);
$ip = str_replace("7.","",$ip);
$ip = str_replace("0.","",$ip);
if($ip=="127.0.0.1"){
    echo("correct");
    exit();
}