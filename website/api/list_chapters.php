<?php

$all_files = scandir("../data/chapters");
$chapter_files = array_values(preg_grep("/\d+\.inc/", $all_files));

function filename_to_number($filename) {
  return intval($filename);
}

$retval = array_map('filename_to_number', $chapter_files);

header('Content-Type: application/json; charset=utf8');
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT"); // Date in the past
echo json_encode($retval);
