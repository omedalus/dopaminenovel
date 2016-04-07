<?php

$dev = $_GET['dev'];
$dirname = $dev == "true" ? "chapters-dev" : "chapters";

$mturk = $_GET['mturk'] == 'true';
$mturkscript = $mturk ? '<script src="api/mturk.js"></script>' : '';

$showtitle = !($_GET['showtitle'] == 'false');
$showcopyright = !($_GET['showcopyright'] == 'false');
$showtoc = !($_GET['showtoc'] == 'false');
$includescripts = !($_GET['includescripts'] == 'false');
$internalcss = $_GET['internalcss'] == 'true';

$exportable = $_GET['exportable'] == 'true';
if ($exportable) {
  //$showtitle = false;
  //$showcopyright = false;
  //$showtoc = false;
  $includescripts = false;
  $internalcss = true;
}


require_once('act_breaks.php');
header('Content-Type: text/html; charset=utf-8');

echo <<<EOL
<!DOCTYPE html>
<html lang="en-us" xmlns="http://www.w3.org/1999/xhtml">
<head>
  <title>Dopamine</title>
  <base target="_self" />

  <meta http-equiv="content-type" content="text/html;charset=UTF-8">

  <!-- Favicon -->
  <link rel="shortcut icon" href="../favicons/favicon.ico?v=3" />
EOL;

if ($includescripts) {
  echo <<<EOL
  <script src="../thirdparty/jquery-1.10.2.min.js"></script>
  <script src="../thirdparty/underscore-min.js"></script>

  <script src="../api/script.js"></script>
  $mturkscript
EOL;
}

if ($internalcss) {
  echo <<<EOL
  <style>
EOL;
  require_once('../css/fulltext.css');

  echo <<<EOL
  </style>
EOL;
} else {
  echo <<<EOL
  <link rel="stylesheet" type="text/css" href="../css/fulltext.css" />
EOL;
}

echo <<<EOL
</head>
<body>
EOL;

if ($showtitle) {
  echo <<<EOL
<div class="titlepage" id="titlepage">
  <div class="booktitle">
    <img src="../img/dopamine-title-text-filled.png"
        alt="Dopamine" />
  </div>
  <div>
    <img src="../img/smileyvial-round.png"/>
  </div>
  <div class="authorbyline">
    <img src="../img/ANovelBy.png"
        alt="A Novel By" />
  </div>
  <div class="authorname">
    <img src="../img/MikhailVoloshin.png"
        alt="Mikhail Voloshin" />
  </div>
</div>
EOL;
}


if ($showcopyright) {
  echo <<<EOL
<div class="copyrightpage" id="copyrightpage">
  <div class="booktitle-redux">
    Dopamine
  </div>
  <div class="fictionnotice">
    <i>Dopamine</i> a work of fiction. Names, characters, places, and incidents either are the product of the author’s imagination or are used fictitiously. Any resemblance to actual persons, living or dead, events, or locales is entirely coincidental.
  </div>

  <div class="publisher">
    Published in the United States with Kindle Direct Publishing.
  </div>
  
  <div class="copyright">
    Copyright 2016 &copy; Mikhail Voloshin<br/>
    All rights reserved.
  </div>
</div>
EOL;
}

$chapter_dir = "../data/" . $dirname . "/";
$all_files = scandir($chapter_dir);
$chapter_files = array_values(preg_grep("/\d+\.inc/", $all_files));

if ($showtoc) {
  echo <<<EOL
<div class="tocpage">
<a id="tocitself"><h3>Table of contents</h3></a>

<nav id="toc">
<ol>
  <li><i><a href="#titlepage">Title</a></i></li>
  <li><i><a href="#copyrightpage">Copyright</a></i></li>
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
  <li><a href="#$chapter_anchor">$tocsection &mdash; Chapter $chapter_number</a></li>
EOL;
  }
  echo <<<EOL

</ol>
</nav>
</div>
EOL;
}


echo <<<EOL
<div class="inspirationquotepage">
  <blockquote class="prechapter">
    “The most lively thought is still inferior to the dullest sensation.”
    <div class="attrib">
      &mdash; David Hume (1711-1776)
    </div>
  </blockquote>
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
</body>
</html>
EOL;

