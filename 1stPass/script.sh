options()
{       echo "Before running this script make sure that you have installed llvm in ~/llvm-project else modify the path accordingly"
        echo "Enter 0 to modify and build"
        echo "Enter 1 to only build"
        echo "Enter 2 to run opt "
        echo "Enter 3 to convert c file to ll"
}
   
case $1 in

  0)
    #  make changes in file then run  
   nano  ~/llvm-project/llvm/lib/Transforms/FirstPass/FirstPass.cpp
   ninja -C ~/llvm-project/build
   ;;

  1)
    ninja -C ~/llvm-project/build

    ;;

  2)
    echo "Running opt"
    read -p "Enter the bc or ll file" test 
    opt -load ../build/lib/LLVMFirstPass.so     -firstpass1  $test.ll  -enable-new-pm=0 -o ou

    ;;
  3)
	echo "If c file is test.c then given input as test "
	read -p "Enter the c file name " test
	clang -S -emit-llvm -O1 $test.c -o $test.ll
    ;;
   --h | --help)
		options 
   ;;
  *) 
    echo "Please give input 0 1 or 2"
esac

