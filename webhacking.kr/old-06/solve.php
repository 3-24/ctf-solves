<?php
$val_id="admin";
$val_pw="nimda";
  for($i=0;$i<20;$i++){
    $val_id=base64_encode($val_id);
    $val_pw=base64_encode($val_pw);
  }
$val_id=str_replace("1","!",$val_id);
$val_id=str_replace("2","@",$val_id);
$val_id=str_replace("3","$",$val_id);
$val_id=str_replace("4","^",$val_id);
$val_id=str_replace("5","&",$val_id);
$val_id=str_replace("6","*",$val_id);
$val_id=str_replace("7","(",$val_id);
$val_id=str_replace("8",")",$val_id);

$val_pw=str_replace("1","!",$val_pw);
$val_pw=str_replace("2","@",$val_pw);
$val_pw=str_replace("3","$",$val_pw);
$val_pw=str_replace("4","^",$val_pw);
$val_pw=str_replace("5","&",$val_pw);
$val_pw=str_replace("6","*",$val_pw);
$val_pw=str_replace("7","(",$val_pw);
$val_pw=str_replace("8",")",$val_pw);

echo($val_id);
echo("\n");
echo($val_pw);
