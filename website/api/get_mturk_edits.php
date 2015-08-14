<?php

// TODO: Make this parse batch_results.csv
// Skip the first line, then break on commas
// 28 fields we're interested in.
// fields[26] is the URL, which has the position number
// fields[27] is the feedback 

$retval = array();

$batchfilestr = file_get_contents('batch_results.csv');

$batchsplit = array();
if (preg_match_all("/\n\"[A-Z0-9]{30}\"/", $batchfilestr, $batchsplit, PREG_OFFSET_CAPTURE)) {
  $batchsplit = $batchsplit[0];
}

$lastoffset = false;
$linedata = array();

for ($isplit = 0; $isplit <= sizeof($batchsplit); $isplit++) {
  if ($isplit < sizeof($batchsplit)) {
    $curoffset = $batchsplit[$isplit][1];
  } else {
    $curoffset = strlen($batchfilestr);
  }

  if ($lastoffset) {
    $line = substr($batchfilestr, $lastoffset, $curoffset - $lastoffset);
    
    $linesplit = array();
    if (preg_match_all("/#p=(\d+)&h=\d+\",\"(.*)\"/s", $line, $linesplit)) {
      $pnum = intval($linesplit[1][0]);
      $suggestiontxt = $linesplit[2][0];

      $suggestiongroup = array(
        "p" => $pnum,
        "suggestion" => $suggestiontxt
      );
        
      array_push($retval, $suggestiongroup);
    }
  }
  
  $lastoffset = $curoffset;
}



header('Content-Type: application/json; charset=utf8');
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT"); // Date in the past
echo json_encode($retval);
