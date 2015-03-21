<?php

	class Search{
		public function main($searchString){
			$counter = 0;
			$fp = fopen('save.csv','r');
			echo "<!DOCTYPE html>\n";
			echo "<html>\n";
			echo "	<head>\n";
			echo '				<meta http-equiv="content-type" content="text/html" charset="Shift-JIS">'."\n";
			echo '				<meta name="author" content="＠FuckUJABEE">'."\n";
			echo '				'."\n";
			echo '				<link rel="stylesheet" text="text/css" href="common.css">'."\n";
			echo '				'."\n";
			echo '				<meta http-equiv="content-language" content="ja">'."\n";
			echo "		<title>\n";
			echo "SearchResult : ".$searchString . "\n";
			echo "		</title>\n";
			echo "	</head>\n";
			echo '	<body>'."\n";

			while($line = fgets($fp)){
				$CutStrings = explode(",", $line);
				
				if(strpos($CutStrings[0], $searchString) !== FALSE){
					echo '<p><a href="' .$CutStrings[0].".html" .'">' .$CutStrings[0] ."</a></p><br>\n";
					$counter++;
				}
			}
			
			echo '<a href="index.php">Back</a>'."\n";
			echo "	</body>\n";
			echo "</html>\n";
		}
	};

	$search = new Search();
	$search->main($_POST['longitude']);
