<?php

$chapternum = intval($_GET['chapternum']);
$filename = str_pad($chapternum, 3, "0", STR_PAD_LEFT) . ".inc";

$retval = file_get_contents("../data/chapters/" . $filename);

header('Content-Type: application/json; charset=utf8');
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT"); // Date in the past
echo json_encode($retval);
