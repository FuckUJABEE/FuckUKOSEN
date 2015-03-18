<?php

	class register{		
		public function main(){
			$isMakeFile = true;
			$CSVPath = fopen( "save.csv", "a+" );
			$makeFileName = $_POST['name'].'.html';
			if($CSVPath !== false){
				fwrite($CSVPath, $_POST['name']);
				fwrite($CSVPath, ", ");
				fwrite($CSVPath, $_POST['url']);
				fwrite($CSVPath, ", ");
				fwrite($CSVPath, $_POST['register']);
				fwrite($CSVPath, "\n");
				fclose($CSVPath);
			}else{
				$isMakeFile = false;
			}
			
			if(($isMakeFlag = touch($makeFileName)) === TRUE){
				$makeFilePath = fopen($makeFileName, "w");
				if(fwrite($makeFilePath, 
'
<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="content-type" content="text/html" charset="Shift-JIS">
		<meta name="author" content="@FuckUJABEE">
		<meta http-equiv="content-language" content="ja">

		<link rel="stylesheet" text="text/css" href="common.css">

		<title>
			'.$_POST['name'].'
		</title>
	</head>
	<body>
		<h1>
			Name
		</h1>
		<h2>
			'.$_POST['name'].'
		</h2><br>
		<h1>
			Address
		</h1>
		<h2>
			'.$_POST['url'].'
		</h2><br>
		<h1>
			Register
		</h1>
		<h2>
			'.$_POST['register'].'
		</h2><br>
		<span id="back_to_index">
			<a href="index.php" >Back</a>
		</span>
	</body>
</html>'
					) === FALSE){
					echo "writing failuer";
				}
				chmod($makeFileName, 0666);
				
			}else{
				echo "make file failuer\n";
			}

			echo "<!DOCTYPE html>\n";
			echo "<html>\n";
			echo "	<head>\n";
			echo '				<meta http-equiv="content-type" content="text/html" charset="Shift-JIS">'."\n";
			echo '				<meta name="author" content="@FuckUJABEE">'."\n";
			echo '				<meta http-equiv="content-language" content="ja">'."\n";
			echo '				'."\n";
			echo '				<link rel="stylesheet" text="text/css" href="common.css">';
			echo '				'."\n";
			echo '		<title>'."\n";
			if($isMakeFile === true){
				echo "			Success\n";
				
			}else{
				echo "			Failuer\n";
			}

			echo "		</title>\n";
			echo "	</head>\n";
			echo "	<body>\n";
			echo "		<h1>\n";
			
			if($isMakeFile === true){
				echo "			Success\n";
				
			}else{
				echo "			Failuer\n";
			}
			echo "		</h1>\n";
			echo '		<a href="'.$makeFileName.'">'.$makeFileName.'</a>';
			echo "		<br>\n";
			echo '		<span id="back_to_index">'."\n";
			echo '			<a href="index.php">Back</a>'."\n";
			echo "		</span>\n";
			echo "	</body>\n";
			echo "</html>\n";
		}
	};

	$Regist = new register();
	$Regist->main();