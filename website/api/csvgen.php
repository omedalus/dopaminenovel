<?php

$pbegin = 5;
$pend = 4240;

$numsteps = intval($_GET['n']);
$stepsize = intval(($pend - $pbegin) / $numsteps);

$h = intval($_GET['h']);

echo "link<br/>";
for ($i = $pbegin; $i < $pend; $i += $stepsize) {
  echo "https://mikhailvoloshin.com/ALLSITES/dopaminenovel.com/api/full_text.php?dev=true#p=$i&h=$h";
  echo "<br/>";
}

