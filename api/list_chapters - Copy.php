<?php


$all_files = scandir("../data/chapters");
$chapter_files = array_values(preg_grep("/\d+\.inc/", $all_files));

$retval = $chapter_files;

header('Content-Type: application/json; charset=utf8');
echo json_encode($retval);
