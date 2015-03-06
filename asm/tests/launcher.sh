#!/bin/sh

path_to_test="/nfs/zfs-student-3/users/2013/marene/rendu/rattrapage/corewar/asm/tests"
path_to_ft_asm="/nfs/zfs-student-3/users/2013/marene/rendu/rattrapage/corewar/asm"
path_to_asm="/nfs/zfs-student-3/users/2013/marene/rendu/rattrapage/corewar/asm/champions"
tester=$path_to_test"/test"
ft_asm=$path_to_ft_asm"/asm"
asm=$path_to_asm"/asm"
launcher_log=$path_to_test"/launcher.log"

let "koTest = 0"
let "okTest = 0"
let "success = 0"
let "fail = 0"
let "invalid_dump = 0"
let "discarded = 0"
let "total = 0"

rm -f $launcher_log
rm -f "$path_to_test/"*.s
rm -f "$path_to_test/"*.cor
rm -f "$path_to_test/"*.diff
rm -f "$path_to_asm/"*.txt
rm -f "$path_to_ft_asm/"*.txt
echo "\033[0;32m==Building $tester==\033[0m"	| tee	-a	$launcher_log
make -C $path_to_test							>>			$launcher_log
echo "\n\033[0;32m==Building $ft_asm==\033[0m"	| tee	-a	$launcher_log
make -C $path_to_ft_asm							>>			$launcher_log
if [ -x $tester ]
then
	if [ -x $asm ]
	then
		if [ -x $ft_asm ]
		then
			echo "\033[0;34mproducing testing .s file\033[0m"
			$tester >> $launcher_log
			allKo=`ls "$path_to_test" | grep koTest`
			let "total = `ls $path_to_test | grep koTest | wc -l`"
			for file in $allKo # Starting test with valid syntax source files
			do
				let "koTest = $koTest + 1"
				echo "\033[A\033[2K\033[0;34mkoTest [$koTest / $total]\033[0m"
				$asm "$path_to_test/$file" >> $launcher_log
				cor=`echo $file | cut -d'.' -f1`
				if [ -f "$path_to_test/$cor.cor" ]
				then
					let "discarded = $discarded + 1"
				else
					$ft_asm "$path_to_test/$file" >> $launcher_log
					if [ -f "$path_to_test/$cor.cor" ]
					then
						let "fail = $fail + 1"
					else
						let "success = $success + 1"
					fi
				fi
			done

		echo "\nkoTests: $koTest tests, $discarded discarded, $success success, $fail fails"
		echo ""
		let "success = 0"
		let "fail = 0"
		let "discarded = 0"
		rm -f "$path_to_test/"*.cor
		rm -f "$path_to_asm/"*.txt
		rm -f "$path_to_ft_asm/"*.txt
		rm -f "$path_to_ft_asm/"*.diff
		allOk=`ls "$path_to_test" | grep okTest`
		let "total = `ls $path_to_test | grep okTest | wc -l`"
		for file in $allOk # Starting test with valid syntax source files
		do
			let "okTest = $okTest + 1"
			echo "\033[A\033[2K\033[0;34mokTest [$okTest / $total]\033[0m"
			$asm "$path_to_test/$file" >> $launcher_log
			cor=`echo $file | cut -d'.' -f1`
			if [ -f "$path_to_test/$cor.cor" ]
			then
				hexdump -vC "$cor.cor" > "$path_to_asm/$cor.txt"
				rm -f "$path_to_test/$cor.cor"
				$ft_asm "$path_to_test/$file" >> $launcher_log
				if [ -f "$path_to_test/$cor.cor" ]
				then
				hexdump -vC "$cor.cor" > "$path_to_ft_asm/$cor.txt"
				diff "$path_to_asm/$cor.txt" "$path_to_ft_asm/$cor.txt" > "$path_to_test/$cor.diff"
				if [ -s "$path_to_test/$cor.diff" ]
				then
					let "invalid_dump = $invalid_dump + 1"
				else
					let "success = $success + 1"
				fi
				else
					let "fail = $fail + 1"
				fi
			else
				let "discarded = $discarded + 1"
			fi
		done
		echo "\nokTests: $okTest tests, $discarded discarded, $success success, $fail fails, $invalid_dump invalid dumps"
		else
			echo "$ft_asm is not executable"
		fi
	else
		echo "$asm is not executable"
	fi
else
	echo "$test is not executable"
fi
