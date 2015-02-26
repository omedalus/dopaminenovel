<?php

$chapternum = intval($_GET['chapternum']);
$dev = $_GET['dev'];
$filename = str_pad($chapternum, 3, "0", STR_PAD_LEFT) . ".inc";

$dir = $dev == "true" ? "chapters-dev" : "chapters";

$retval = file_get_contents("../data/" . $dir . "/" . $filename);

header('Content-Type: application/json; charset=utf8');
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT"); // Date in the past
echo json_encode($retval);
