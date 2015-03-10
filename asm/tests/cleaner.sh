path_to_test="/nfs/zfs-student-3/users/2013/marene/github/corewar/asm/tests"
path_to_ft_asm="/nfs/zfs-student-3/users/2013/marene/github/corewar/asm"
path_to_asm="/nfs/zfs-student-3/users/2013/marene/github/corewar/asm/champions"
tester=$path_to_test"/test"
ft_asm=$path_to_ft_asm"/asm"
asm=$path_to_asm"/asm"
launcher_log=$path_to_test"/launcher.log"

rm -f $launcher_log
rm -f "$path_to_test/"*.s
rm -f "$path_to_test/"*.cor
rm -f "$path_to_test/"*.diff
rm -f "$path_to_asm/"*.txt
rm -f "$path_to_ft_asm/"*.txt
