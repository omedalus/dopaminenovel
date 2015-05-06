<?php

$dev = $_GET['dev'];
$dirname = $dev == "true" ? "chapters-dev" : "chapters";


require_once('act_breaks.php');
header('Content-Type: text/html; charset=utf-8');

echo <<<EOL
<!DOCTYPE html>
<html lang="en-us" xmlns="http://www.w3.org/1999/xhtml">
<head>
  <meta http-equiv="content-type" content="text/html;charset=UTF-8">

  <title>Dopamine</title>

  <base href="http://dopaminenovel.com" target="_self" />
  <link rel="stylesheet" type="text/css" href="css/fulltext.css" />

  <!-- Favicon -->
  <link rel="shortcut icon" href="http://dopaminenovel.com/favicons/favicon.ico?v=3" />

</head>
<body>

<div class="blankpage printonly">
  This page intentionally left blank.
</div>

<div class="titlepage">
  <div class="booktitle">
    Dopamine
  </div>
  <div class="authorbyline">
    A novel by
  </div>
  <div class="authorname">
    Mikhail Voloshin
  </div>
</div>

<div class="copyrightpage">
  <div class="booktitle-redux">
    Dopamine
  </div>
  <div class="fictionnotice">
    This is a work of fiction. Names, characters, places, and incidents either are the product of the author’s imagination or are used fictitiously, and any resemblance to actual persons, living or dead, events, or locales is entirely coincidental.
  </div>

  <div class="copyright">
    Copyright 2014 &copy; Mikhail Voloshin<br/>
    All rights reserved.
  </div>
</div>

<div>
EOL;

$chapter_dir = "../data/" . $dirname . "/";
$all_files = scandir($chapter_dir);
$chapter_files = array_values(preg_grep("/\d+\.inc/", $all_files));

echo <<<EOL
<div class="tocpage">
<a id="TOC"><h3>Table of contents</h3></a>

<nav id="toc">
<ol>

EOL;
$tocsection = '';
foreach ($chapter_files as $chapter_file) {
  $chapter_number = intval($chapter_file);

  $chapter_anchor = "chapter_" . $chapter_number;
  if ($chapter_number == 1) {
    $chapter_anchor = "start";
  }

  $newsection = $ACT_BREAKS[$chapter_number];
  if ($newsection) {
    $tocsection = $newsection;
  }

  echo <<<EOL
  <li><a href="/api/full_text.php#$chapter_anchor">$tocsection &mdash; Chapter $chapter_number</a></li>
EOL;
}
echo <<<EOL

</ol>
</nav>
</div>
EOL;

$cursection = '';
foreach ($chapter_files as $chapter_file) {
  $chapter_number = intval($chapter_file);
  $chapter_text = file_get_contents($chapter_dir . $chapter_file);

  $chapter_anchor = "chapter_" . $chapter_number;
  if ($chapter_number == 1) {
    $chapter_anchor = "start";
  }

  $section = $ACT_BREAKS[$chapter_number];
  if ($section) {
    $cursection = $section;
  
    echo <<<EOL
<div class="actbreak">
$section
</div>
EOL;
  }
  
  echo <<<EOL
<div class="chapter">

<div class="chapternumber">
  <a id="$chapter_anchor" >
  $chapter_number
  </a>
</div>

$chapter_text

</div>
EOL;
}

echo <<<EOL
</div>
</body>
</html>
EOL;

