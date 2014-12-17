<?php

$chapternum = intval($_GET['chapternum']);
$filename = str_pad($chapternum, 3, "0", STR_PAD_LEFT) . ".inc";

$chapter_text = file_get_contents("../data/chapters/" . $filename);

header('Content-Type: text/html; charset=utf-8');

echo <<<EOL
<!DOCTYPE html>
<html lang="en-us">
<head>

  <meta http-equiv="content-type" content="text/html;charset=UTF-8">

  <title>Dopamine - Chapter $chapternum</title>

</head>
<body>

$chapter_text

</body>
</html>
EOL;

